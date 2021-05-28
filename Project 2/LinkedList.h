#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class LinkedList
{
    private:
        Node<T>* head;
        Node<T>* tail;
        size_t type;
        size_t size;
        bool is_circularly;

    public:
        
        LinkedList();                                                                			//DONE!
        LinkedList(Node<T>* head, Node<T>* tail, size_t type, bool is_circularly);   			//DONE!
        size_t get_size();															 			//DONE!
        void append(T data);  //done     												 		//DONE!
        void prepend(T data); //done    													  	//DONE!
        void add_at_i(T data, size_t i);  //done          										//DONE!
        void remove_at_i(size_t i);       //done     											//DONE!
        void change_type(size_t type);   														//DONE!     
        void delete_list();  																	//DONE!       
        void rotate(int r);       																//DONE!
        void reverse();       																	//DONE!
        void random_shuffle();  																//DONE!      
        void display_i(size_t i); 																//DONE!     
        void display_all();       																//DONE!
        void display_range(size_t i = 0, size_t j = 0);											//DONE!
        void display_links();   																//DONE!
        void info();     																		//DONE!  ish
};
template <typename T>		
LinkedList<T>::LinkedList()
{
	this->head = NULL; 
	this->tail = NULL; 
	this->type = 0; 
	this->size = 0; 
	this->is_circularly = false;
	
}
template <typename T>
LinkedList<T>::LinkedList(Node<T>* head, Node<T>* tail, size_t type, bool is_circularly)     //DONE!
{
	this->head = head;
	this->tail = tail;
	this->type = type;
	this->size = 0; 
	this->is_circularly = is_circularly;
}
template <typename T>
size_t LinkedList<T>::get_size()   //DONE  ????
{
	return this->size;
}
template <typename T>
void LinkedList<T>::append(T data) //DONE!
{
		Node<T>* temp = new Node<T>(data);
		tail->set_next(temp);
		if (type == 1){temp->set_prev(tail);}
		tail = temp;
		if (is_circularly == true)
		{
			tail->set_next(head);
			head->set_prev(tail);
		}
		//this->tail = temp;
		size++;
}
template <typename T>
void LinkedList<T>::prepend(T data)  //DONE!
{
		Node<T>* temp = new Node<T>(data);		
		if (size == 0) 
		{
			head = temp;
			tail = head;	
			if (is_circularly == true)
			{
				tail->set_next(head);
				if (type == 2)
				{
					head->set_prev(tail);
				}
			}
			size++;
			return;
		}

		if (type == 1)
		{
			temp->set_next(head);
			head = temp;
		}
		if (type == 2)
		{
			temp->set_next(head);
			head->set_prev(temp);
			head = temp;
		}
		//head = temp;
		if (is_circularly == true)
		{
			tail->set_next(head);
			if (type == 2)
			{
				head->set_prev(tail);
			}
		}
		size++;
}  
template <typename T>
void LinkedList<T>::add_at_i(T data, size_t i)       //DONE!
{
	Node<T>* pre;
	Node<T>* curr = head;
	Node<T>* newNode = new Node<T>(data);

	curr = head;     
	if(i > size)
	{
		cout << "This LinkedList does not have that many nodes." << endl;
	}
	else if(head != NULL)
	{
		for(int k = i; k > 0; k--)
		{
			pre=curr;
			curr = curr->get_next();
		}
		if(i==0)
		{
			cout << "Adding at Head!" << endl;
            prepend(data);
		}
		else if(i == size)
		{
			cout << "Adding at Tail!" << endl;
			append(data);
		}
		else
		{
			pre->set_next(newNode);
			newNode->set_next(curr);
			if (type == 1)
			{
				newNode->set_prev(pre);
				curr->set_prev(newNode);		
			}
			cout << "Node added at position: " << i << endl;
			size++;
		}
	}
	else
	{
		head = newNode;
		tail = newNode;
		cout << "Added first node in LinkedList!" << endl;
		if (is_circularly == true) 
		{ 
			head->set_next(tail);
			tail->set_prev(head);
		}
		size++;
	}
}
template <typename T>
void LinkedList<T>::remove_at_i(size_t i)      
{
	Node<T>* pre;
	Node<T>* curr = head;
	Node<T>* post;
	curr = head;    
	if (head == NULL) { return; }
	if (i+1 > size) { return; }
	if (i == 0)
	{	
		pre = head;
		head = head->get_next();
		delete pre;
		if (type == 2) 
		{
			 head->set_prev(NULL); 
		}
		if (is_circularly == 1) 
		{ 
			this->head->set_prev(tail); 
			this->tail->set_next(head); 
		}
	}
	else if(i > 0 && i < size -1)
	{
		for(int k = 0; k != i; k++)
		{
			pre=curr;
			curr = curr->get_next();
			post = curr->get_next();
		}
		pre->set_next(post);
		delete curr;
		if (type == 2)
		{
			post->set_prev(pre);
		}
	}
	else if(i+1 == size) 
	{ 
		for(int k = 0; k != i-1; k++)
		{
			pre=curr;
			curr = curr->get_next();
			post = curr->get_next();
		} 
		tail = curr;
		delete post;
		tail->set_next(NULL);
		if (is_circularly == 1) 
		{	
			tail->set_next(head); 
		}
		if (type == 2 && is_circularly == 1)
		{	
			head->set_prev(tail);
		}
	
		
		
	}
	size--;
}

