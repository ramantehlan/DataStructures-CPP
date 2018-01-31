/* 
 * File:   main.cpp
 * Author: Raman
 *
 * Created on 7 January, 2018, 8:39 PM
 */

// INCLUDES
#include <iostream>
#include <stdlib.h>

#include "headerFiles/trees/trees.h"

using namespace std;

// DEFAULT GLOBAL VARIABLES
// _Warning: Do not change the position of any option_
string exitOption = "Exit (X)";
string backOption = "Back (<-)";
string mainOption[] = {
    "Linked Lists", "queues", "stacks", 
    "trees", "graphs", "heaps"
};
string linkedListOption[] = {
    "singly LL", "circular LL", "doubly LL", 
    "circular LL", "header LL"
};
string treeOption[] = {
    "Binary Tree" , "Binary Search Tree"
};
string binarySearchTreeOption[] = {
    "Insert a new node", "Pre-order traversal", "In-order traversal", 
    "Post-order traversal", "Find smallest node", "Find Largest node", 
    "Delete a node", "Count number of nodes", "Count non-leaf/internal nodes", 
    "Count leaf/external nodes",  "Calculate hight", "Find the mirror Image",
    "Find path to a node", "Delete the tree"
};

// DECLARING FUNCTIONS
void menuDriven(string[] , int);
void doAction(string);

// IMPORTANT DATA STRUCTURES
binarySearchTree BST = binarySearchTree();





/**
 * MAIN PROGRAM START HERE
 * @return 0
 */
int main() {    
// To fill dummy data in BST
BST.insert(54);
BST.insert(50);
BST.insert(32);
BST.insert(64);
BST.insert(24);
BST.insert(43);
BST.insert(15);
BST.insert(12);

    menuDriven(mainOption , sizeof(mainOption));       
    return 0;
}

void menuDriven(string menu[] , int size){
    // No of elements in menu
    // adding 2 since exit and back options are added by default
    size = size/sizeof(menu[0]);
    // Run till we reach end of array
    printf("\t----------------------------\n");
    cout << "\t[" << 0 << "] " << exitOption << endl;
    cout << "\t[" << 1 << "] " << backOption << endl;
    printf("\t----------------------------\n");
    for(int l = 0; l < size; l++){
        cout << "\t[" << l + 2 << "] " << menu[l] << endl;
    }
    printf("\t----------------------------\n");
    
    // Let user choose from the menu
    int option;
    do{
        // Getting user answer
        printf("\tEnter Your Option:  ");
        scanf("%d",&option);
        cout << endl;
        
        // Check if option selected is not out of range
        if(option > (size+1) || option < 0){
            printf("Error: Option out of range \n");
        }else if(option == 0){
            doAction(exitOption);
        }else if(option == 1){
            doAction(backOption);
        }else{
        // do action as per option selected
            doAction(menu[option - 2]);
        }
        
    }while(option != 0);
}

void doAction(string actionName){
        //Exit the program
        if(actionName == exitOption){
            printf("\n> Thank You for stopping by. \n");
            printf("> Creator : ramantehlan@github \n");
            exit(0);
        }
        //Going back to main menu
        else if(actionName == backOption){
            printf("> Going back to main menu. \n");
            menuDriven(mainOption , sizeof(mainOption));
        }
         
        //Linked list
        else if(actionName == mainOption[0]){
             printf("> Linked List selected \n");
             menuDriven(linkedListOption , sizeof(linkedListOption));
        }
        //Queues
        else if(actionName == mainOption[1]){
             printf("> Queues selected \n");
        }
        //Stack
        else if(actionName == mainOption[2]){
             printf("> Stacks selected \n");
        }
        //Trees
        else if(actionName == mainOption[3]){
             printf("> Trees selected \n");
             menuDriven(treeOption , sizeof(treeOption));
        }
        //Graphs
        else if(actionName == mainOption[4]){
             printf("> Graphs selected \n");
        }
        //Heaps
        else if(actionName == mainOption[5]){
             printf("> Heaps selected \n");
        }
        
        //Binary tree
        else if(actionName == treeOption[0]){
            printf("> Binary tree \n");
        }
        //Binary search tree
        else if(actionName == treeOption[1]){
            printf("> Created binary search tree (BST)\n");
            //Show all the possible actions on binary search tree
            menuDriven(binarySearchTreeOption, sizeof(binarySearchTreeOption));
        }
        //Insert into binary search tree
        else if(actionName == binarySearchTreeOption[0]){
            int no;
            cout << "\n> How many nodes you wish to add to BST: ";
            cin >> no;
            
            // Add multiple nodes
            for(int i = 0; i < no; i++){
                int value;
                cout << "> " << (i+1) << ") Enter the value of new node: ";
                cin >> value;
                BST.insert(value);
            }
            
            cout << "> Successfully Inserted. \n";
            
        }   
        //Pre-order traversal
        else if(actionName == binarySearchTreeOption[1]){
            cout << "> Pre-order traversal: ";
            BST.preOrderAccess(BST.getRoot());
            cout << endl;
        }
        //In-order Traversal
        else if(actionName == binarySearchTreeOption[2]){
            cout << "> In-order traversal: ";
            BST.inOrderAccess(BST.getRoot());
            cout << endl;
        }
        //Post-order traversal
        else if(actionName == binarySearchTreeOption[3]){
            cout << "> Post-order traversal: ";
            BST.postOrderAccess(BST.getRoot());
            cout << endl;
        }
        //Find the smallest value
        else if(actionName == binarySearchTreeOption[4]){
            cout << "> Smallest value: ";
            BST.smallestData();
            cout << endl;
        }
        //Find the largest value
        else if(actionName == binarySearchTreeOption[5]){
            cout << "> Largest value: ";
            BST.largestData();
            cout << endl;
        }
        //Delete a node 
        else if(actionName == binarySearchTreeOption[6]){
            int deleteValue;
            cout << "> Enter the value of node (to delete): ";
            cin >> deleteValue;
            
            BST.deleteNode(deleteValue);
        }
        
        
        //Unknown Operation
        else{
            printf("Error: Operation don't exist. \n");
        }
    }