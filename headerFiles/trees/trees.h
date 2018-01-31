/* 
 * File:   trees.h
 * Author: Raman
 *
 * Created on 7 January, 2018, 8:58 PM
 */

#ifndef TREES_H
#define TREES_H

#include <stdio.h>
#include <stdlib.h>

class binarySearchTree{
    //Structure of a single node
    class node{
    public:
        int data;
        node* left;
        node* right;
    }; 

public:
    node* root = NULL;
    
    binarySearchTree(){
        
    }
    
    //To insert a node into the BST
    void insert(int value){
        node* ele = NULL;
        node* currentNode = root;
        node* parentNode = NULL;
        
        ele = (node*)malloc(sizeof(node));
        ele->data = value;
        ele->left = NULL;
        ele->right = NULL;
        
        if(root == NULL){
            root = ele;
            root->left = root->right = NULL;
        }else{
            while(currentNode != NULL){
                parentNode = currentNode;
                if(currentNode->data > value)
                    currentNode = currentNode->left;
                else
                    currentNode = currentNode->right;
            }
            if(parentNode->data > value)
                parentNode->left = ele;
            else 
                parentNode->right = ele;
        } 
    }
    
    //Pre-order traversal 
    void preOrderAccess(node* n){
        if(n != NULL){
            printf("%d ", n->data);
            preOrderAccess(n->left);
            preOrderAccess(n->right);
        }
    }
    
    //In-order traversal
    void inOrderAccess(node* n){
        if(n != NULL){
            inOrderAccess(n->left);
            printf("%d ", n->data);
            inOrderAccess(n->right);
        }
    }
    
    //Post-order traversal
    void postOrderAccess(node* n){
        if(n != NULL){
            postOrderAccess(n->left);
            postOrderAccess(n->right);
            printf("%d ", n->data);
        }
    }
    
    //smallest node Access
    void smallestData(){
        if(root != NULL){
            node* leftNode = smallestNode(root);
            printf("%d ", leftNode->data);
        }
    }
    
    //Largest node access
    void largestData(){
        if(root != NULL){
            node* rightNode = largestNode(root);
            printf("%d ", rightNode->data);
        }
    }
    
    //Most left node
    node* smallestNode(node* n){
        if(n == NULL || n->left == NULL){
            return n;
        }else{
            return smallestNode(n->left);
        }
    }
    
    //Most right node
    node* largestNode(node* n){
        if(n == NULL || n->right == NULL){
            return n;
        }else{
            return largestNode(n->right);
        }
    }
    
    //Delete a node 
    void deleteNode(int value){
        
    }
    
    //To get the root of BST
    node* getRoot(){
        return root;
    }
    
    //To display the BST
    void print(){
        

    }
    
};

#endif /* TREES_H */

