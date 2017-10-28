#include <iostream>
using namespace std;

// function to get fast input of integers
void fastScan(int &num){
	int c;
	num=0;
	c=getchar_unlocked();
	for(;(c>47 && c<58);c=getchar_unlocked()){
		num= num*10+c-48;	 
	}
}


int main(){
	
	int n;  //no of array elements
	fastScan(n);
  
	int arr[1001]={0};  //array for storing occurances intially zero
	int arr1[n];  //array for storing elements
	for(int i=0;i<n;i++)
	{
	    fastScan(arr1[i]);
	    arr[arr1[i]]++;     //incrementing element count when input 
	}
	int q,q1;  // q is no of queries and q1 is for every query
	fastScan(q);
	for(int i=0;i<q;i++)
	{
	    fastScan(q1);
	    if(arr[q1]==0)
	        cout<<"NOT PRESENT\n";
	    else
	        cout<<arr[q1]<<"\n";
	}
	
}
