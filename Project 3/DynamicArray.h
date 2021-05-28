#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class DynamicArray
{
    private:
		int array_size;
		int array_count;
		T* array;
		
    public: 
        DynamicArray();                   			//DONE!                                             	
        int get_size();								//DONE!					 			
        void append(T data);     					//DONE!							 	
        void prepend(T data); 						//DONE!					  	
        void add_at_i(T data, size_t i);          	//DONE!										
        void remove_at_i(size_t i);         		//DONE!										  														     
        void delete_array();  						//DONE!											      
        void rotate(int r);       																
        void reverse(); 							//DONE!      																	
        void random_shuffle();  					//DONE! 											      
        void display_i(size_t i); 					//DONE! 															     
        void display_all();       					//DONE! 											
        void display_range(int i, int j);			//DONE!
        void array_resize();     					//DONE!													
};
#endif
