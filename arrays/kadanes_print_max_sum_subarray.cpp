#include<iostream>
#include<utility>
using namespace std;

int max(int a, int b){
  return(a>b?a:b);
}

pair<int,int> kadanesMaxSumSubArray(int *a,int n){
  int max_sum_here, max_so_far,beg=0;
  pair<int,int> p (0,0);
  max_sum_here = max_so_far = 0;
  for(int i=0; i<n ; i++){
    max_sum_here += a[i];
    if(max_sum_here < 0){
      max_sum_here = 0;
      beg = i+1;
    }
    if(max_so_far < max_sum_here){
      max_so_far = max_sum_here;
      p.second = i;
      p.first = beg;
    }
}
  return p;
}

//for all negatives
pair<int,int> kadanesMaxSumSubArray2(int *a,int n){
  int max_sum_here, max_so_far,beg=0;
  pair<int,int> p (0,0);
  max_sum_here = max_so_far = a[0];
  for(int i=1; i<n ; i++){
    max_sum_here += a[i];
    if(max_sum_here < a[i]){
      max_sum_here = a[i];
      beg = i;
    }
    if(max_so_far < max_sum_here){
      max_so_far = max_sum_here;
      p.second = i;
      p.first = beg;
    }
}
  return p;
}


int main(){
  int arr[] = {-8,-3,-6,-2,-5,-4};
  int n = sizeof(arr)/sizeof(arr[0]);
  pair<int,int> p = kadanesMaxSumSubArray2(arr,n);
  cout<<"max sum is :"<<p.first<<"   "<<p.second;
  return 0;
}
