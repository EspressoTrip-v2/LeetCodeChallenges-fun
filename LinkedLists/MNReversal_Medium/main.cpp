#include <iostream>
using namespace std;

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {}
    explicit ListNode(int x) : val(x), next(nullptr)
    {}
    ListNode(int x, ListNode *next) : val(x), next(next)
    {}
};

void print(ListNode *n)
{
    auto step = n;
    while (n->next != nullptr) {
        cout << n->val << " -> ";
        n = n->next;
    }
    cout << n->val << endl;
}
ListNode *process(ListNode *previous_, ListNode *begin_, int right_)
{
    ListNode *tail = previous_;
    previous_->next = nullptr;
    ListNode *step = begin_;
    ListNode *temp = nullptr;
    while (step->next != nullptr) {
        temp = step->next;
        step->next = previous_;
        previous_ = step;
        if (step->val == right_) {
            tail->next = temp;
            break;
        }
        step = temp;
    }
    if (step->next == nullptr) step->next = previous_;
    return step;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head->next == nullptr) return head;
    ListNode *start = head;
    ListNode *prevStep = head;
    ListNode *step = start->next;
    ListNode *temp = nullptr;
    while (step != nullptr) {
        if (start->val == left) {
            start = process(start, step, right);
            break;
        }
        if (step->val == left) {
            temp = process(step, step->next, right);
            prevStep->next = temp;
            step = prevStep;
            break;
        }
        prevStep = step;
        step = step->next;
    }

    return start;
};
int main()
{
    auto nodeA = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4,
            new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(8,
                    new ListNode(9, new ListNode(10))))))))));
    auto *r = reverseBetween(nodeA, 1, 5);
    print(r);

    auto *nodeB = new ListNode(1, new ListNode(2));
    auto *rB = reverseBetween(nodeB, 1, 2);
    print(rB);
    delete nodeA;
    delete nodeB;
    return 0;
}
