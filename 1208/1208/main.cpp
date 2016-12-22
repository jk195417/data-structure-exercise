//
//  main.cpp
//  1208
//
//  Created by Xin on 2016/12/20.
//  Copyright © 2016年 hongxin. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
struct Node{
    char value;
    Node *left;
    Node *right;
    Node(){
        this->value = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node *ptr){
    if (ptr) {
        inorder(ptr->left);
        printf("%c ",ptr->value);
        inorder(ptr->right);
    }
}
void preorder(Node *ptr){
    if (ptr) {
        printf("%c ",ptr->value);
        preorder(ptr->left);
        preorder(ptr->right);
    }
    
}
void postorder(Node *ptr){
    if (ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%c ",ptr->value);
    }
}
struct Tree{
    Node *root=(Node*)malloc(sizeof(Node));
    Tree(const char *arr){
        int length=0;
        int index=0;
        int tree_height;
        Node *pointer = root;
        while(arr[length] != '\0'){
            length++;
        }
        root->value = arr[index];
        for(int i=length/2+1; i>0; i--){
            printf(" ");
        }
        printf("%c\t",arr[index]);
        printf("\n");
        index++;
        for(tree_height = length/2 ; tree_height>0; tree_height--){
            for(int i=tree_height; i>0; i--){
                printf(" ");
            }
            pointer->left = new Node();
            pointer->left->value=arr[index];
            if(index>=length){
                break;
            }
            
            printf("%c ",arr[index]);
            index++;
            
            pointer->right = new Node();
            pointer->right->value=arr[index];
            if(index>=length){
                break;
            }
            printf("%c",arr[index]);
            index++;
            
            pointer = pointer->left;
            printf("\n");
        }
    }
    void Inorder(){
        inorder(root);
    }
    void Preorder(){
        preorder(root);
    }
    void Postorder(){
        postorder(root);
    }
};



int main(int argc, const char * argv[]) {
    FILE *file;
    int i=0;
    char buf;
    char content[100];
    const char *path = "/Users/Xin/Code/Data-Structure-Exercise/1208/a.txt";
    file = fopen(path, "r");
    if(!file){
        printf("open file failed\npath : %s\n",path);
        exit(1);
    }
    printf("file : %s open success!\n",path);
    while (!feof(file)) {
        fscanf(file, "%c ",&buf);
        content[i]=buf;
        i++;
    }
    printf("tree\t:\n");
    Tree tree(content);
    
    printf("Inorder\t:\t");
    tree.Inorder();
    printf("\n");
    
    printf("Preorder\t:\t");
    tree.Preorder();
    printf("\n");
    
    printf("Postorder\t:\t");
    tree.Postorder();
    printf("\n");
    
    return 0;
}
