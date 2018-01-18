/* 
 * File:   main.cpp
 * Author: Raman
 *
 * Created on 7 January, 2018, 8:39 PM
 */

// INCLUDES
#include <iostream>
#include <stdlib.h>

using namespace std;

// DEFAULT GLOBAL VARIABLES
string exitOption = "Exit (X)";
string backOption = "Back (<-)";
string mainOption[] = {
    "Linked Lists", "queues", "stacks", "trees", "graphs", "heaps"
};
string linkedListOption[] = {"singly LL", "circular LL", 
                             "doubly LL", "circular LL", "header LL"};
string treeOption[] = {"Binary Tree" , "Binary Search Tree"};

// DECLARING FUNCTIONS
void menuDriven(string[] , int);
void doAction(string);

/**
 * MAIN PROGRAM START HERE
 * @return 0
 */
int main() {    
    menuDriven(mainOption , sizeof(mainOption));       
    return 0;
}

void menuDriven(string menu[] , int size){
    // No of elements in menu
    // adding 2 since exit and back options are added by default
    size = size/sizeof(menu[0]);
    // Run till we reach end of array
    printf("----------------------------\n");
    cout << "[" << 0 << "] " << exitOption << endl;
    cout << "[" << 1 << "] " << backOption << endl;
    printf("----------------------------\n");
    for(int l = 0; l < size; l++){
        cout << "[" << l + 2 << "] " << menu[l] << endl;
    }
    printf("----------------------------\n");
    
    // Let user choose from the menu
    int option;
    do{
        // Getting user answer
        printf("Enter Your Option:  ");
        scanf("%d",&option);
        
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
        if(actionName == exitOption){
            printf("\n> Thank You for stopping by. \n");
            printf("> Creator : ramantehlan@github \n");
            exit(0);
        }else if(actionName == backOption){
            printf("> Going back to main menu. \n");
            menuDriven(mainOption , sizeof(mainOption));
        }
         
        else if(actionName == mainOption[0]){
             printf("> Linked List selected \n");
             menuDriven(linkedListOption , sizeof(linkedListOption));
        }else if(actionName == mainOption[1]){
             printf("> Queues selected \n");
        }else if(actionName == mainOption[2]){
             printf("> Stacks selected \n");
        }else if(actionName == mainOption[3]){
             printf("> Trees selected \n");
             menuDriven(treeOption , sizeof(treeOption));
        }else if(actionName == mainOption[4]){
             printf("> Graphs selected \n");
        }else if(actionName == mainOption[5]){
             printf("> Heaps selected \n");
        }
        
        else if(actionName == treeOption[0]){
            #include "headerFiles/trees/trees.h"
            printf("> Binary tree \n");
        }else if(actionName == treeOption[1]){
            #include "headerFiles/trees/trees.h"
            printf("> Binary search tree \n");
        }
        
        else{
            printf("Error: Operation don't exist. \n");
        }
    }