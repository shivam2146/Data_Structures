#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *prev;
};

class Stack_LL{
  node *top;
  int size;
public:
  Stack_LL(){
    top = NULL;
    size =0;
  }
  Stack_LL(int ele){
    top = new node();
    top->data = ele;
    top->prev = NULL;
    size =1;
  }
  int top_ele();
  void push(int ele);
  bool isStackEmpty();
  int pop();
  int cap(){
    return size;
  }
};

bool Stack_LL::isStackEmpty(){
    if(top == NULL)
      return true;
    else
      return false;
}

int Stack_LL::top_ele(){
  if(isStackEmpty())
    return INT_MIN;
  else
    return top->data;
}
void Stack_LL::push(int ele){
  if(isStackEmpty()){
    top = new node();
    top->data = ele;
    top->prev = NULL;
  }
  else{
    node *temp = new node();
    temp -> data = ele;
    temp -> prev = top;
    top = temp;
    temp = NULL;
    delete(temp);
  }
  size +=1;
}

int Stack_LL::pop(){
  if(isStackEmpty())
    return INT_MIN;
  size -= 1;
  node *temp = top;
  top = top->prev;
  int ele = temp->data;
  temp -> prev = NULL;
  delete(temp);
  return ele;
}

int main(){
  Stack_LL s(20);
  cout<< s.isStackEmpty()<<"\n";
  cout<<s.top_ele()<<"\n";
  s.push(30);
  s.push(40);
  cout<<s.top_ele()<<"\n";
  cout<<s.cap()<<"\n";
  cout<<s.pop()<<"\n";
  s.pop();
  s.pop();
  cout<<s.isStackEmpty()<<"\n";
  cout<<s.cap()<<"\n";
}
