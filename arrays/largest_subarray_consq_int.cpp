#include<iostream>
#include<vector>
#include<utility>
using namespace std;

bool isConsecutive(int arr[],int i,int j,int max,int min){
    if(max-min != j-i)
      return false;
    vector<bool> visited(j-i+1,false);
    for(int k=i; k<=j;k++){
      if(visited[arr[k]-min])
        return false;
      else
        visited[arr[k]-min] =true;
    }
    return true;
}

void largest_subarray(int arr[],int n){
  int i,j,max,min;
  pair<int,int> largest_sub(-1,-1);
  for(i=0;i<n-1;i++){
    max= min =arr[i];
    for(j=i+1;j<n;j++){
      if(arr[j]>max)
        max = arr[j];
      if(arr[j]<min)
        min = arr[j];
      if(isConsecutive(arr,i,j,max,min))
        if(largest_sub.second-largest_sub.first < j-i){
            largest_sub .first = i;
            largest_sub.second = j;
        }
    }
  }
  cout<<"largest subarray of consecutive integers are ["<<largest_sub.first<<"...."<<largest_sub.second<<"]\n";
}

int main(){
  int arr[]= {2,0,2,1,4,3,1,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  largest_subarray(arr,n);
  return 0;
}
