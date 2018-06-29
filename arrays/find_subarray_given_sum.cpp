#include<iostream>
using namespace std;

//sliding window
void subArrayGivenSum(int *arr,int n,int sum){
  int winSum=0,winEnd=0;
  for(int i=0 ;i<n; i++){
    while(winSum <= sum && winEnd < n)
      winSum += arr[winEnd++];
    if(winSum == sum){
      printf("sub array with given sum is: %d,%d",i,winEnd-1);
      return;
    }
    else
      winSum -= arr[i];
  }
}

int main(){
  int arr[]= {2,6,0,9,7,3,1,4,1,10};
  int size= sizeof(arr)/sizeof(arr[0]);
  int sum = 15;
  subArrayGivenSum(arr,size,sum);
  return 0;
}
