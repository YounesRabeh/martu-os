#include "Communication.h"


Communication::Communication() {
  initCommunication();
}

void Communication::initCommunication() {
    // Set baud rate to 9600 (for example)
    UBRR0H = 0;
    UBRR0L = 103;
    // Enable transmitter and receiver
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    // Set data frame format: 8 data bits, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
}

void Communication::print(const char *str) {
  while (char c = pgm_read_byte(str++)) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
  }
}

void Communication::print(uint16_t num) {
  char buffer[6]; // Buffer to hold the string representation of the number
  itoa(num, buffer, 10); // Convert the short to a string
  for (int i = 0; buffer[i] != '\0'; i++) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = buffer[i]; 
  }
}

void Communication::print(uint32_t num) {
  char buffer[11]; // Buffer to hold the string representation of the number
  ultoa(num, buffer, 10); // Convert the unsigned long to a string
  for (int i = 0; buffer[i] != '\0'; i++) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = buffer[i];
  }
}


void Communication::print(volatile char buffer[], uint8_t maxLength) {
  for (uint8_t i = 0; i < maxLength && buffer[i] != '\0'; i++) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = buffer[i];
  }
}

void Communication::printChar(char character){
  while (!(UCSR0A & (1 << UDRE0)));
  UDR0 = character;
}

void Communication::printBool(bool value) {
    if (value == true) {
      printChar('1');
    } else {
      printChar('2');
    }
}

void Communication::receiveSerial(char* buffer) {
  uint8_t index = 0;

  while (index < sizeof(buffer) - 1) {
    while (!(UCSR0A & (1 << RXC0))) {
      // Wait for data to be available
    }
    char receivedChar = UDR0;
    if (receivedChar == '\n') {
      break; // End of string reached
    }
    buffer[index] = receivedChar;
    index++;
  }
  buffer[index] = '\0';  // Null-terminate string
}


void Communication::addToBuffer(volatile char buffer[], uint8_t maxLength) {
  uint8_t index = 0;
  char receivedChar;

  while (index < maxLength - 1) {
    if (UCSR0A & (1 << RXC0)) {
      receivedChar = UDR0;
      if (receivedChar == '\r' || receivedChar == '\n') {
        break; // Stop if a newline or carriage return is received
      } else if (receivedChar == ' '){continue;} //skip empty spaces
      buffer[index] = receivedChar;
      index++;
    }
  }

  buffer[index] = '\0'; // Null-terminate the buffer
}

bool Communication::isAvailable() {
  return (UCSR0A & (1 << RXC0)) != 0;
}