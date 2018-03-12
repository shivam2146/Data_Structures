#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q;
    cin>>n>>q;
    int q1,x,y,t,k,lans=0;
    vector<vector<int>> arr(n,vector<int>(0));
    for(int i=0;i<q;i++){
        cin>>q1>>x>>y;
        if(q1==1){
             t= (x^lans)%n;
            arr[t].push_back(y);
        }
        else if(q1==2){
            t= (x^lans)%n;
            k= y%arr[t].size();
            lans = arr[t][k];
            cout<<lans<<"\n";
        }
    }
    return 0;
}
