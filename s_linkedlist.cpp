#include<iostream>
#include "basic.h"
using namespace std;

class ListEle{
  private:
    int data;
    ListEle *next;
  public:
    ListEle(int val):  next(NULL), data(val){}    //use of initializer list to initialize class
    ~ListEle(){}
    ListEle* getNext(){ return next; }
    int getValue(){  return data; }
    void setNext(ListEle *p){ next = p; }
    void setVal(int &val){ data = val; }
};
  class LinkedList{
  ListEle *head;
  public:
    LinkedList(): head(NULL){}
    ~LinkedList(){}
    void traverse();
    void insert_at_head(int ele);
    void insert_at(int el,int pos);
    int delete_at(int pos);
};
void LinkedList::traverse(){
    if(head == NULL)
    {
      cout<<"List is empty";
      return ;
    }
    ListEle *temp = head;
    printf("\nContent of the list:");
    while(temp != NULL){
      //cout<<"  "<<temp->getNext();
      printf("%d ",temp->getValue());
      temp = temp->getNext();
    }
    delete temp;
  }
void LinkedList::insert_at_head(int ele){
  ListEle *node= new ListEle(ele);
  if(head== NULL){
    head = node;
  }
  else{
    node->setNext(head);
    head = node;
  }
  node = NULL;
  delete node;
}
void LinkedList::insert_at(int ele, int pos){
  if(pos ==  1){
    insert_at_head(ele);
    return;
  }
  ListEle *temp;
  temp = head;
  int k=1;

  while(k+1!= pos && temp != NULL){
      temp= temp->getNext();
      k++;
  }
  if(temp == NULL){
    printf("Invalid position");
  }
  else{
    ListEle *node = new ListEle(ele);
    node->setNext(temp->getNext());
    temp->setNext(node);
  }
  temp = NULL;
  delete temp;
}
int LinkedList::delete_at(int pos){

  if(head == NULL){
      cout<<"underflow";
      return -1;
    }
  if(pos == 1){
    ListEle *temp = head;
    head= head->getNext();
    int t = temp->getValue();
    temp->setNext(NULL);
    delete temp;
    return t;
  }else{
    ListEle *temp = head;
    int c = 1;
    while(c+1 != pos && temp != NULL){
      temp= temp->getNext();
      c++;
    }
    if(temp == NULL || temp->getNext()==NULL){
      printf("\nInvalid position: ");
      return -1;
    }else{
      ListEle *d = temp->getNext();
      temp->setNext(temp->getNext()->getNext());
      temp = NULL;
      int t= d->getValue();
      delete d;
      delete temp;
      return t;
    }
  }
}
int main(){
  LinkedList l;
  l.insert_at_head(51);
  l.insert_at_head(25);
  l.insert_at(36,1);
  l.insert_at(35,2);
  l.insert_at(95,5);
  l.traverse();
  cout<<"\ndeleted at 5: "<<l.delete_at(5);
  l.traverse();
  cout<<"\ndeleted at 1 : "<<l.delete_at(1);
  l.traverse();

}
