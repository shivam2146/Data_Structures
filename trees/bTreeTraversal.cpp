#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template <typename T>
struct node{
  T data;
  node *left;
  node *right;
};

template <typename T>
class BTree{
  node <T>*root;
  void preorder(node <T>*temp);
  void inorder(node<T> *temp);
  void postorder(node<T>*temp);
  bool insert(node <T>*temp,node <T>*data);
public:
  BTree(){
    root = NULL;
  }
  void preorder();
  void iPreorder();
  void insert(T data);
  void inorder();
  void iInorder();
  void postorder();
  void iPostorder();
  void levelOrder();
};

template <typename T>
void BTree<T>::inorder(){
    printf("\nInorder traversal of tree:  ");
    inorder(root);
}

template <typename T>
void BTree<T>::inorder(node<T> *temp){
  if(!temp)
    return;
  inorder(temp->left);
  cout<<temp->data<<" ";
  inorder(temp->right);
}

template <typename T>
void BTree<T>::iInorder(){
  printf("\nInorder traversal of tree:  ");
  stack<node<T>*> st;
  node<T> *temp = root;
      while(1){
        while(temp){
          st.push(temp);
          temp = temp->left;
        }
        if(st.empty())
          break;
        temp= st.top();
        st.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
      }
}

template <typename T>
void BTree<T>::preorder(){
  printf("\nPreorder Traversal of Tree:  ");
  preorder(root);
}

template <typename T>
void BTree<T>::preorder(node <T>*temp){
  if(!temp)
    return;
  cout<<temp->data<<" ";
  preorder(temp->left);
  preorder(temp->right);
}

template <typename T>
void BTree<T>::iPreorder(){
  stack<node<T>*> st;
  st.push(root);
  node <T>*temp;
  cout<<"\nPreorder traversal of tree:  ";
  while(!st.empty()){
      temp = st.top();
      st.pop();
      cout<<temp->data<<" ";
      if(temp->right)
        st.push(temp->right);
      if(temp->left)
        st.push(temp->left);
    }
}

template <typename T>
void BTree<T>::postorder(){
  printf("\nPostorder Traversal of Tree:  ");
  postorder(root);
}

template <typename T>
void BTree<T>::postorder(node<T>*temp){
  if(!temp)
    return;
  postorder(temp->left);
  postorder(temp->right);
  cout<<temp->data<<" ";
}

template <typename T>
void BTree<T>::iPostorder(){
    printf("\nPostorder Traversal of Tree:  ");
    stack<node<T>*> st;
    node <T> *prev = NULL;
    node <T> *curr = root;
    do{
      while(curr != NULL){
        st.push(curr);
        curr = curr->left;
      }
      while(curr == NULL && !st.empty()){
        curr = st.top();
        if(curr->right == NULL || curr->right == prev){
          st.pop();
          cout<<curr->data<<" ";
          prev = curr;
          curr = NULL;
        }else{
          curr = curr->right;
        }
      }
    }while(!st.empty());
}

template <typename T>
void BTree<T>::levelOrder(){
  queue<node<T>*> q;
  q.push(root);
  cout<<"\nLevel order Traversal: ";
  while(!q.empty()){
    node<T> *temp = q.front();
    cout<<temp->data<<" ";
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
    q.pop();
  }
}

template <typename T>
void BTree<T>::insert(T data){
    cout<<"\ninserting element "<<data;
    node <T> *d = new node<T>;
    d->data = data;
    d->left = NULL;
    d->right = NULL;
    if(!root){
        root = d;
        return;
    }
    queue<node<T>*> q;
    q.push(root);
    while(!q.empty()){
      node<T> *temp = q.front();
      if(temp->left)
        q.push(temp->left);
      else{
        temp->left = d;
        break;
      }
      if(temp->right)
        q.push(temp->right);
      else{
        temp->right = d;
        break;
      }
      q.pop();
    }
    q = queue<node<T>*>();
}



int main(){
  BTree<int> t;
  t.insert(5);
  t.insert(6);
  t.insert(3);
  t.insert(8);
  t.insert(9);
  t.insert(2);
  t.insert(7);
  t.levelOrder();
  t.preorder();
  t.iPreorder();
  t.inorder();
  t.iInorder();
  t.postorder();
  t.iPostorder();
  return 0;
}
