/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission.
  // You only need to complete this method
    Node *temp,*prev = NULL,*t = headA,*nxt;
    if(headA == NULL)
        return headB;
    while(headB != NULL){
        if(headA->data > headB->data)
        {
            temp = headB;
            headB= headB->next;
            temp->next = headA;
            if(prev != NULL)
                prev->next = temp;
            else
                t= temp;
        }else{
            nxt = headA->next;
            if(nxt != NULL)
            while(nxt->data < headB->data){
                prev = headA;
                headA=headA->next;
                nxt = nxt->next;
                if(nxt == NULL)
                    break;
            }
            temp= headB;
            headB= headB->next;
            temp->next = headA->next;
            headA->next = temp;
            prev = headA;
            headA= headA->next;
        }
    }
    return t;
}
