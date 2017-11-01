#include <iostream>
using namespace std;
int main(){
    int test_case_count;
    cin>>test_case_count;
    int n,k,i;
    for(i=0;i<test_case_count;i++){
        cin>>n;
        cin>>k;
        int arr[n],min;
	    cin>>a[0];
	    min=a[0];
        for(int j=1;j<n;j++){
            cin>>arr[j];
            if(arr[j]<min)
                min=arr[j];
        }
        int flag=1,c=0;
            if(min<k)
                flag=0;
           while(flag==0){
                flag=1;
                min++;
		if(min<k)    
                    flag=0;
           		
               c++;
           }
			    
                cout<<c<<endl;
    }
    
    
    
    return 0;
}
