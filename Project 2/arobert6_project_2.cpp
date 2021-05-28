#include <iostream>
#include <iomanip> 
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	srand(time(NULL));	
	LinkedList<int> a(NULL, NULL, 1, false);
	LinkedList<int> b(NULL, NULL, 1, true);
	LinkedList<int> c(NULL, NULL, 2, false);
	LinkedList<int> d(NULL, NULL, 2, true);
	

	for (int i = 10; i > 0; --i) { a.prepend(i); }
	for (int i = 10; i > 0; --i) { b.prepend(i); }
	for (int i = 10; i > 0; --i) { c.prepend(i); }
	for (int i = 10; i > 0; --i) { d.prepend(i); }
	

	
	for (int i = 2; i > 0; --i)
	{
		a.random_shuffle();
		b.random_shuffle();
		c.random_shuffle();
		d.random_shuffle();
		
		a.info();
		a.display_all();
		cout << endl;
		b.info();
		b.display_all();
		cout << endl;
		c.info();
		c.display_all();
		cout << endl;
		d.info();
		d.display_all();
		cout << endl;
	}
	
	a.rotate(3);
	a.display_all();
	c.rotate(-3);
	c.display_all();
	
	b.reverse();
	b.display_all();
	d.reverse();
	d.display_all();
	
	
	
	
	
	
	

		
	return 0;
}
