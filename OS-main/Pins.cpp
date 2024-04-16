#include "Pins.h"

DigitalPin::DigitalPin() {
    
}

void DigitalPin::setPinState(uint8_t pin, bool bitValue) {
  port_PTR port_REGISTER; // Use volatile uint8_t* to match the PORT types
  if (pin > 7) {
    port_REGISTER = &PORTB;
  } else {
    port_REGISTER = &PORTD;
  }
  setPinPort(bitValue, correctBit(pin), port_REGISTER);   
}

void DigitalPin::setPinMode(uint8_t pin, bool bitValue) {
  port_PTR port_REGISTER; // Use volatile uint8_t* to match the PORT types
  if (pin > 7) {
    port_REGISTER = &DDRB;
  } else {
    port_REGISTER = &DDRD;
  }
  setPinPort(bitValue, correctBit(pin), port_REGISTER); 
}

void DigitalPin::setPinPort(bool bitValue, uint8_t bitNumber, port_PTR port_) {
  if (bitValue) {
    *port_ |= (1 << bitNumber);  // Set the bit HIGH
  } else {
    *port_ &= ~(1 << bitNumber); // Set the bit LOW
  }
}

uint8_t DigitalPin::correctBit(uint8_t pin) {
  switch (pin) {
    case 13: return 5;
    case 12: return 4;
    case 11: return 3;
    case 10: return 2;
    case 9:  return 1;
    case 8:  return 0;
    default: return  pin;
  }
}


bool DigitalPin::getPinState(uint8_t pin){
  if (pin > 7) {
    return (PIND & (1 << correctBit(pin))) != 0;
  } else {
    return (PINB & (1 << correctBit(pin))) != 0;
  }
}

