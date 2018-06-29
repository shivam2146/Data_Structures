#include<iostream>
#include<unordered_map>
using namespace std;

bool isPalindrome(string s,int low,int high){
  if(low >= high)
    return true;
  return (s[low] == s[high]) && isPalindrome(s,low+1,high-1);
}

bool isRepeatedSubSeq(string s){
  unordered_map<char,int> map;
  for(int i=0; i < s.length(); i++)
    if(++map[s[i]] >= 3)
      return true;
  string temp;
  for(int i=0;i<s.length();i++)
    if(map[s[i]] >= 2)
      temp += s[i];

  return !isPalindrome(temp,0,temp.length()-1);
}

int main(){
    string  s="XYBYAXB";
  if(isRepeatedSubSeq(s))
    cout<<"rep subseq present";
  else
    cout<<"rep subseq not present";
  return 1;
}
