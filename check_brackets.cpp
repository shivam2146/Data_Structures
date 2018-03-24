#include<iostream>
#include <stack>
using namespace std;

bool check_brackets(char* arr,int n){
    stack<char> st;
    char c;
    for(int i=0;i<n;i++){
      if(arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        st.push(arr[i]);
      else{
          if(st.empty())
            return false;
          c= st.top();
          st.pop();
          if(c == '{' && arr[i] != '}')
            return false;
          if(c == '[' && arr[i] != ']')
            return false;
          if(c == '(' && arr[i] != ')')
            return false;
      }
    }
    if(st.empty())
      return true;
    else
      return false;
}

int main(){
  char arr[] = {'(','{','[',']','}',')','(',')'};
  cout<<check_brackets(arr,8);
}
