#include<iostream>
#include<utility>
#include<limits.h>
using namespace std;

//such that a[i] < a[j] then i<j and diff is max
void maxDiffPair(int arr[],int n){
  pair<int,int> p;
  int maxdiff = INT_MIN;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(maxdiff < arr[j]-arr[i]){
        maxdiff = arr[j]-arr[i];
        p={i,j};
      }
    }
  }
  cout<<"maximum difference is : "<<maxdiff<<" and the pair is : ("<<arr[p.first]<<","<<arr[p.second]<<")\n";
}

int main(){
  int arr[]={2,7,9,5,1,3,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  maxDiffPair(arr,n);
  return 0;
}
