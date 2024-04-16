#ifndef Pins_h
#define Pins_h

#include <stdint.h> 
#include <avr/io.h>

/**
 * @brief A typedef for a pointer to a volatile uint8_t, used for port registers.
 */
typedef volatile uint8_t* port_PTR;

/**
 * @class DigitalPin
 * @brief A class for managing digital pins, all the pins are set as INPUT by default.

 */
class DigitalPin {
public:
    DigitalPin();   
    /**
     * @brief Set the state (HIGH or LOW) of a specific pin.
     *
     * @param pin The pin number (0-13) to set the STATE for.
     * @param bitValue true for HIGH, false for LOW.
     */
    void setPinState(uint8_t pin, bool bitValue);
    /**
     * @brief Set the Pin Mode to OUTPUT or INPUT
     * 
     * @param pin The pin number (0-13) to set the MODE for.
     * @param bitValue true for OUTPUT, false for INPUT.
     */
    void setPinMode(uint8_t pin, bool bitValue);
    /**
     * @brief Get the value of a pin (HIGH or LOW)
     *
     * @param pin The pin number (0-13) to get the STATE for.
     * @param bitValue true for HIGH, false for LOW.
     */
    bool getPinState(uint8_t pin);

private:
    /**
     * @brief Set the state (HIGH or LOW) of a specific bit in a port register.
     *
     * @param bitValue true for HIGH, false for LOW.
     * @param bitNumber The bit number to set (0-7).
     * @param _PORT_ The pointer to the port register.
     */
    void setPinPort(bool bitValue, uint8_t bitNumber, port_PTR _PORT_);
    /**
     * @brief Get the correct bit number for a specific pin number.
     *
     * @param pin The pin number (0-13).
     * @return The corresponding bit number for the given pin.
     */
    uint8_t correctBit(uint8_t pin);
    
};

#endif
