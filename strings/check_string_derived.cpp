#include<iostream>
#include<algorithm>
using namespace std;

bool checkStringDerived(string s, string d){
  s = s+s;
  for(int i=0;i<s.length()-d.length();i++){
    if(s.substr(i,d.length()) == d )
      return true;
  }
  return false;
}

bool check(string s,string d){
  if(s.length() != d.length())
    return false;
  for(int i=0;i<s.length();i++){
    rotate(s.begin(),s.begin()+1,s.end());
  //right rotation
  //  rotate(s.rbegin(),s.rbegin()+1,s.rend());
    if(!s.compare(d))
      return true;
  }
  return false;
}

int main(){
  string s= "ABCD";
  string d= "DABC";
  if(checkStringDerived(s,d))
    cout<<"can be derived";
  else
    cout<<"cannot be derived";
  if(check(s,d))
    cout<<"\ncan be derived";
  else
    cout<<"\ncannot be derived";
  return 0;
}
