#include<bits/stdc++.h> 
using namespace std; 

// Function to find page faults using FIFO 
int pageFaults(int pages[], int n, int capacity) 
{ 
	// To decrease the time complexity used set here
	unordered_set<int> s; 

	// To store the pages in FIFO manner 
	queue<int> indexes; 

	
	int page_faults = 0; 
	for (int i=0; i<n; i++) 
	{ 
		// if capicity is moe than the no of pages given as input by the user
		if (s.size() < capacity) 
		{ 
		
			if (s.find(pages[i])==s.end()) 
			{ 
				// Insert the current page 
				s.insert(pages[i]); 

				
				page_faults++; 

				// Push the current page into the queue 
				indexes.push(pages[i]); 
			} 
		} 

	    
		else
		{ 
			
			if (s.find(pages[i]) == s.end()) 
			{ 
				
				int val = indexes.front(); 
				
				// Pop the first page from the queue 
				indexes.pop(); 

				// Remove the indexes page from the set 
				s.erase(val); 

				// insert the current page in the set 
				s.insert(pages[i]); 

				
				indexes.push(pages[i]); 

				// Increment page faults 
				page_faults++; 
			} 
		} 
	} 

	return page_faults; 
} 

 
int main() 
{ 
	

	int n;
	cout<<"Enter the no of pages in the page list"<<endl;
	cin>>n;
	int pages[n];
	for(int i=0;i<n;i++)
	{
	    cin>>pages[i];
	}
	
    int capacity;
    cout<<"Enter the capicity"<<endl;
    cin>>capacity;
	cout << pageFaults(pages, n, capacity); 
	return 0; 
} 

