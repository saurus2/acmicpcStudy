#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a)<(b)) ? (a) : (b))

typedef struct TreeNode{
    int key;
    struct TreeNode *left, *right;
};

TreeNode *search(TreeNode *node, int key){
    if(node == NULL){
        return NULL;
    }
    if(key == node->key){
        return node;
    }
    else if(key < node->key){
        return search(node->left, key);
    }else{
        return search(node->right, key);
    }
}

void insert_node(TreeNode **root, int key){
    TreeNode *p, *t;
    TreeNode *n;
    
    t = *root;
    p = NULL;
    
    while(t != NULL){
        if(key == t->key){
            return ;
        }
        p=t;
        if(key < t->key){
            t = t->left;
        }else{
            t = t->right;
        }
    }
    
    n = (TreeNode*)malloc(sizeof(TreeNode));
    if(n == NULL) return;
    
    n->key = key;
    n->left = n->right = NULL;
    
    if(p != NULL){
        if(key < p->key)
            p->left = n;
        else
            p->right = n;
    }else{
        *root = n;
    }
}

void delete_node(TreeNode **root, int key){
    TreeNode *p, *child, *succ, *succ_p, *t;
    
    p = NULL;
    t = *root;
    
    while((t != NULL) && (t->key != key)){
        p = t;
        t = (key < t->key) ? t->left : t->right;
    }
    
    if( t == NULL ){
        printf("key is not\n");
        return;
    }
    
    if((t->left == NULL) && (t->right == NULL)){
        if(p != NULL){
            if(p->left == t)
                p->left = NULL;
            else
                p->right = NULL;
        }
        else{
            *root = NULL;
        }
    }
    else if((t->left == NULL) || (t->right == NULL)){
        child = (t->left != NULL) ? t->left : t->right;
        if(p!= NULL){
            if(p->left == t){
                p->left = child;
            }else{
                p->right = child;
            }
        }else{
            *root = child;
        }
    }
    else{
        succ_p = t;
        succ = t->right;
        
        while(succ->left != NULL){
            succ_p = succ;
            succ = t->left;
        }
        if(succ_p->left == succ){
            succ_p->left = succ->right;
        }else{
            succ_p->right = succ->right;
        }
        t->key = succ->key;
        t = succ;
    }
    free(t);
}

void inorder(TreeNode *root){
    if(root){
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);
    }
}

void preorder(TreeNode *root){
    if(root){
        printf("%d -> ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ", root->key);
    }
}

int get_node_count(TreeNode *node){
    int count = 0;
    if(node != NULL){
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    }
    return count;
}

int get_leaf_count(TreeNode *node){
    int count = 0;
    if(node != NULL){
        if(node->left == NULL && node->right == NULL){
            return 1;
        }else{
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
        }
    }
    return count;
}

int get_height(TreeNode *node){
    int height = 0;
    if(node != NULL){
        height = 1 + max(get_height(node->left),get_height(node->right));
    }
    return height;
}

int main(void){
    int i;
    TreeNode *n1 = NULL;
    insert_node(&n1, 15);
    for(i=0; i<5; i++){
        insert_node(&n1, i+10);
        inorder(n1);
        printf("\n");
        insert_node(&n1, i+50);
    }
    
    printf("\n%d", get_height(n1));
    printf("\n%d", get_node_count(n1));
    printf("\n%d", get_leaf_count(n1));
    
    return 0;
}

