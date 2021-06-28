#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val{};
    Node *prev{nullptr};
    Node *next{nullptr};
    Node *child{nullptr};
};

void print(Node *start)
{
    cout << boolalpha << endl;
    auto *step = start;
    while (step->next != nullptr) {
        cout << step->val << " -> ";
        step = step->next;
    }
    cout << step->val << endl;
}
//Node *flatten(Node *head) // Ordered
//{
//    if (head->next == nullptr && head->child == nullptr) return head;
//    queue<Node *> cQ;
//    auto *step = head;
//    while (step->next != nullptr || !cQ.empty()) {
//        if (step->child != nullptr) {
//            cQ.push(step->child);
//            step->child = nullptr;
//        }
//        if (step->next == nullptr && !cQ.empty()) {
//            step->next = cQ.front();
//            step->next->prev = step;
//            cQ.pop();
//        }
//
//        step = step->next;
//    }
//    return head;
//};

Node *inOrderFunc(Node *start)
{
    if (start->child) {
        auto *next = start->next;
        start->next = start->child;
        start->next->prev = start;
        start->child = nullptr;
        auto *result = inOrderFunc(start->next);
        result->next = next;
        if (next) {
            next->prev = result;
            start = next;
        }
    }
    if (start->next) {
        return inOrderFunc(start->next);
    }

    return start;
}

Node *flatten(Node *head) // unOrdered DFS
{
    inOrderFunc(head);
    return head;
};

int main()
{

    auto *node1 = new Node;
    node1->val = 1;
    auto *node2 = new Node;
    node2->val = 2;
    auto *node3 = new Node;
    node3->val = 3;
    auto *node4 = new Node;
    node4->val = 4;
    auto *node5 = new Node;
    node5->val = 5;
    auto *node6 = new Node;
    node6->val = 6;
    auto *node7 = new Node;
    node7->val = 7;
    auto *node8 = new Node;
    node8->val = 8;
    auto *node9 = new Node;
    node9->val = 9;
    auto *node10 = new Node;
    node10->val = 10;
    auto *node11 = new Node;
    node11->val = 11;
    auto *node12 = new Node;
    node12->val = 12;

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->prev = node5;

    node3->child = node7;
    node7->next = node8;
    node8->prev = node7;
    node8->next = node9;
    node9->prev = node8;
    node9->next = node10;

    node8->child = node11;
    node11->next = node12;
    node12->prev = node11;

//    auto *node1 = new Node;
//    node1->val = 1;
//    auto *node2 = new Node;
//    node2->val = 2;
//    auto *node3 = new Node;
//    node3->val = 3;
//    node1->child = node2;
//    node2->child = node3;
    auto *result = flatten(node1);
    print(result);
    return 0;
}
