#include<iostream>
#include<algorithm>
using namespace std;

void rearrangeArray(int *arr,int n){
  std::sort(arr,arr+n);
  int *arr1 = (int*) malloc(sizeof(int)*n);
  int low=0,high=n-1,i=0;
  while(low<high){
    arr1[i++] = arr[low++];
    arr1[i++] = arr[high--];
  }
  printf("rearranged array:\n");
  for(i=0;i<n;i++)
    printf("%d ",arr1[i]);
}

void swap(int &a,int &b){
  int temp=a;
  a=b;
  b=temp; 
}

void rearrangeArray1(int *arr,int n){
  for(int i= 1; i<n-1; i+=2){
    if(arr[i] < arr[i-1])
      swap(arr[i],arr[i-1]);
    if(arr[i]< arr[i+1])
      swap(arr[i],arr[i+1]);
  }
  printf("rearranged array:\n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

int main(){
  int arr[]={2,5,1,6,7,3,9,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  rearrangeArray(arr,n);
  rearrangeArray1(arr,n);
}
