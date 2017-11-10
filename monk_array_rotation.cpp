#include<cstdio>
using namespace std;
int main(){
	int testCases;
	scanf("%d",&testCases);
	while (testCases){
		int n,shift;
		scanf("%d %d",&n,&shift);
		int arr[n];
		shift= shift % n;
		for(int i=shift;i<n;i++)
			scanf("%d",&arr[i]);
		for(int j = 0;j < shift;j++)
			scanf("%d",&arr[j]);
		for(int k=0;k < n;k++)
			printf("%d ",arr[k]);
		printf("\n");
		testCases--;
	}
}

