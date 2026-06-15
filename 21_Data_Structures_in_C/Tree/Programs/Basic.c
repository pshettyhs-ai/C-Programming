/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 21 Data Structures in C
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node *new_node(int d){
    Node *n=malloc(sizeof(Node));
    n->data=d; n->left=n->right=NULL;
    return n;
}
Node *insert(Node *root, int d){
    if(!root) return new_node(d);
    if(d < root->data) root->left  = insert(root->left,  d);
    else if(d > root->data) root->right = insert(root->right, d);
    return root;
}
Node *search(Node *root, int d){
    if(!root || root->data==d) return root;
    if(d < root->data) return search(root->left,  d);
    return search(root->right, d);
}
Node *min_node(Node *n){ while(n->left) n=n->left; return n; }
Node *delete_node(Node *root, int d){
    if(!root) return root;
    if(d < root->data)       root->left  = delete_node(root->left,  d);
    else if(d > root->data)  root->right = delete_node(root->right, d);
    else {
        if(!root->left){ Node*r=root->right; free(root); return r; }
        if(!root->right){ Node*l=root->left; free(root); return l; }
        Node *s = min_node(root->right);
        root->data = s->data;
        root->right = delete_node(root->right, s->data);
    }
    return root;
}
void inorder(Node *root){if(root){inorder(root->left);printf("%d ",root->data);inorder(root->right);}}
void preorder(Node *root){if(root){printf("%d ",root->data);preorder(root->left);preorder(root->right);}}
void postorder(Node *root){if(root){postorder(root->left);postorder(root->right);printf("%d ",root->data);}}
int height(Node *root){
    if(!root) return 0;
    int l=height(root->left), r=height(root->right);
    return 1+(l>r?l:r);
}
void free_tree(Node *root){if(root){free_tree(root->left);free_tree(root->right);free(root);}}

int main(void){
    Node *root=NULL;
    int vals[]={50,30,70,20,40,60,80,10,25,35,45};
    int n=sizeof(vals)/sizeof(vals[0]);
    for(int i=0;i<n;i++) root=insert(root,vals[i]);

    printf("=== Binary Search Tree ===\n");
    printf("Inorder   (sorted): "); inorder(root);   printf("\n");
    printf("Preorder  (root first): "); preorder(root);  printf("\n");
    printf("Postorder (root last):  "); postorder(root); printf("\n");
    printf("Height: %d\n", height(root));

    printf("\n=== Search ===\n");
    int search_vals[]={40,55,80};
    for(int i=0;i<3;i++){
        Node *found=search(root,search_vals[i]);
        printf("Search %d: %s\n",search_vals[i],found?"Found":"Not found");
    }

    printf("\n=== Delete ===\n");
    root=delete_node(root,30);
    printf("After deleting 30: "); inorder(root); printf("\n");
    root=delete_node(root,50);
    printf("After deleting 50: "); inorder(root); printf("\n");

    free_tree(root);
    return 0;
}
/*
OUTPUT:
Inorder   (sorted): 10 20 25 30 35 40 45 50 60 70 80
Preorder  (root first): 50 30 20 10 25 40 35 45 70 60 80
Height: 4
*/
