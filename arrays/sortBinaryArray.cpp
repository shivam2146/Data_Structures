#include<iostream>
using namespace std;

void sortBinary(int *arr,int n){
    int count =0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0)
          count++;
    }
    for(int i=0;i<n;i++)
      if(i<count)
        arr[i] = 0;
      else
        arr[i] = 1;
}

void sortBinary1(int *arr,int n){
  int k=0;
  for(int i=0;i<n;i++){
    if(arr[i]==0)
      arr[k++] = 0;
  }
  for(int i=k;i<n;i++)
    arr[i] = 1;
}

int main(){
  int a[] = {1,0,1,0,0,0,1,1,0,0,1};
  int n= sizeof(a)/sizeof(a[0]);
  sortBinary1(a,n);
  printf("rearranged array:\n");
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
