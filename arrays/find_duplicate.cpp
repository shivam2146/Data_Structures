#include<iostream>
#include<unordered_map>
using namespace std;

int findDuplicate(int arr[],int n){
  unordered_map<int,bool> map;
  for(int i=0;i<n;i++){
    if(map.find(arr[i]) == map.end())
      map.insert({arr[i],1});
    else
      return arr[i];
  }
  return -1;
}

int main(){
  int arr[]= {1,2,3,4,3,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"duplicate element is: "<<findDuplicate(arr,n);
  return 0;
}
