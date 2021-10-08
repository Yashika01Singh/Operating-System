#include <stdio.h>
#include <stdlib.h>
struct node {
    int val;
    struct node*left;
    struct node*right;
    int height;
};

struct node* new (int value){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height =1;
    return new_node;
}
int getheight (struct node *root){

    if(root==NULL){
        return 0;
    }
    return root->height;

    

}
int max (int a , int b){
    if(a>b){
        return a;
    }
    return b;
}

int getbalance (struct node *root){

    if(root==NULL) {
         return 0;
    }

    return getheight(root->left) - getheight(root->right);
}

struct node* rr (struct node *root){

    struct node* root_left = root-> left;
    struct node* root_left_right = root_left ->right;

    //right rotate
    root_left->right = root;
    root->left = root_left_right;
    


    // update hrights
    root->height= max(getheight(root->left) , getheight(root->right)) +1;
    root_left ->height = 1+max(getheight(root_left->left) , getheight(root_left->right));

    return root_left;
}
struct node* ll (struct node *root){
    struct node* root_right = root-> right;
    struct node* root_right_left= root_right ->left;
    //left rotate

    root_right->left=root;
    root->right = root_right_left;

    //update heights
    root->height= max(getheight(root->left) , getheight(root->right)) +1;
    root_right ->height = 1+max(getheight(root_right->left) , getheight(root_right->right));
    return root_right;
}
struct node* insert (struct node *root , int value){
    
    if(root == NULL)
        {
            return new(value);
        }
   
    if(value == root->val){
        return root;
    }
    
    if (value < root->val)
        {   
            root->left = insert (root->left , value);}
    if (value > root->val)
        {   
            root->right= insert (root->right , value);}

    root->height= max(getheight(root->left) , getheight(root->right)) +1;
    printf("inserting                         ");
    // balancing
     
    int bal = getbalance(root);

    // ll case
    if(bal >1 && value < root->left->val){
        return rr(root);
    }

    // rr case
    if(bal <-1 && value > root->right->val){
            return ll(root);

    }

    //double rotations

    //lr case
    if(bal >1 && value> root->left->val){
            root->left = ll(root->left);
            return rr(root);
    }

    //rl case
    if(bal <-1 && value < root->right->val){

        root->right = rr(root->right);
        return ll (root);
    }

    return root;

}
struct node* minNode(struct node *root){
    if(root==NULL)
        return NULL;
     if(root->left != NULL){
         return minNode(root->left);
     }
     return root;
}
struct node* delete(struct node *root , int value){
 
    if(root==NULL)
        return NULL;
    
    if(root->val > value)
        root->left = delete(root->left , value);
    else if (root->val < value)
        root->right = delete(root->right , value);
    
    else{

        if(root->left != NULL && root->right !=NULL){
            struct node *minRight = minNode(root->right);
            root->val = minRight->val;
            root->right = delete(root->right , minRight->val);
        }
        else if(root->left != NULL){
            struct node *temp;
            
            temp = root;
            root=root->left;
            free(temp);
                        
            }
        else if(root->right != NULL){
            struct node* temp;
            temp = root;
            root=root->right;
            free(temp);
            
        }   

        else{
         free(root);
         return NULL;
        }

    }
    root->height= max(getheight(root->left) , getheight(root->right)) +1;
    int bal = getbalance(root);
    // ll case
    if(bal >1 && getbalance(root->left)>=0){
        return rr(root);
    }

    // rr case
    if(bal <-1 && getbalance(root->right)<=0){
            return ll(root);

    }

    //double rotations

    //lr case
    if(bal >1 && getbalance(root->left)<0){
            root->left = ll(root->left);
            return rr(root);
    }

    //rl case
    if(bal <-1 && getbalance(root->right)<=0){

        root->right = rr(root->right);
        return ll (root);
    }

    return root;

}
void printPreOrder(struct node *root){
  if (root != NULL) {
    printf("%d ", root->val);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}
int main(){

    struct node *root;
    root=NULL;
    int element;
    struct node *temp;
    
    int query;
    
    while(1){
        printf("\nEnter operation 1.Insert \n2.Delete \n3.Minimum Element \n4.quit\n");
        
        scanf("%d" , &query);
        if(query==5){
            printPreOrder(root);
        }
        if(query >5){
            printf("Invalid choice try again");
            continue;
        }
        if(query == 4){
            break;
        }
        if(query == 1){
            printf("\nEnter element to insert in BST : ");
            
            scanf("%d" , &element);
            root=insert(root , element);
            

        }
        if(query == 2){
            printf("\nEnter element to delete from BST : ");
            
            scanf("%d" , &element);
            root=delete(root , element);
            

        }
        if(query == 3){
            temp=minNode(root);
            printf("\nMinimum Element is : %d ", temp->val);
        }

    }
    
    //deleting the tree
    while(root!=NULL){
        root=delete(root, root->val);
    }
    
}