template <typename T>
void LinkedList<T>::change_type(size_t type)       
{
	string type_name;
	char confirm;
	Node<T>* pre;
	Node<T>* curr = head;
	Node<T>* post;
	
	/*if(this->type == 1)	{ type_name = "singly"; }
	if(this->type == 2)	{ type_name = "doubly"; }*/
	
	if (type == 1)
	{
		for (int i = size-1; i > 0; i--)
		{
			pre = curr;
			curr = curr->get_next();
			curr->set_prev(pre);
		}	
		this->type = 2;
	}
	if (type == 2)
	{
		for (int i = size-1; i > 0; i--)
		{
			pre = curr;
			curr = curr->get_next();
			curr->set_prev(NULL);
		}
		this->type = 1;		
	}		
}
template <typename T>
void LinkedList<T>::delete_list()     
{
	Node<T>* pre;
	Node<T>* curr = head;
	Node<T>* post;
	
	while(curr->get_next() != tail)
	{
		pre = curr;
		curr = curr->get_next();
		delete pre;
	}	
	delete this;
}
template <typename T>
void LinkedList<T>::rotate(int r)        
{
	if (r > 0)
	{
		for(int i = 0; i != r; i++)
		{
			Node<T>* pre = head;
			Node<T>* curr = head;
			
			while(curr->get_next() != tail)
			{
				curr = curr->get_next();
			}
			tail = curr;
			head = tail->get_next();
			head->set_next(pre);
			if (is_circularly != 1) 
			{	
				head->set_prev(NULL);
				tail->set_next(NULL);
			}
			if (type == 2)
			{
				curr = head->get_next();
				curr->set_prev(head);
			}	
		}
	}
	if (r < 0)
	{
		for(int i = r; i != 0; i++)
		{
			Node<T>* temp = head;

			head = head->get_next();
			tail->set_next(temp);
			tail = temp;
			if (type == 1)
			{
				if (is_circularly == false) { tail->set_next(NULL); }
			}
			if (type == 2)
			{
				if (is_circularly == false) 
				{ 
					tail->set_next(NULL); 
					head->set_prev(NULL);
				}
			}
		}		
	}		
			
			
			
			/*
			while(curr->get_next() != tail)
			{
				curr = curr->get_next();
			}
			tail = curr;
			head = tail->get_next();
			head->set_next(pre);
			if (is_circularly != 1) 
			{	
				head->set_prev(NULL);
				tail->set_next(NULL);
			}
			if (type == 2)
			{
				curr = head->get_next();
				curr->set_prev(head);
			}	
		}		
	}*/
	
}
template <typename T>
void LinkedList<T>::reverse()      
{
	Node<T>* prev   = NULL;
    Node<T>* curr = head;
    Node<T>* post;
    Node<T>* temp;
    
		while (curr != NULL || curr == head)
		{
			post = curr->get_next();  
			curr->set_next(prev);   
			prev = curr;
			curr = post;
		}
		temp = tail;
		tail = head;
		head = temp;
}
template <typename T>
void LinkedList<T>::random_shuffle()        
{		
	Node<T>* curr = head;
	Node<T>* pre;
	Node<T>* post;
	int slot = 0;
	int n1;
	int length = size;

	for(int j = size; j > 0; j--)
	{
		do {	
			n1 = rand()%(length-1)+1;
		}
		while (n1 < slot && n1 == 0 && n1 < (length-1));
		
		for(int k = n1; k > 0; k--)
		{
			pre = curr;
			curr = curr->get_next();
		}
		if (curr==tail) 
		{
			tail = pre;
			tail->set_next(NULL);
		}
		else
		{
			post = curr->get_next();
			pre->set_next(post);
		}
		if (type == 2) 
		{ 
			post->set_prev(pre);
			curr->set_prev(NULL);
		}
		curr->set_next(head);
		head=curr;
		if (is_circularly == 1) 
		{
			tail->set_next(head);
				if (type == 2) 
				{ 
					head->set_prev(tail);
				}
		}
		slot++;
	}
	
	/*
		 * fuck this noise!  Get back to this later. HAS TO BE AN EASIER WAY!
		 * if (n1 == n2) { }
		else if (n1 == 0)
		{
			curr2->set_next(post1);
			head = curr2;
			pre2->set_next(curr1);
			curr1->set_next(post2);	
			if(is_circularly == true) { tail->set_next(head); }
		}
		else if (n2 == 0)
		{
			curr1->set_next(post2);
			head = curr1;
			pre1->set_next(curr2);
			curr2->set_next(post1);
			if(is_circularly == true) { tail->set_next(head); }
		}
		else if (n2+1 == n1)// || n2-1 == n1)
		{
			pre1->set_next(curr2);
			curr2->set_next(curr1);
			curr1->set_next(post2);				
		}
		else if (n1+1 == n2)// || n2-1 == n1)
		{
			pre2->set_next(curr1);
			curr1->set_next(curr2);
			curr2->set_next(post1);				
		}			
		else
		{
			curr1->set_next(post2);
			pre1->set_next(curr2);
			curr2->set_next(post1);
			pre2->set_next(curr1);
			if(is_circularly == true) { tail->set_next(head); }
		}
		
		//if (n1 != 0)
		//{
		//	pre1->set_next(curr2);	
		//}
		if (type == 2)
		{
			curr1->set_prev(pre2);
			curr2->set_prev(pre1);
			post1->set_prev(curr2);
			post2->set_prev(curr1);
		}
		this->display_all();*/
	//}
}
template <typename T>
void LinkedList<T>::display_i(size_t i)       //DONE!
{
	Node<T>* pre;
	Node<T>* curr = head;
	Node<T>* post;

	if (head == NULL) { return; }
	if (i > size) { return; }
			
	for(int k = i; k > 0; k--)
	{
		curr = curr->get_next();
	}
	cout << curr->get_data() << endl;
}
template <typename T>
void LinkedList<T>::display_all()  //DONE!
{
	cout << "List: ";   
	if (this->head == NULL)
	{
		cout << "EMPTY LIST\n";
		return;
		}
            
	Node<T>* c = this->head;
   
    do	{
		cout << c->get_data() << " ";
		c = c->get_next();
	}while (c != head && c != NULL);
	
	cout << endl;
}
template <typename T>
void LinkedList<T>::display_range(size_t i, size_t j)
{
	Node<T>* curr = head;
	
	if (j > i)
	{
		cout << "Error: j cannot be larger than i\n";
		return;
	}
	if (j > size)
	{
		cout << "Error: j cannot be larger than size\n";	
	}
	for(int k = j; k > 0; k--)
	{
		curr = curr->get_next();
		cout << "poop" << endl; 
	}
	cout << "List: ";
	for(int k = i-j; k+1 > 0; k--)
	{
		cout << curr->get_data() << " ";
		curr = curr->get_next();
	}
		cout << endl;
}
template <typename T>
void LinkedList<T>::display_links()     
{
	cout << "Links:"
		 << "\n\thead = " << this->head
		 << "\n\ttail = " << this->tail 
		 << endl; //<< tail->get_data() << endl;
	
	
	 /* Use this to check if links are correct. Fix while loop with for loop later. (maybe...)
	Node<T>* pre;
	Node<T>* curr = head;
	int k = 0;

	for(int i = size; i > 0; i--)
	{
		cout << "Node " << k << endl
			 << "Prev: " << curr->get_prev() << " "
			 << "curr: " << curr << " "
			 << "next: " << curr->get_next() << endl;
		pre = curr;
		curr = curr->get_next();
		k++;
	}*/
}
template <typename T>
void LinkedList<T>::info()      
{
	string t;
	
	if (type == 1) { t = "Singly"; }
	if (type == 2) { t = "Doubly"; }
	
	
	//string t = (this->type) ? "Doubly" : "Singly" ; //Goddamn turnary!! Either change this or switch type to bool. NOPE! Not changing this!
	t += (is_circularly) ? "-circularly " : " ";
	cout << "Type: " << t << "linked-list\n";
            
	cout << "Size: " << this->size << std::endl;
	this->display_links();
}

#endif
