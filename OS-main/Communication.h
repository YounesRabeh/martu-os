#ifndef Communication_h
#define Communication_h

#include <avr/pgmspace.h> //REGISTER NAMES<io.h> + COPY-fn() 
#include <stdlib.h> // itoa
#include <stdint.h> //uintX_t

/**
 * @class Communication
 * @brief A class for handling communication tasks.
 *
 * This class provides communication-related functionality.
 */
class Communication {
public:
    /**
     * @brief Initializes a new Communication instance.
     * This constructor initializes the communication settings.
     */
    Communication();

    /**
     * @brief Prints a null-terminated string to the communication channel.
     * @param str A pointer to a null-terminated string to be printed.
     */
    void print(const char *str);
    /**
     * @brief Prints an unsigned 16-bit integer to the communication channel.
     * @param num The number to be printed.
     */
    void print(uint16_t num);
    /**
     * @brief Prints an unsigned 32-bit integer to the communication channel.
     * @param num The number to be printed.
     */
    void print(uint32_t num);
    /**
     * @brief Prints the contents of a volatile character buffer to the communication channel.
     * @param buffer A pointer to a volatile character array.
     * @param maxLength The maximum number of characters to print.
     */
    void print(volatile char buffer[], uint8_t maxLength);
    /**
     * @brief Prints a character to the communication channel.
     * @param character The character to be printed.
     */
    void printChar(char character);
    /**
     * @brief Receives characters from the communication channel into a buffer.
     * @param buffer A pointer to a character array for storing received characters.
     * @param maxLength The maximum number of characters to receive.
     */
    void receiveSerial(char* buffer);
    /**
     * @brief Appends received characters to a buffer.
     * NOTE: the buffer gets cleared at every call 
     * @param buffer A pointer to a volatile character array for appending characters.
     * @param maxLength The maximum number of characters to append.
     */
    void addToBuffer(volatile char buffer[], uint8_t maxLength);
    /**
     * @brief Checks if the communication channel is available.
     * @return true if communication channel is available, false otherwise.
     */
    bool isAvailable();

    void printBool(bool value);

private:    
    /**
     * @brief Initialize the communication settings.
     *
     * This private method initializes the communication settings or performs
     * any necessary setup for the communication channel.
     */
    void initCommunication();
};

#endif
