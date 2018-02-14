#include<bits/stdc++.h>
using namespace std;

class DyStack{
  vector<int> vec;
  int top;
  int capacity;
public:
  DyStack(){
    vec.resize(1);
    capacity = 1;
    top= -1;
  }
  void push(int ele);
  int pop();
  int topele();
  bool isStackEmpty();
  bool isStackFull();
  void growStack();   //doubles the size of stack
  void deleteStack();
  int size(){
    return top+1;
  }
};
void DyStack::push(int ele){
  if(isStackFull())
    cout<<"\nstack overflow : use growStack funcn to inc size of stack";
  else{
    vec[++top]= ele;
  }
}
int DyStack::topele(){
  if(isStackEmpty())
    return INT_MIN;
  return vec[top];
}
int DyStack::pop(){
  if(isStackEmpty())
    return INT_MIN;
  return vec[top--];
}
void DyStack::growStack(){
  vec.resize(capacity*2);
  capacity *= 2;
}
bool DyStack::isStackFull(){
  if(top ==capacity-1)
    return true;
  else
    return false;
}
bool DyStack::isStackEmpty(){
  if(top == -1)
    return true;
  else
    return false;
}

int main(){
  DyStack st;
  cout<<"top element: "<<st.topele();
  cout<<"\nsize of stack: "<<st.size();
  st.push(25);
  cout<<"\n top element : "<<st.topele();
  st.push(30);
  st.growStack();
  cout<<"\nsize of stack: "<<st.size();
  st.push(60);
  st.push(10);
  st.growStack();
  cout<<"\nsize of stack: "<<st.size();
  cout<<"\npopped element "<<st.pop();
  cout<<"\nsize of stack: "<<st.size();
  cout<<"\n top element : "<<st.topele();
  cout<<"\n popped element: "<<st.pop();
  cout<<"\nsize of stack: "<<st.size();
  cout<<"\n popped element: "<<st.pop();
}
