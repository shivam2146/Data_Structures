#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,q,m,n1,c,t1,t2,s;
    string s1,s2;
    scanf("%d",&n);
    char str[n];
    for(int i=0;i<n;i++)
        cin>>str[i];
   
    scanf("%d",&q);
     
    for(int i=0;i<q;i++){
        scanf("%d %d",&m,&n1);    
        c=0;
        //cout<<"for i"<<q<<endl;
        for(int k=m;k<=n1;k++){
            if(k-1 !=0)
                s1= string(str).substr(0,k-1);
            else
                s1="0";
            if(k != n)
                s2= string(str).substr(k);
            else 
                s2="0";
            cout<<"for j"<<q<<s1<<s2<<endl;
            t1= stoi(s1);
            cout<<"for j"<<q<<endl;
            t2= stoi(s2);
            cout<<"for j"<<q<<endl;
            s= t1 + t2;
            cout<<"for j"<<q<<endl;
            if(s%2==0 && s%3==0 && s%5==0)
                c++;
            cout<<c;
        }
       printf("%d\n",c);
        
    }
}
