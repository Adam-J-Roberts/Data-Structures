#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip> 
#include <ctime>
#include <chrono>
#include <ratio>
#include <fstream>


using namespace std;


int main()
{
	vector<int> a;

	
	srand(time(NULL));
	int count = 1;																//times function will get run
	int n1; 
	std::ofstream outfile;                                                           //starting my off stream
	outfile.open ("Vector.txt");											//Creating file to save too

					
	/*							//  PREPEND     //
	outfile << "Prepend" << endl;	
	for (int j = 0; j < 6; j++)
	{	
		std::chrono::high_resolution_clock::time_point t1 =  std::chrono::high_resolution_clock::now();       //My start clock
		for (int i = 1; i < count+1; i++) {a.insert (a.begin(), i);}  
		                          //populate my dynamic array with append
		std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;                                //Start time minus finish time
													//What gets written to file
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		a.clear();
	}
									//  APPEND     //
	outfile << "Append" << endl;
	count = 1;		
	for (int j = 0; j < 6; j++)
	{	
		std::chrono::high_resolution_clock::time_point t1 =  std::chrono::high_resolution_clock::now();       //My start clock
		for (int i = 1; i < count+1; i++) {a.push_back(i);}  
		                          //populate my dynamic array with append
		std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;                                //Start time minus finish time
													//What gets written to file
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		a.clear();
	}
									//  Add at i     //	
	outfile << "Add at i" << endl;	
	count = 1;
	for (int j = 0; j < 6; j++)
	{	
		std::chrono::high_resolution_clock::time_point t1 =  std::chrono::high_resolution_clock::now();       //My start clock
		for (int i = 1; i < count+1; i++) {a.insert (a.begin(), i);}  
		                          //populate my dynamic array with append
		std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();        //My end clock
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
		for (int i = 1; i < count+1; i++) {a.insert (a.begin(), i);}     						//populate my dynamic array with append
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();        //My start clock
		reverse(a.begin(),a.end());									                       		//reverse
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
		for (int i = 1; i < (count+1); i++) {a.push_back(i);}                                               	//Populate
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();		//start clock
		//int size1 = a.max_size();
		//cout << "here" << endl;
		//n1 = rand() % size + 1;
		random_shuffle (a.begin(), a.end());
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;  
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		a.clear();
	
	}*/
	
												//  Rotate		//
	outfile << "Shuffle" << endl;	
	for (int j = 0; j < 6; j++)
	{	//cout << j << endl;  
		for (int i = 1; i < (count+1); i++) {a.push_back(i);}
		                                             	//Populate
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();		//start clock
		//int size1 = a.max_size();
		//cout << "here" << endl;
		//n1 = rand() % size + 1;
		 
		rotate(a.begin(),a.begin()+1,a.end());
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();        //My end clock
		std::chrono::duration<double, milli> time_span = t2 - t1;  
		outfile << "It took me " << time_span.count() << " seconds to run this " 
			    << count << " times." << endl;										//First test results
		count = (count * 10);
		//a.clear();
	
	}
	
	
	
	
	
	
	
	
	return 0;
}
