#include <iostream>
#include <memory>

class Node {
public:
    int data;
    std::shared_ptr<Node> next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    std::shared_ptr<Node> head;

    LinkedList() : head(nullptr) {}

    void append(int value) {
        if (!head) {
            head = std::make_shared<Node>(value);
        } else {
            auto current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = std::make_shared<Node>(value);
        }
    }

    void print() const {
        auto current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.print(); // Output: 1 2 3

    return 0;
}