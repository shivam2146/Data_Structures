#include<iostream>
#include<unordered_set>
using namespace std;

void check(int arr[], int n){
  unordered_set<int> set;
  set.insert(0);
  int sum = 0;
  for(int i=0;i<n;i++){
    sum+= arr[i];
    if(set.find(sum) != set.end()){
      printf("subarray exists");
      return;
    }
    else
      set.insert(sum);
  }
  printf("subarray does not exists");
}

int main(){
  int arr[] = { 2,-7,4,3,1,3,1,-4,-2,-2 };
  int n = sizeof(arr) / sizeof(arr[0]);
  check(arr,n);
}
