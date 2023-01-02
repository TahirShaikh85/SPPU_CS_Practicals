
#include <iostream>
#include <list>

template <typename T>
class PriorityQueue {
 public:
  // Constructor
  PriorityQueue() {}

  // Insert an element into the queue with a given priority
  void push(T element, int priority) {
    // Create a new node with the given element and priority
    Node node(element, priority);

    // Insert the node into the list in the correct position
    // based on its priority
   
    for (auto it = data_.begin(); it != data_.end(); it++) {
      if (node <= *it) {
        data_.insert(it, node);
        return;
      }
    }
    // If the element has the highest priority, add it to the end of the list
    data_.push_back(node);
  }

  // Remove and return the element with the highest priority
  T pop() {
    T element = data_.front().element;
    data_.pop_front();
    return element;
  }

  // Return the element with the highest priority
  T top() const {
    return data_.front().element;
  }

  // Return true if the queue is empty, false otherwise
  bool empty() const {
    return data_.empty();
  }

 private:
  // Node class to store the element and its priority
  class Node {
   public:
    Node(T element, int priority) : element(element), priority(priority) {}

    // Overload the <= operator to compare the priorities of two nodes
    bool operator<=(const Node& other) const {
      return priority <= other.priority;
    }

    T element;
    int priority;
  };

  // Inorder list to store the nodes
  std::list<Node> data_;
};

int main() {
  PriorityQueue<int> pq;

  pq.push(10, 1);
  pq.push(20, 2);
  pq.push(30, 3);
  pq.push(40, 4);

  std::cout << "Top element: " << pq.top() << std::endl;  // Output: 40

  pq.pop();

  std::cout << "Top element after pop: " << pq.top() << std::endl;  // Output: 30

  pq.push(50, 5);

  std::cout << "Top element after push: " << pq.top() << std::endl;  // Output: 50

  return 0;
}

