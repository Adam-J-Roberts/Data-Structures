#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Node
{

    private:
        T data;
        Node<T>* next;
        Node<T>* prev;

    public:
        Node(T data);
        T get_data();
        void set_data(T data);
        Node<T>* get_next();
        void set_next(Node<T>* next); 
        Node<T>* get_prev();
        void set_prev(Node<T>* prev);
        void display_links();
        void print_node();
};
template <typename T>
Node<T>::Node(T data)
{
	this->data = data;
	this->next = NULL;
	this->prev = NULL;	
}
template <typename T>
T Node<T>::get_data()
{
	return this->data;
}
template <typename T>
void Node<T>::set_data(T data)
{
	this->data = data;
}
template <typename T>
Node<T>* Node<T>::get_next()
{
	return this->next;
}
template <typename T>
void Node<T>::set_next(Node<T>* next)
{
	this->next = next;
}
template <typename T>
Node<T>* Node<T>::get_prev()
{
	return this->prev;
}
template <typename T>
void Node<T>::set_prev(Node<T>* prev)
{
	this->prev = prev;
}
template <typename T>
void Node<T>::display_links()
{
	cout << "The next node is " << next << endl;
	cout << "The previous node was " << prev << endl;
}
template <typename T>
void Node<T>::print_node()
{
	cout << "The data is " << data << endl;
	cout << "The next node is " << next << endl;
	cout << "The previous node was " << prev << endl;
}

#endif
