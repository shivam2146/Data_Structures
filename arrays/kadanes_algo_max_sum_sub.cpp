#include<iostream>
using namespace std;

int max(int a, int b){
  return(a>b?a:b);
}

int kadanesMaxSumSubArray(int *a,int n){
  int max_sum_here, max_so_far;
  max_sum_here = max_so_far = a[0];
  for(int i=1; i<n ; i++){
    max_sum_here += a[i];
    max_sum_here = max(max_sum_here,a[i]);
    max_so_far = max(max_so_far,max_sum_here);
  }
  return max_so_far;
}

int main(){
  int arr[] = {-8,-3,6,2,-5,-4};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"max sum is :"<<kadanesMaxSumSubArray(arr,n);
  return 0;
}
