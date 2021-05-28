#include <iostream>
#include <iomanip> 
#include "DynamicArray.cpp"


using namespace std;

int main()
{
	int i=0;
	
	DynamicArray<int> a;
	a.prepend(5);
	a.prepend(4); 
	a.prepend(3);
	a.prepend(2); 
	a.prepend(1); 
	a.prepend(0); 
	a.append(7);
	a.add_at_i(6,6);
	a.remove_at_i(4);
	a.add_at_i(4,4);	
	//a.reverse();
	//a.display_range(3, 5);	
	//a.random_shuffle();
	a.rotate(3);
	a.display_all();

	return 0;
}
