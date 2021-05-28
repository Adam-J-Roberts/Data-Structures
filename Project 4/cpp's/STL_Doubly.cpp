#include <iostream>
#include <list>
#include <iterator>
#include <iomanip> 
#include <ctime>
#include <chrono>
#include <ratio>
#include <fstream>


using namespace std;


int main()
{

	list<int> a;
	list<int> b;
	list<int>::iterator it;
	
	srand(time(NULL));
	int count = 1;																//times function will get run
	int n1; 
	
	std::ofstream outfile;                                                           //starting my off stream
	outfile.open ("STL_LL.txt");											//Creating file to save too

					
	/*							//  PREPEND     //
	outfile << "Prepend" << endl;	
	
	for (int j = 0; j < 6; j++)
	{	
		std::chrono::high_resolution_clock::time_point t1 =  std::chrono::high_resolution_clock::now();       //My start clock
		for (int i = 1; i < count+1; i++) {a.push_front(i);}  
		                          //populate my dynamic array with append
		std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;                                //Start time minus finish time
													//What gets written to file
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		a.clear();
	}
	/*							//  APPEND     //
	outfile << "Append" << endl;	
	count = 1;
	for (int j = 0; j < 6; j++)
	{	
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();        //My start clock
		for (int i = 1; i != count+1; i++) {a.push_back(i);}                        //populate my dynamic array with append
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;                                //Start time minus finish time
		
													//What gets written to file
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		a.clear();
	}
	
										//  ADD AT I     //                 
	outfile << "Add at i" << endl;	
	count = 1;
	for (int j = 0; j < 6; j++)
	{	
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();        //My start clock
		for (int i = 1; i != count; i++) 
		{
			it = a.begin();
			a.insert(it,i);
			advance(it,1);					
		}                        	//populate my dynamic array with add at i
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;                                //Start time minus finish time
		
													//What gets written to file
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		a.clear();
	}
										//  REVERSE		//
	outfile << "Reverse" << endl;	
	//count = 1;
	for (int j = 0; j < 6; j++)
	{	
		for (int i = 1; i < count+1; i++) {a.push_front(i);}    						//populate my dynamic array with append
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();        //My start clock
		a.reverse();									                       	//reverse
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;                                //Start time minus finish time
		
													//What gets written to file
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		a.clear();
	}
										//  SHUFFLE		//
	outfile << "Shuffle" << endl;	
	for (int j = 0; j < 6; j++)
	{	
		for (int i = 1; i < (count+1); i++) {a.push_front(i);}
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		int size1 = a.size();
		//cout << "here" << endl;
		for (int j = 0; j < size1; j++)
		{
			int size = a.size();
			n1 = rand() % size + 1;
			it = a.begin();
			advance (it,(n1-1));
			a.erase(it);
			b.push_front(n1);
		
		}
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;  
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		a.clear();
		b.clear();
	
	}*/
	/*									//  rotate		//
	outfile << "Rotate" << endl;	
	for (int j = 0; j < 6; j++)
	{	
		for (int i = 1; i < (count+1); i++) {a.push_front(i);}
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		int size1 = a.size();
		//cout << "here" << endl;
		n1 =  (a.size() - 4);
		it = a.begin();
		//out << "i:" << i << endl;
		advance (it,n1);
		//cout << "here" << endl;
		for (int j = 0; j < size1; j++)
		{
			cout << "j: " << j << endl;
			if (n1 > 1)
			{ //cout << "here" << endl;
				do{
					cout << "here1 " << endl;
					a.erase(it);
					b.push_back(n1);
					int size1 = a.size();
					cout << size1 << endl;
				}while (size1 < n1);
				it = a.end();
				do{
					cout << "here2 " << endl;
					n1 =  a.size(); 
					it = a.end();
					a.erase(it);
					b.push_back(n1);
				}while (a.size() > 0);
				cout << "here3 " << endl;
			}
		}
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;  
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		a.clear();
		b.clear();
	
	}

	return 0;
}


