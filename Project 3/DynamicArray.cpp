#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray()   
{
	array_size = 5;
	array_count = 0;
	array = new T[array_size];
}  
template <typename T>                                                          	
int DynamicArray<T>::get_size()
{
	return this->array_count;
}	
template <typename T>														 			
void DynamicArray<T>::append(T data)
{
	array[array_count] = data;
	array_count++;
	this->array_resize();
}    
template <typename T> 												 	
void DynamicArray<T>::prepend(T data)
{
	T* copy = new T[array_size];
	copy[0] = data;
	array_count++;
	for (int i = 1; i < array_count; i++)
		copy[i] = array[i-1];
	delete[] array;
	array = copy;
	this->array_resize();
	
}
template <typename T> 													  	
void DynamicArray<T>::add_at_i(T data, size_t i)
{
	
	T* copy = new T[array_size];
	array_count++;
	for (int j = 0; j < i; j++)
		copy[j] = array[j];
	copy[i] = data;
	for (int k = i+1; k < array_count; k++)
		copy[k] = array[k-1];

	delete[] array;
	array = copy;
	this->array_resize();
}
template <typename T>          										
void DynamicArray<T>::remove_at_i(size_t i)
{
	T* copy = new T[array_size];
	
	for (int j = 0; j < (i); j++)
		copy[j] = array[j];
	for (int k = i+1; k < array_count; k++)
		copy[k-1] = array[k];
	delete[] array;
	array = copy;
	array_count--;
	this->array_resize();
}
template <typename T>
void DynamicArray<T>::delete_array()  																	      
{
	array_count = 0;
	delete[] array;
}
template <typename T>
void DynamicArray<T>::rotate(int r)     																
{	
	
	for(int j = 0; j < r; j++)
	{
		
		T* copy = new T[array_size];
		for(int i = 0; i < array_count-1; i++)
		{
			//cout << array[i] << endl;
			copy[i+1] = array[i];
		} 
		copy[0] = array[array_count-1];
		delete[] array;
		array = copy;
	}
	
}
template <typename T>
void DynamicArray<T>::reverse()      																	
{
	T* copy = new T[array_size];
	int k = array_count-1;
	
	for (int j = 0; j < array_count; j++)
	{
		copy[j] = array[k];
		k--;
	}
	delete[] array;
	array = copy;
}
template <typename T>
void DynamicArray<T>::random_shuffle()  																      
{
	T data1;
	
	srand(time(NULL));
	for(int j = (array_count/2+2); j > 0; j--)
	{		
		int n1 = rand()%(array_count)+0;
		int n2 = rand()%(array_count)+0;
		
		data1 = array[n1];
		array[n1] = array[n2];
		array[n2] = data1;
	}
}
template <typename T>
void DynamicArray<T>::display_i(size_t i) 																     
{
	cout << array[i] << endl;
}
template <typename T>
void DynamicArray<T>::display_all()       																
{
	for(int i=0; i < array_count; i++)
		cout << array[i] << endl;
}
template <typename T>
void DynamicArray<T>::display_range(int i, int j)											
{
	for(int k=i; k < j+1; k++)
		cout << array[k] << endl;
}
template <typename T>
void DynamicArray<T>::array_resize()
{
	if (array_size < (array_count + (array_count/2)) || array_size > array_count*2 || array_size > 4)
	{
		array_size = (array_count * 2);
		T* resized = new T[array_size];
		for (int i = 0; i < array_count; i++)
			resized[i] = array[i];
		delete[] array;
		array = resized;
	}
}
