#include<iostream>
#include<stack>
using namespace std;

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
bool isoperand(char c){
  if((c>='A' && c<='Z') || (c>='a'&& c<='z'))
    return true;
  else
    return false;
}
void infix_to_postfix(char *c,int n){
  stack<char> s;
  for(int i=0;i<n;i++)
  {
    if(isoperand(c[i]))
      printf("%c",c[i]);
    else if(c[i] == ')'){
      while( !s.empty() && s.top() != '(' ){
        cout<<s.top();
        s.pop();
      }
      if(!s.empty())
      s.pop();
    }
    else if(c[i] == '(')
      s.push(c[i]);
    else{
      while(!s.empty() && Prec(s.top()) >= Prec(c[i]) ){
        cout<<s.top();
        s.pop();
      }
      s.push(c[i]);
    }

  }
  while(!s.empty()){
    cout<<s.top();
    s.pop();
  }
}

int main(){
  char ch[] = {'(','A','+','B',')','*','C','-','D'};
  //infix_to_postfix(ch,9);
  char ch1[] = {'A','*','B','-','(','C','+','D',')','+','E'};
  infix_to_postfix(ch1,11);
}
