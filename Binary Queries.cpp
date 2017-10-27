#include <iostream>
using namespace std;
int main()
{
	int io_array_size,query_count;
	
	cin>>io_array_size>>query_count;
	
	bool arr[io_array_size];
	
	for(int i=0;i<io_array_size;i++)
	{
		cin>>arr[i];          //input the binary string
	}
  
	int q_type_checker;
	int q1,q2;
	
  for(int j=0;j<query_count;j++)
	{
		cin>>q_type_checker;
		if(q_type_checker==1)  // if checker==1 we have to flip the q1th bit 
		{
			cin>>q1;
			arr[q1-1]=!arr[q1-1];
		}
		else{                 // else check if substring q1 to q2 is odd or even
			  cin>>q1>>q2;
			  if(arr[q2-1]==0)
				  cout<<"EVEN\n";
			  else
				  cout<<"ODD\n";	
		    }
	 }
}
