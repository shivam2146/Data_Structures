#include<iostream>
using namespace std;

template <typename T>
struct node{
  T data;
  node *next;
};

template <typename T>
class LinkedList{
  node<T> *head;
public:
  LinkedList(){
    head = NULL;
  }
  void insertAtHead(int);
  void insertAtTail(int);
  void print();
};

template <typename T>
void LinkedList<T>::insertAtHead(int key){
  node<T>*temp = new node<T>;
  temp->data = key;
  if(!head){
    temp->next = NULL;
    head = temp;
    temp = NULL;
    return;
  }
  temp->next = head;
  head = temp;
  temp = NULL;
}

template<typename T>
void LinkedList<T>::insertAtTail(int key){
  node<T> *temp = new node<T>;
  temp->data = key;
  temp->next = NULL;
  if(!head){
    head = temp;
    temp = NULL;
    return;
  }
  node<T> *t = head;
  for(;t->next!=NULL;t= t->next);
  t->next = temp;
  temp = NULL;
}

template<typename T>
void LinkedList<T>::print(){

  node<T> *temp = head;
  cout<<"\ncontent of linked list: ";
  for(;temp!=NULL;temp= temp->next)
      cout<<temp->data<<" ";
}

int main(){
  LinkedList<int> l;
  l.insertAtHead(1);
  l.insertAtHead(10);
  l.insertAtTail(5);
  l.insertAtHead(12);
  l.insertAtTail(13);
  l.insertAtHead(63);
  l.insertAtHead(8);
  l.print();
  return 0;
}
