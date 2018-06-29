#include<iostream>
#include<limits.h>
using namespace std;

//using sliding window tech
void minSumSubArray(int arr[],int n,int k){
  int index = 0, minSum = INT_MAX, winSum = 0;
  for(int i=0; i<n ; i++){
    winSum += arr[i];
    if(i+1 >= k){
      if(minSum > winSum){
        minSum = winSum;
        index = i;
      }
      winSum -= arr[i-k+1];
    }
  }
  printf("min sum subarray is %d,%d with sum: %d",index-k+1,index,minSum);
}

int main(){
  int arr[] = {10,4,2,5,6,3,8,1};
  int size = sizeof(arr)/sizeof(arr[0]);
  int k = 3;
  minSumSubArray(arr,size,k);
  return 1;
}
