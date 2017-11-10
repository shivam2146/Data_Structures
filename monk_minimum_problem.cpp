//#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	int testCases,n;
	scanf("%d",&testCases);
	while (testCases > 0){
		int min,count=1;
		int n;
		scanf ("%d",&n);
		int arr[n];
		scanf ("%d",&arr[0]);
		min=arr[0];
		for (int i=1;i<n;i++){
			scanf("%d",&arr[i]);
			if(arr[i]<min){
				count = 1;
				min = arr[i];
			}
			else if(arr[i]==min)
				count++;
		}
		if (count % 2 == 0)
		    printf("Unlucky\n");
		else
		    printf("Lucky\n");
		testCases--;
	}
	
}
