#include<bits/stdc++.h>
using namespace std;

struct Stack{
  int *arr;
  int top;
  int capacity;
};

Stack* CreateStack(){
  Stack *s = new Stack();
  s -> arr = new int[1];
  s -> top = -1;
  s -> capacity = 1;
  return s;
}

bool isStackFull(Stack *s){
  if(s->top == s->capacity-1)
    return true;
  else
    return false;
}

bool isStackEmpty(Stack *s){
  if(s->top == -1)
    return true;
  else
    return false;
}
void DoubleStack(Stack *s){
  int *arr1 = new int[2*s->capacity];
  s->capacity *=2;
  for(int i=0;i<=s->top;i++)
    arr1[i] = s->arr[i];
  delete[] s->arr;

  s->arr  = arr1;
  arr1 = NULL;
}

void push(Stack *s, int ele){
  if(isStackFull(s))
    DoubleStack(s);
  s->arr[++s->top] = ele;

}

int pop(Stack *s){
  if(isStackEmpty(s))
    return INT_MIN;
  return s->arr[s->top--];
}

int Top(Stack *s){
  if(isStackEmpty(s))
    return INT_MIN;
  return s->arr[s->top];
}

int main(){
  Stack *s = CreateStack();
  cout<<isStackEmpty(s);
  push(s,25);
  push(s,30);
  push(s,35);
  cout<<s->capacity;
  cout<<Top(s);
  cout<<pop(s);
  cout<<pop(s);
  cout<<pop(s);
  cout<<pop(s);
  cout<<pop(s);
  delete s;
}
