#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while (t > 0){
    int n,count=1;
    cin >> n;
    int arr[n];
    cin >> arr[0];
    int min=arr[0];
    for (int i = 1;i < n;i++){
	 cin >> arr[i];
	 if (arr[i] <= min){
	 	count++;
	 	min=arr[i];
	 }
	 
	}
	cout<<count<<"\n";
	t--;
	
  }
  return 0;
}
