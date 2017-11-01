#include<iostream>
using namespace std;
void fastscan(int &number)
{
    register int c; //directs compiler to use register for storing c
 
    number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();   //getchar_unlocked faster than getchar but it is thread unsafe
    
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
 
}
int main()
{
  int testCases,numEle;
  fastscan(testCases);
  while (testCases > 0){
    fastscan(numEle);
    int arr[numEle],occurance[1000001];   
    std::fill_n(occurance, 1000001, -1);
    for (int i=0;i <numEle;i++){
  	    fastscan(arr[i]);
  	    occurance[arr[i]]=i+1;
    }
    int numQueries,x;
    fastscan(numQueries);
    for (int i=0; i < numQueries; i++){
        fastscan(x);
        if (x <= 1000000)
  	        cout<<occurance[x]<<"\n";
  	    else
  	        cout<<"-1"<<"\n";
     }
     testCases--;
    }
  return 0;
}
