#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],m,i,f[n]={0},g[n]={0},t,M,A;
    cin>>a[0];
    m=a[0];
    if(m>=0)
        ++f[m];
    else
        ++g[abs(m)];
    
    for(i=1;i<n;i++){
        cin>>a[i];
        t=a[i];
        if(t>=0)
            ++f[t];
        else
            ++g[abs(t)];
        if(m>=0)
            M=f[m];
        else
            M=g[abs(m)];
        if(t>=0)
            A=f[t];
        else
            A=g[abs(t)];
        if(A>M)
            m=t;
        else if(A==M)
            if(t<m)
                m=t;
    }
    cout<<m;
    
}
