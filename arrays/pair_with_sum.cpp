#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

//using sorting to find pair in O(nlogn)
void pairSum(int *arr, int n,int sum){
  sort(arr,arr+n);
  int high = n-1 , low = 0;
  while(low<high){
      if(arr[low]+arr[high] == sum ){
        printf("pair found\n");
        return;
      }
      else if(arr[low]+arr[high] > sum)
        high--;
      else
        low++;
  }
  printf("pair not found\n");
}

//using hashing to solve in O(n) and prints all indices where pair occur
void pairSumHash(int *arr, int n, int sum){
  std::unordered_map<int,int> map;
  int flag=0;
  for(int i=0;i<n;i++){
    if(map.find(sum-arr[i]) != map.end()){
      printf("pair found at index %d and %d\n",map[sum-arr[i]],i);
      flag=1;
    }
    else
      map[arr[i]] = i;
  }
  if(flag==0)
    printf("pair not found\n");
}

int main(){
  int arr[] = {1,8,2,3,4,5,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  //pairSum(arr,n,14);
  pairSumHash(arr,n,9);
  return 0;
}
