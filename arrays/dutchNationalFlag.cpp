#include<iostream>
using namespace std;

void swap(int &a,int &b){
  int temp=a;
  a=b;
  b=temp;
}

void sort1(int *arr, int n){
  int count[3] = {0};
  int output[n];
  for(int i=0; i<n ; i++){
    count[arr[i]]++;
  }
  for(int j=1;j<3;j++)
    count[j] += count[j-1];
  for(int i = 0 ; i<n ; i++){
    output[count[arr[i]]-1]= arr[i];
    count[arr[i]]--;
  }
  for(int j=0 ; j<n ; j++){
     arr[j] = output[j];
     cout<<output[j];
   }
}

void threeWayPartition(int *arr,int end){
  int first=0,i=0,last = end-1;
  int pivot = 1;
  while(i<=last){
    if(arr[i] < pivot){
        swap(arr[i],arr[first]);
        ++i;
        ++first;
    }
    else if(arr[i]>pivot){
      swap(arr[i],arr[last]);
      --last;
    }
    else{
      ++i;
    }
  }
}
int main(){
  int arr[] = {0,1,2,2,1,0,0,2,0,1,1,0};
  int n= sizeof(arr)/sizeof(arr[0]);
  //sort1(arr,n);
  threeWayPartition(arr,n);
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);

}
