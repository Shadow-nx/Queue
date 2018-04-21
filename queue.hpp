#include <initializer_list>
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
struct ForwardList{
    Node* first;
    Node* last;
};


class Queue{
    public:
        Queue();
        Queue(std::initializer_list<int> list1);
        Queue(const Queue& q);
        auto swap_(Queue& q) -> void;
        auto operator=(const Queue& q) -> void;
        auto empty() -> bool;
        auto size() -> int;
        auto push(int value) -> void;
        auto pop() -> void;
        auto front() -> int&;
        auto back() -> int&;
        auto operator==(const Queue& q) -> bool;
        ~Queue();
        friend auto operator<<(ostream& os, Queue& q) -> ostream&;
        friend auto operator>>(istream& is, Queue& q) -> istream&;
    private:
        ForwardList *list;
};
