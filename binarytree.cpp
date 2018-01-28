#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
struct node{
  int data;
  node *left;
  node *right;
};
int max(int a, int b)
{
  return (a >= b)? a: b;
}
class BinaryTree{
    node *root;
    void preorder(node *t);
    void inorder(node *t);
    void postorder(node *t);
    int maximum(node *t);
    int search(node *t, int ele);
    int size(node *t);
    void delete_n(node *t);
    int height(node *t);
    int diameter(node *t);

   /////////////public funcs //////////////////

    public:
    BinaryTree(): root(NULL){}
    ~BinaryTree(){}
    node* deepest_node();
    void rpreorder(){
        node *t = root;
        if(!root)
        return;
        cout<<"\npreorder travesal of tree: ";
        preorder(t);
        t = NULL;
    }
     void rinorder(){
       if(!root)
         return;
       cout<<"\ninorder travesal of tree: ";
       node *t = root;
       inorder(t);
       t = NULL;
     }
     void rpostorder(){
       if(!root)
         return;
       cout<<"\npostorder travesal of tree: ";
       node *t= root;
       postorder(t);
       t = NULL;
     }
     void bfs();
     void i_preorder();
     void i_inorder();
     void i_postorder();
     void insert(int ele);
     int rheight(){
       if (!root)
        return 0;
       else
        return height(root);
     }
     void rdelete(){
       if(!root)
        return ;
        delete_n(root);
     }
     int rsize(){
       if(!root)
        return 0;
      return size(root);
     }
     int rmax(){
       if(!root)
         return -1;
       return maximum(root);
     }
     int rsearch(int ele){
       if(!root)
         return -1;
       return search(root,ele);
     }
     void rev_levelorder();
     void delete_ele(int ele);
     int rdiameter(){
       if(!root)
        return 0;
       else{
         node *temp = root;
         return diameter(temp);
      }
     }
};
void BinaryTree::delete_ele(int ele){
  node *temp = root, *del;
  node *deep = deepest_node();
  queue<node *> q;
  q.push(temp);
  while(!q.empty()){
    temp = q.front();
    if(temp->data == ele){
      del = temp;
    }
    if(temp-> left == deep){
      temp->left = NULL;
    }
    else if(temp->right == deep){
      temp->right = NULL;
    }
    if(temp->left != NULL)
      q.push(temp->left);
    if(temp->right != NULL)
      q.push(temp->right);
    q.pop();
  }
  if(del == NULL) {
    cout<<"node with given data already doesn't exist";
    return;
  }
  cout<<"\nnode with data " <<del->data <<" deleted";
  del-> data = deep->data;
  delete deep;
}
node* BinaryTree::deepest_node(){
      queue<node*> q;
      node *temp;
      if(!root)
        return NULL;
      q.push(root);
      while(!q.empty()){
        temp = q.front();
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
        q.pop();
      }
      return temp;
}
int BinaryTree::height(node *t){
  if(t == NULL)
    return 0;
  else{
    int l = height(t->left);
    int h= height(t->right);
     return (l>h)? l+1 : h+1;
  }
}
int BinaryTree::diameter(node *t){
    if(!t)
      return 0;
    //height of left and right subtree
    int lheight= height(t->left);
    int rheight= height(t->right);

    //diameter of left and right subtree
    int ldiameter= diameter(t->left);
    int rdiameter= diameter(t->right);

    return max(lheight+rheight, max(ldiameter,rdiameter));
}
void BinaryTree::delete_n(node *t){
    if(t == NULL)
      return;
    else{
      delete_n(t->left);
      delete_n(t->right);
      if(t == root)             //this is to make root null so root doesn't points to a garbage location
        root = NULL;
      delete t;
    }
}
void BinaryTree::rev_levelorder(){
    queue<node *> q;
    stack<node *>s;
    node *temp= root;
    q.push(temp);
    cout<<"\nrev level order traversal : ";
    while(!q.empty()){
      temp = q.front();
      s.push(temp);
      if(temp->right != NULL)
        q.push(temp->right);
      if(temp->left != NULL)
        q.push(temp->left);
      q.pop();
    }
    while(!s.empty())
      {
        temp= s.top();
        cout<<temp->data<<" ";
        s.pop();
      }
    temp = NULL;
}
int BinaryTree::size(node *t){
  if(t == NULL)
    return 0;
  else
    return size(t->left)+ 1 + size(t->right);
}
int BinaryTree::search(node *t,int ele){
  if(t == NULL)
    return 0;
  else{
    if(t->data == ele)
      return 1;
    if(search(t->left,ele) == 1)
      return 1;
    else return search(t->right,ele);
  }
}
void BinaryTree::preorder(node *t){
  if(t != NULL){
    cout<<t->data<<" ";
    preorder(t->left);
    preorder(t->right);
  }
}
void BinaryTree::inorder(node *t){
  if(t!= NULL){
    inorder(t->left);
    cout<<t->data<<" ";
    inorder(t->right);
  }
}
void BinaryTree::postorder(node *t){
  if(t!=NULL){
    postorder(t->left);
    postorder(t->right);
    cout<<t->data<<" ";
  }
}
void BinaryTree::bfs(){
  queue <node*> q;
  node *l, *r, *temp;
  if(!root)
    return;
  q.push(root);
  cout<<"\nbfs travesal of tree: ";
  while(!q.empty()){
    temp = q.front();
    cout<<temp->data<<" ";
    r= temp->right;
    l= temp->left;
    q.pop();
    if (l)
      q.push(l);
    if (r)
      q.push(r);
  }
  l=r=temp= NULL;
}
void BinaryTree::i_preorder(){
  node *l, *r;
  if(!root)
    return;
  cout<<"\npreorder travesal of tree";
  stack <node*> s;
  node *temp;
  s.push(root);
  while(!s.empty()){
    temp = s.top();
    l= temp->left;
    r= temp->right;
    cout<<temp->data<<" ";
    s.pop();
    if(r)
      s.push(r);
    if(l)
      s.push(l);
  }
  temp=l=r=NULL;
}
void BinaryTree::i_inorder(){
  node *temp;
  if(!root)
    return;
  cout<<"\ninorder traversal: ";
  stack <node*> s;
  temp= root;
  while(1){
    while(temp){
      s.push(temp);
      temp=temp->left;
    }
    if(s.empty())
      break;
    temp= s.top();
    cout<<temp->data<<" ";
    temp= temp->right;
    s.pop();
  }
  temp= NULL;
}
void BinaryTree::i_postorder(){
  node *temp= root, *prev=NULL;
  stack<node*> s;
  cout<<"\nPost order traversal: ";
  do{
        while(temp){
          s.push(temp);
          temp=temp->left;
        }
        while(temp == NULL && !s.empty()){
          temp = s.top();
          if(temp->right == NULL || prev == temp->right ){
            cout<<temp->data<<" ";
            prev= temp;
            temp= NULL;
            s.pop();
          }else{
            temp= temp->right;
          }
        }
      }while(!s.empty());
}
void BinaryTree::insert(int ele){
  node *d= new node;
  d->data = ele; d->left = NULL; d->right = NULL;
  queue <node*> q;
  node *l, *r,*temp;
  if(!root){
    root = d;
    d= NULL;
    return;
  }
  q.push(root);
  while(!q.empty()){
    temp = q.front();
    l = temp->left;
    r = temp->right;
    if(l){
      q.pop();
      q.push(l);
    }
    else{
      temp->left= d;
      break;
    }
    if (r){
      q.push(r);
    }
    else{
      temp->right = d;
      break;
    }
  }
  d =temp=l=r= NULL;
}
int BinaryTree::maximum(node *t){
  if(t->left==NULL && t->right == NULL)
    return t->data;
  else{
    int l,r,m;
    l= maximum(t->left);
    r=maximum(t->right);
    m = l;
    if(m < r)
      m = r;
    if(m < t->data)
      m= t->data;
    return m;
  }
}
int main(){
  BinaryTree t;
  t.insert(1);
  t.insert(2);
  t.insert(3);
  t.insert(4);
  t.insert(5);
  //t.insert(6);
  //t.insert(7);
  t.bfs();
  t.rpreorder();
  t.rinorder();
  t.rpostorder();
  t.i_preorder();
  t.i_inorder();
  t.i_postorder();
  t.rev_levelorder();
  cout<<"\nsearch for 9 returned: "<<t.rsearch(9);
  cout << "\nMax ele: "<< t.rmax();
  cout<<"\nsize of binary tree: "<<t.rsize();
  cout<<"\nheight of tree : "<<t.rheight();
  cout<<"\ndiameter of tree: "<<t.rdiameter();
  node *d = t.deepest_node();
  if(d != NULL)
  cout<<"\ndeepest node of tree "<< d->data;
  t.delete_ele(3);
  cout<<"\nsize of binary tree: "<<t.rsize();
  t.bfs();
  t.rdelete();
  cout<<"\nsize of binary tree: "<<t.rsize();
  d = t.deepest_node();
  if(d != NULL)
  cout<<"\ndeepest node of tree "<< d->data;

}
