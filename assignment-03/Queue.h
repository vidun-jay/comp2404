#ifndef QUEUE_H
#define QUEUE_H

#include "Order.h"

class Queue {

    // nested node class
    class Node {
        public:
            // Node();
            Node(Order* order) : data(order), next(nullptr) {};
            Order* data;
            Node* next;
    };

    /* Member Functions */
    public:
        /* Constructors */
        Queue();
        ~Queue();

        /* Getters & Setters */
        int size() const;

        /* Other */
        bool empty() const;
        Order* peekFirst() const;
        Order* popFirst();
        void addLast(Order* order);

    /* Member Variables */
    private:
        Node* head;
        Node* tail; // point to last element in Queue
        int num_nodes;
};

#endif // QUEUE_H