#include "Queue.h"

/****************
 * CONSTRUCTORS *
 ****************/

Queue::Queue() : head(NULL), tail(NULL), num_nodes(0) {}

Queue::~Queue() {
   Node* curr = head;
   Node* prev;

   while(curr != nullptr) {
      prev = curr;
      curr = curr->next;
      delete prev;
   }
}

/*********************
 * GETTERS & SETTERS *
 *********************/

int Queue::size() const { return this->num_nodes; }

/*********
 * OTHER *
 *********/

/**
 * @brief Returns true if the `Queue` is empty
 *
 * @return true if empty,
 * @return false otherwise
 */
bool Queue::empty() const { return this->num_nodes == 0; }

/**
 * @brief Peek first element in `Queue`
 *
 * @return data from the first location if it exists,
 * @return nullptr otherwise
 */
Order* Queue::peekFirst() const {
    if (this->head == nullptr) return nullptr;
    else return this->head->data;
}

/**
 * @brief Delete the first node in `Queue`
 *
 * @return Order* data from the first location if it exists,
 * @return nullptr otherwise
 */
Order* Queue::popFirst() {
   // Queue is empty
   if (this->empty()) return nullptr;
   else {
      Node* target_node = this->head;
      Order* return_data = this->head->data;
      this->head = this->head->next;
      num_nodes--;

      // Queue is now empty, update tail pointer
      if (this->head == nullptr) this->tail = nullptr;

      // delete node and return data
      delete target_node;
      return return_data;
   }
}

/**
 * @brief Add `order` to the back of the `Queue`
 *
 * @param order order to add
 */
void Queue::addLast(Order* order) {
   Node* node = new Node(order);

   // if Queue is empty set the head and tail to the new node
   if (this->empty()) {
      this->head = node;
      this->tail = node;
   // otherwise add to end of queue
   } else {
      this->tail->next = node;
      this->tail = node;
   } num_nodes++;
}