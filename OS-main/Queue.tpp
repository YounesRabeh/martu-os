template <typename EVENT>
Queue<EVENT>::Queue() {
    front = rear = nullptr;
}

template <typename EVENT>
Queue<EVENT>::~Queue() {
    clear();
}

/*
template <typename EVENT>
void Queue<EVENT>::enqueue(EVENT val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else if (val < front->data) {
        // If the new element is smaller than the front, it becomes the new front.
        newNode->next = front;
        front = newNode;
    } else {
        Node* current = front;
        Node* previous = nullptr;

        while (current != nullptr && current->data < val) {
            previous = current;
            current = current->next;
        }

        // Insert the new element after 'previous' and before 'current'.
        previous->next = newNode;
        newNode->next = current;

        if (current == nullptr) {
            // If 'current' is nullptr, the new element becomes the new rear.
            rear = newNode;
        }
    }
}*/

template <typename EVENT>
void Queue<EVENT>::enqueue(EVENT val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}


template <typename EVENT>
void Queue<EVENT>::dequeue() {
    if (isEmpty()) {
        return;
    }

    Node* temp = front;
    front = front->next;
    delete temp;
}

template <typename EVENT>
EVENT Queue<EVENT>::peek() {
    if (isEmpty()) {
        return EVENT();
    }
    return front->data;
}

template <typename EVENT>
bool Queue<EVENT>::isEmpty() {
    return front == nullptr;
}

template <typename EVENT>
void Queue<EVENT>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename EVENT>
uint16_t Queue<EVENT>::currentSize() const {
    uint16_t count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}


template <typename EVENT>
void Queue<EVENT>::sort() {
    uint16_t size = currentSize();
    if (size <= 1) {
        // No need to sort if there are 0 or 1 elements.
        return;
    }

    Node* current = front;
    Node* nextNode = current->next;

    for (uint16_t i = 0; i < size - 1; i++) {
        for (uint16_t j = 0; j < size - i - 1; j++) {
            if (current->data > nextNode->data) {
                // Swap the data of the two nodes.
                uint32_t temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            // Move to the next node.
            current = nextNode;
            nextNode = nextNode->next;
        }
        // Reset current and nextNode for the next pass.
        current = front;
        nextNode = current->next;
    }
}
