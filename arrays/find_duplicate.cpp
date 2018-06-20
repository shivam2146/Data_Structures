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

//in O(n) time using constant space
int findDuplicate2(int arr[],int n){
    int dup = -1,absval;
    for(int i=0;i<n;i++){
      absval = (arr[i]<0? -arr[i]: arr[i]);
      if(arr[absval-1] > 0)
        arr[absval-1] = - arr[absval-1];
      else{
        dup = absval;
        break;
      }
    }
    for(int i=0 ;i<n;i++)
      arr[i] = (arr[i]>0? arr[i] : -arr[i]);
    return dup;
}

int main(){
  int arr[]= {1,1,3,4,3,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"duplicate element is: "<<findDuplicate(arr,n)<<endl;
  cout<<"duplicate element is: "<<findDuplicate2(arr,n)<<endl;
  return 0;
}
