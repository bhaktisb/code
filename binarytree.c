#include<stdio.h>
#include<malloc.h>
struct Node* insert(int data);
 struct Node* search(struct Node * root , int key);
 struct Node* searchIter(struct Node * root , int key);
 struct Node *insertBST(struct Node * root ,int key);
  void preorder(struct Node* root);

struct Node
{
int data;
struct Node * rchild;
struct Node * lchild;
 };

int main()
{
 struct Node *p = insert(20);
 struct Node *p1 = insert(12);
 struct Node *p2 = insert(45);
 struct Node *p3 = insert(70); 
 p->lchild=p1;
 p->rchild=p2;
 p2->rchild=p3;
 /*struct Node *s = search(p,80);
 if(s!=NULL)
 {
 printf("%d ",s->data);
 }
 else{
    printf("Element not Found");
 }*/
 preorder(p);
  insertBST(p,11);
  printf("\n");
   preorder(p);

}
struct Node* insert(int data)
 {
    struct Node *p;
    p=(struct Node * )malloc(sizeof(struct Node) ) ;
    p->data=data;
    p->lchild=NULL;
    p->rchild=NULL;
    return p;
 }

struct Node *insertBST(struct Node * root ,int key)
{
    struct Node *tmp,*par,*ptr;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        par=ptr;
        if(key<ptr->data)
        {
            ptr=ptr->lchild;
        }
        else if (key>ptr->data)
        {
            ptr=ptr->rchild;
        }else{
            printf("Duplicate Key ");
            return root;
        }
    }
      tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data=key;
        tmp->lchild=NULL;
        tmp->rchild=NULL;
        if(par==NULL)
        {
            root=tmp;
        }
        else if(key<par->data)
        {
            par->lchild=tmp;
        }else
        {
            par->rchild=tmp;
        }
        return root;
}
 struct Node* search(struct Node * root , int key)
{
if(root==NULL)
{
    return NULL;
}
if(key==root->data)
{
    return root;
}
else if(key<root->data)
{
    return search(root->lchild,key);
}
else if(key>root->data)
{
    return search(root->rchild,key);
}
}

 void preorder(struct Node* root)
 {
    if(root!=NULL)
    {
        printf("%d  ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
 }
