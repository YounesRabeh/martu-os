#ifndef Queue_h
#define Queue_h


#include <stdint.h>
/**
 * @brief A template class for a simple linked list-based queue.
 *
 * This class provides basic queue operations, including enqueue, dequeue, peek,
 * isEmpty, and clear. It is a templated class, allowing you to store elements
 * of any data type in the queue.
 *
 * @tparam EVENT The type of data elements to store in the queue.
 */
template <typename EVENT>
class Queue {
public:
    /**
     * @brief Constructor for the Queue class.
     */
    Queue();

    /**
     * @brief Destructor for the Queue class.
     */
    ~Queue();

    /**
     * @brief Enqueues a new element into the queue.
     *
     * @param val The value to be enqueued.
     */
    void enqueue(EVENT val);

    /**
     * @brief Dequeues and removes the front element from the queue.
     */
    void dequeue();

    /**
     * @brief Retrieves the value of the front element without dequeuing it.
     *
     * @return The value of the front element.
     */
    EVENT peek();

    /**
     * @brief Checks if the queue is empty.
     *
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty();

    /**
     * @brief Clears the queue by removing all elements.
     */
    void clear();

    /**
     * @brief Returns the number of elements in the queue.
     *
     * @return The number of elements in the queue.
     */
    uint16_t currentSize() const;

    /**
     * @brief Sort the queue.
     */
    void sort();

private:
    struct Node {
        EVENT data;
        Node* next;
    };
    Node* front;
    Node* rear;
};

#include "Queue.tpp"  // Include the template implementation

#endif

