#include <initializer_list>
#include <iostream>

using namespace std;

template <class T>
struct Node {
	T data;
	Node<T>* next;
};
template <class T>
struct ForwardList {
	Node<T>* first;
	Node<T>* last;
};
template <class T>
class Queue {
	public:
		Queue();
		Queue(std::initializer_list<T> list1);
		Queue(const Queue& q);
		auto swap_(Queue& q) -> void;
		auto operator=(const Queue& q) -> void;
		auto empty() -> bool;
		auto size() -> int;
		auto push(T value) -> void;
		auto pop() -> void;
		auto front() -> T&;
		auto back() -> T&;
		auto operator==(const Queue& q) -> bool;
		~Queue();
		template <class T2>
		friend auto operator<<(ostream& os, Queue<T2>& q) -> ostream&;
		template <class T3>
		friend auto operator>>(istream& is, Queue<T3>& q) -> istream&;
	private:
		ForwardList<T> *list;
};

template <class T>
Queue<T>::Queue() {
	list=new ForwardList<T> {nullptr,nullptr};
}
template <class T>
Queue<T>::Queue(std::initializer_list<T> list1) {
	list=new ForwardList<T> {nullptr,nullptr};
	for(int x : list1) {
		if(list->first==nullptr) {
			list->first=new Node<T> {x,nullptr};
			list->last=list->first;
			continue;
		}
		list->last->next=new Node<T> {x,nullptr};
		list->last=list->last->next;
	}
}
template <class T>
Queue<T>::Queue(const Queue<T>& q) {
	list=new ForwardList<T> {nullptr,nullptr};
	for(Node<T>* curr=q.list->first; curr != nullptr; curr=curr->next) {
		if(list->first == nullptr) {
			list->first = new Node<T> {curr->data,nullptr};
			list->last = list->first;
			continue;
		}
		list->last->next = new Node<T> {curr->data,nullptr};
		list->last = list->last->next;
	}
}
template <class T>
auto Queue<T>::swap_(Queue<T>& q) -> void {
	swap(list,q.list);
}
template <class T>
auto Queue<T>::operator=(const Queue<T>& q) -> void {
	for(Node<T>* curr=q.list->first; curr != nullptr; curr=curr->next) {
		if(list->first == nullptr) {
			list->first = new Node<T> {curr->data,nullptr};
			list->last = list->first;
			continue;
		}
		list->last->next = new Node<T> {curr->data,nullptr};
		list->last = list->last->next;
	}
}
template <class T>
auto Queue<T>::empty() -> bool {
	if(list->first == nullptr && list->last == nullptr)
		return true;
	else
		return false;
}
template <class T>
auto Queue<T>::size() -> int {
	int size_=0;
	for(Node<T>*curr=list->first; curr!=nullptr; curr=curr->next) {
		size_++;
	}
	return size_;
}
template <class T>
auto Queue<T>::push(T value) -> void {
	if(list->first == nullptr) {
		list->first=new Node<T> {value,nullptr};
		list->last=list->first;
		return;
	}
	list->last->next=new Node<T>{value,nullptr};
	list->last=list->last->next;
}
template <class T>
auto Queue<T>::pop() -> void {
	if(list->first != list-> last) {
		Node<T>* pop_element=list->first;
		list->first=list->first->next;
		delete pop_element;
		pop_element=nullptr;
	} else{
		delete list->first;
		list->first=new Node<T>{0,nullptr};
		list->last=list->first;
	}
}
template <class T>
auto Queue<T>::front() -> T& {
	return list->first->data;
}
template <class T>
auto Queue<T>::back() -> T& {
	return list->last->data;
}
template <class T>
auto Queue<T>::operator==(const Queue<T>& q) -> bool {
	Node<T>* curr1=list->first;
	Node<T>* curr2=q.list->first;
	while(curr1 != nullptr || curr2 != nullptr) {
		if(curr1->data != curr2->data)
			return false;
		curr1=curr1->next;
		curr2=curr2->next;
	}
	return true;
}
template <class T2>
auto operator<<(ostream& os, Queue<T2>& q) -> ostream& {
	for(Node<T2>*curr=q.list->first; curr!=nullptr; curr=curr->next) {
		os << curr-> data << " ";
	}
	os << endl;
	return os;
}
template <class T3>
auto operator>>(istream& is, Queue<T3>& q) -> istream& {
	int value;
	while(is>>value) {
		if(q.list->first == nullptr) {
			q.list->first = new Node<T3> {value,nullptr};
			q.list->last = q.list->first;
			continue;
		}
		q.list->last->next = new Node<T3> {value,nullptr};
		q.list->last =  q.list->last->next;
	}
	return is;
}
template <class T>
Queue<T>::~Queue() {
	Node<T>* curr;
	while(list->first!=list->last) {
		curr=list->first;
		list->first=list->first->next;
		delete curr;
	}
	delete list->first;
	list->first=nullptr;
	list->last=nullptr;
	delete list;

}
