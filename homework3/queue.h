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

public:

  ~Queue() {
    while (head != nullptr) {
      dequeue();
    }
  }

  Queue() = default;

  Queue(const Queue& s) = delete;
  Queue& operator=(const Queue& s) = delete;

  Queue(Queue&& s): size(s.size), head(s.head), tail(s.tail) {
    s.head = nullptr;
    s.tail = nullptr;
    s.size = 0;
  }

  Queue& operator=(Queue&& s) {
    if (&s != this) {
      size = s.size;
      head = s.head;
      s.head = nullptr;
      s.size = 0;
    }
    return *this;
  }

  int get_size() {
    return size;
  }

  void enqueue(T x) {
    Node* n = new Node {x, nullptr};
    tail->next = n;
    tail = n;
    size++;
  }

  T dequeue() {
    Node* nodeToDelete = head;
    T valueToReturn = head->data;
    head = head->next;
    size--;
    delete nodeToDelete;
    return valueToReturn;
  }
};

Queue<int> oneTwoThree() {
  Queue<int> z;
  z.enqueue(1);
  z.enqueue(2);
  z.enqueue(3);
  return z;
}
