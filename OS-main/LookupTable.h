#ifndef LOOKUP_TABLE_H
#define LOOKUP_TABLE_H

#include <stdint.h>

typedef void (*Function_PTR)();

class LookupTable {
public:
    LookupTable();
    ~LookupTable();

    // Add a key-value pair to the table
    void addEntry(uint32_t key, Function_PTR value);
    // Remove the first entry from the table
    void removeEntry();
    // Sort the table based on keys
    void sortTable();
    // check if the table is empty
    bool isEmpty() const;
    //get the value
    Function_PTR getValue() const;
    // Get the first key in the table
    uint32_t getKey() const;

private:
    struct TableEntry {
        uint32_t key;
        Function_PTR value;
    };

    // Define a maximum size for the table (adjust as needed)
    static const uint32_t MaxSize = 50;

    // Use PROGMEM for the fixed-size array
    TableEntry table[MaxSize];

    uint32_t size;

    void resize(uint32_t newSize);
};

#endif // LOOKUP_TABLE_H
