#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>

class Node;

typedef std::shared_ptr<Node> NodePtr;

struct Node
{
    int val;
    NodePtr next;

    Node(int i =0):
        val(i)
    {}

    ~Node()
    {
        std::cout << "~Node " << val << "\n";
    }
};

void printList(const NodePtr& list)
{
    NodePtr p = list;
    do {
        std::cout << p->val << ",";
        p = p->next;
    }
    while (p);

    std::cout << "\n";
}

int main()
{
    NodePtr list = std::make_shared<Node>(1);
    list->next = std::make_shared<Node>(2);
    list->next->next = std::make_shared<Node>(3);
    list->next->next = std::make_shared<Node>(4);
    //list->next->next->next = list; // circular reference, causes leak

    printList(list);

    return 0;
}

