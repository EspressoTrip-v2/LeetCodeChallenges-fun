#include <iostream>
#include <memory>
using namespace std;

template< typename T >
struct Node
{
    using node = Node<T>;
    using node_ptr = shared_ptr<node>;
    T value;
    node_ptr next;
    explicit Node(T value) : value(value), next(nullptr)
    {}
    node &setNext(T data_)
    {
        next = make_shared<node>(data_);
        return *next;
    }
};

template< typename T >
struct link_list
{
    using node = Node<T>;
    using node_ptr = shared_ptr<node>;
    node_ptr m_head;
    link_list() : m_head(nullptr)
    {}
    node &set(T data_)
    {
        m_head = make_shared<node>(data_);
        return *m_head;
    }
    friend ostream &operator<<(ostream &os, const link_list &list)
    {
        auto current{list.m_head};
        while (current->next != nullptr) {
            os << current->value << " -> ";
            current = current->next;
        }
        os << current->value << endl;
        return os;
    }

};

template< typename T >
void reverseList(link_list<T> &l)
{
    auto previous = l.m_head;
    auto step = previous->next;
    previous->next = nullptr;
    while (step->next != nullptr) {
        auto temp = step->next;
        step->next = previous;
        previous = step;
        step = temp;
    }
    step->next = previous;
    l.m_head = step;
}

int main()
{
    link_list<int> l;
    l.set(1).setNext(2).setNext(3).setNext(4).setNext(5);
    cout << l;
    reverseList(l);
    cout << l;
    return 0;
}
