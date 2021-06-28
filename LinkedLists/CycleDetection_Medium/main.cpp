#include <iostream>
#include <set>
using namespace std;

/*
    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
    There is a cycle in a linked list if there is some node in the list that can be reached again
    by continuously following the next pointer. Internally, pos is used to denote the index of the
    node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
    Notice that you should not modify the linked list.
*/

struct ListNode
{
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr)
    {}
};

ListNode *intersection(ListNode *head, ListNode *inter)
{
    auto *a = head;
    auto *b = inter;
    while (a != b) {
        a = a->next;
        b = b->next;
    }
    return a;
}

ListNode *detectCycle(ListNode *head) // Floyd's tortoise and hare
{
    if (!head || !head->next) return nullptr;
    auto *t = head;
    auto *h = head;
    do {
        t = t->next;
        h = h->next->next;
        if (!h || !t) return nullptr;
        if (!t->next || !h->next) return nullptr;
    } while (t != h);
    return intersection(head, t);
}

int main()
{
    auto *node1 = new ListNode(1);
    auto *node2 = new ListNode(2);
    auto *node3 = new ListNode(3);
    auto *node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    auto *result = detectCycle(node1);
    cout << (!result ? 0 : result->val) << endl;

    auto *no = new ListNode(1);
    auto *noResult = detectCycle(no);
    cout << (!noResult ? -1 : noResult->val) << endl;

    delete node1, delete node2, delete node3, delete node4;
    return 0;
}
