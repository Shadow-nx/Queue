#include "queue1.hpp"


        Queue::Queue(){
            list=new ForwardList{nullptr,nullptr};
            }
        Queue::Queue(std::initializer_list<int> list1){
            list=new ForwardList{nullptr,nullptr};
            for(int x : list1){
               if(list->first==nullptr){
                   list->first=new Node{x,nullptr};
                   list->last=list->first;
                   continue;
               }
               list->last->next=new Node{x,nullptr};
               list->last=list->last->next;
           }
        }
        Queue::Queue(const Queue& q){
            list=new ForwardList{nullptr,nullptr};
            for(Node* curr=q.list->first; curr != nullptr; curr=curr->next){
                if(list->first == nullptr)
                {
                    list->first = new Node{curr->data,nullptr};
                    list->last = list->first;
                    continue;
                }
                list->last->next = new Node{curr->data,nullptr};
                list->last = list->last->next;
            }
        }
        auto Queue::swap_(Queue& q) -> void{
           swap(list,q.list);
        }

        auto Queue::operator=(const Queue& q) -> void{
            for(Node* curr=q.list->first; curr != nullptr; curr=curr->next){
                if(list->first == nullptr)
                {
                    list->first = new Node{curr->data,nullptr};
                    list->last = list->first;
                    continue;
                }
                list->last->next = new Node{curr->data,nullptr};
                list->last = list->last->next;
            }
        }
        auto Queue::empty() -> bool{
            if(list->first == nullptr && list->last == nullptr)
                return true;
            else
                return false;
        }
        auto Queue::size() -> int{
            int size_=0;
            for(Node *curr=list->first; curr!=nullptr; curr=curr->next){
                size_++;
            }
            return size_;
        }
        auto Queue::push(int value) -> void{
            if(list->first == nullptr){
                list->first=new Node{value,nullptr};
                list->last=list->first;
                return;
            }
            list->last->next=new Node{value,nullptr};
            list->last=list->last->next;
        }
        auto Queue::pop() -> void{
            if(list->first != list-> last){
                Node* pop_element=list->first;
                list->first=list->first->next;
                delete pop_element;
                pop_element=nullptr;
            }else{
                delete list->first;
                list->first=new Node{0,nullptr};
                list->last=list->first;
            }
        }
        auto Queue::front() -> int&{
            return list->first->data;
        }
        auto Queue::back() -> int&{
            return list->last->data;
        }
        auto Queue::operator==(const Queue& q) -> bool {
            Node* curr1=list->first;
            Node* curr2=q.list->first;
            while(curr1 != nullptr || curr2 != nullptr){
                if(curr1->data != curr2->data)
                    return false;
                curr1=curr1->next;
                curr2=curr2->next;
            }
            return true;
        }
        auto operator<<(ostream& os, Queue& q) -> ostream&{
            for(Node *curr=q.list->first; curr!=nullptr; curr=curr->next){
                os << curr-> data << " ";
            }
                os << endl;
                return os;
        }
        auto operator>>(istream& is, Queue& q) -> istream&{
        int value;
            while(is>>value){
                if(q.list->first == nullptr){
                    q.list->first = new Node{value,nullptr};
                    q.list->last = q.list->first;
                    continue;
                }
                q.list->last->next = new Node{value,nullptr};
                q.list->last =  q.list->last->next;
            }
            return is;
        }
        Queue::~Queue(){
            delete list;
        }
