#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class Queue {

  struct Node {
    T data;
    Node* next;
  };

  int size = 0;
  Node* head = nullptr;
  Node* tail = nullptr;

  Node* copy(Node* n) {
    return new Node {n->data, n->next ? copy(n->next) : nullptr};
  }
  //friend ostream& operator<<(ostream &output, Queue<T> &rhs);

public:

  ~Queue() {
    while (head != nullptr) {
      dequeue();
    }
  }

  Queue() = default;

  Queue(const Queue& q) = delete;
  Queue& operator=(const Queue& q) = delete;

  Queue(Queue&& q): size(q.size), head(q.head), tail(q.tail) {
    q.head = nullptr;
    q.tail = nullptr;
    q.size = 0;
  }

  Queue& operator=(Queue&& q) {
    if (&q != this) {
      size = q.size;
      head = q.head;
      tail = q.tail;
      q.head = nullptr;
      q.tail = nullptr;
      q.size = 0;
    }
    return *this;
  }

  int get_size() {
    return size;
  }

  void enqueue(T x) {
    Node* n = new Node {x, nullptr};
    if (size) {
      tail->next = n;
      tail = tail->next;
      ++size;
    } else {
      head = n;
      tail = head;
      ++size;
    }
  }

  T dequeue() {
    if (size) {
      Node* nodeToDelete = head;
      T valueToReturn = head->data;
      head = head->next;
      size--;
      delete nodeToDelete;
      return valueToReturn;
    } else {
      throw underflow_error("The queue is empty.");
    }
  }

  friend ostream& operator<<(ostream &output, Queue<T> &rhs) {
    Node* nodePtr = rhs.head;

    while (nodePtr != nullptr)
    {
      output << nodePtr->data << endl;
      nodePtr = nodePtr->next;
    }
    return output;
  }
};

Queue<int> oneTwoThree() {
  Queue<int> z;
  z.enqueue(1);
  z.enqueue(2);
  z.enqueue(3);
  return z;
}
