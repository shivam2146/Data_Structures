#include<iostream>
#include<limits.h>
#include<utility>
using namespace std;

//naive approach
pair<int,int> maxProductPair(int arr[],int n){
  int maxProd = INT_MIN;
  pair<int,int> x(-1,-1);
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++)
      if(arr[i]*arr[j] > maxProd){
          maxProd = arr[i]*arr[j];
          x = {i,j};
      }
  }
  return x;
}

//better approach
pair<int,int> maxProductPair2(int arr[],int n){
  int max = INT_MIN, max_sec = INT_MIN;
  int min = INT_MAX, min_sec = INT_MAX;
  for(int i=0; i<n; i++){
    if(arr[i] > max){
      max_sec= max;
      max = arr[i];
    }else if(arr[i] > max_sec)
      max_sec = arr[i];
    if(arr[i] < min){
      min_sec = min;
      min = arr[i];
    }else if(arr[i] < min_sec)
      min_sec = arr[i];
  }
  if(min_sec * min > max_sec*max)
    return {min,min_sec};
  else
    return {max,max_sec};
}

int main(){
  int arr[]= {-10,-3,5,6,-5};
  int n = sizeof(arr)/sizeof(arr[0]);
  //pair<int,int> res = maxProductPair(arr,n);
  pair<int,int> res = maxProductPair2(arr,n);
  //printf("pair is (%d, %d) and the product is: %d \n",arr[res.first],arr[res.second],arr[res.first]*arr[res.second]);
  printf("pair is (%d, %d) and the product is: %d \n",res.first,res.second,res.first*res.second);
  return 0;
}
