#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , x;
    scanf ("%d %d", &n , &x );
    int arr[n];
    int skip=0,count=0;
    for (int i = 0;i < n;i++){
        scanf ("%d",&arr[i]);
        if (skip == 0 && arr[i] > x)
            skip++;
        else if (skip == 1 && arr[i] > x )
            skip++;
        if (arr[i] <= x && skip < 2 ) 
            count++;
    }
    cout<<count;
}
