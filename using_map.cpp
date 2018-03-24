#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector<string> vec(n);
    map<string,int> m;
    for(int i=0; i<n;i++){
        cin>>vec[i];
        m[vec[i]]++;
    }
    int q;
    cin>>q;
    string s;
    int count=0;
    for(int i=0;i<q;i++){
        cin>>s;
        //for(int j=0;j<n;j++)
        //    if(s.compare(vec[j])==0)
        //        count++;
        //cout<<count<<"\n";
        //count = 0;
        cout<<m[s]<<"\n";
    }
    return 0;
}
