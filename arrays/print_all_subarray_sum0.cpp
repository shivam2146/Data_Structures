#include<iostream>
#include<unordered_map>

using namespace std;

void print_subarray(int arr[],int n){
	unordered_multimap<int,int> map;
	map.insert(pair<int,int>(0,-1));
  int sum=0;
  for(int i=0; i< n ; i++){
    sum+= arr[i];
    if(map.find(sum) != map.end()){
      auto it = map.find(sum);
      while(it != map.end() && it->first == sum){
        printf("subarray [%d....%d] with sum 0\n",it->second+1,i);
        it++;
      }
    }
      map.insert(pair<int,int>(sum,i));
  }
}
void test(){
  unordered_multimap<int,int> map;
  map.insert(pair<int,int>(2,5));
  map.insert(pair<int,int>(3,10));
  map.insert(pair<int,int>(4,11));
  map.insert(pair<int,int>(3,11));
  map.insert(pair<int,int>(2,42));
  map.insert(pair<int,int>(4,12));
  map.insert(pair<int,int>(1,11));
  auto it = map.find(2);
  while(it!= map.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
  }
}

int main(){
  int arr[] = { 3,4,-7,3,1,3,1,-4,-2,-2 };
  int n = sizeof(arr) / sizeof(arr[0]);
  //print_subarray(arr,n);
  test();
}
