#include<iostream>
using namespace std;

struct node{
  int data;
  node *left;
  node *right;
};

bool isIdentical(node *root1, node *root2){
  if(root1==NULL && root2==NULL)
    return true;
  if(!(root1 && root2))
    return false;
  if(root1->data != root2->data)
    return false;
  bool left = isIdentical(root1->left,root2->left);
  bool right = isIdentical(root1->right,root2->right);
  return (left&&right);
}
