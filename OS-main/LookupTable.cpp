#include "LookupTable.h"

LookupTable::LookupTable() : size(0) {}

LookupTable::~LookupTable() {}

void LookupTable::addEntry(uint32_t key, Function_PTR value) {
    if (size < MaxSize) {
        table[size].key = key;
        table[size].value = value;
        size++;
        this->sortTable();
    }
}

void LookupTable::removeEntry() {
    if (size > 0) {
        for (uint32_t i = 0; i < size - 1; ++i) {
            table[i] = table[i + 1];
        }
        size--;
    }
}


void LookupTable::sortTable() {
    // Bubble sort for simplicity (you can replace it with a more efficient sorting algorithm)
    for (uint32_t i = 0; i < size - 1; ++i) {
        for (uint32_t j = 0; j < size - i - 1; ++j) {
            if (table[j].key > table[j + 1].key) {
                // Swap elements without using std::swap
                TableEntry temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
}


void LookupTable::resize(uint32_t newSize) {
    // No need to dynamically allocate memory; use a fixed-size array
    if (newSize <= MaxSize) {
        size = newSize;
    }
}

bool LookupTable::isEmpty() const {
    return size == 0;
}

Function_PTR LookupTable::getValue() const {
    if (size > 0) {
        return table[0].value;
    } else {
        // Return a default value or handle the case when the table is empty
        return nullptr; // You can modify this based on your needs
    }
}

uint32_t LookupTable::getKey() const {
    if (size > 0) {
        return table[0].key;
    } else {
        // Return a default value or handle the case when the table is empty
        return 0; // You can modify this based on your needs
    }
}
