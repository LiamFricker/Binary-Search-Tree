#include <stdio.h>
#include <iostream>
using namespace std;

//Node Class
class Link
{
public:
    string name;
    int weight;
    Link* left;
    Link* right;
};

class Tree
{  
    public:
        Link* root;

//Checks if the list is empty
bool isEmpty()
{
    return root == NULL;
}
public:
//Build the tree from the unique set of names (names are the key value) and their associated weights.
    void insert(string name, int weight) {
        Link* temp = new Link();
        Link* current;
        Link* parent;

        temp->name = name;
        temp->weight = weight;
        temp->left = NULL;
        temp->right = NULL;

        //if tree is empty
        if(isEmpty()) {
            root = temp;
        } 
        else {
            current = root;
            parent = NULL;

            while(true) {                
                parent = current;
                    
                //go to left of the tree
                if(name.compare(parent->name) < 0) {
                    current = current->left;                
                    //insert to the left
                        
                    if(current == NULL) {
                        parent->left = temp;
                        break;
                    }
                }  //go to right of the tree
                else {
                    current = current->right;
                    
                    //insert to the right
                    if(current == NULL) {
                        parent->right = temp;
                        break;
                    }
                }
            }            
        }
}    
//Searches for a Name and returns its Weight
int search(string namef) {
    Link* current = root;
    if(isEmpty()){
        cout << "No match exists.\n";
        return 0;
    }
    while(current->name.compare(namef) != 0 or current != NULL) {
        if(current->name.compare(namef) > 0) {
            current = current->left;
        }
        else {                
            current = current->right;
        }
    }
    if(current == NULL){
        cout << "No match exists.\n";
        return 0;
    }
    return current->weight;  
}
}; 
void pre_order_traversal(Link* root) {
    if(root != NULL) {
        cout << root->name << ": " << root-> weight << endl;
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void inorder_traversal(Link* root) {
    if(root != NULL) {
        inorder_traversal(root->left);
        cout << root->name << ": " << root-> weight << endl;
        inorder_traversal(root->right);
    }
}
void post_order_traversal(Link* root) {
    if(root != NULL) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        cout << root->name << ": " << root-> weight << endl;
    }
}
//print out the height of the tree using recursion
int returnHeight(Link* root){
    int height = 1;
    int lheight = 0;
    int rheight = 0;
    if(root != NULL) {
        if(root->left != NULL){
            lheight = returnHeight(root->left);
        }
        if(root-> right != NULL){
            rheight = returnHeight(root->right);
        }
        if(lheight > rheight){
            height += lheight;
        }
        else{
            height += rheight;
        }
    }
    return height;
}
//Determine the number of leaves and print the result (remember a leaf has no children).
int returnLeaves(Link* root){
    int leaves = 0;
    if(root != NULL) {
        if(root->left != NULL){     
            leaves += returnLeaves(root->left);
        }
        if(root->right != NULL){     
            leaves += returnLeaves(root->right);
        }
        if(root->left == NULL and root->right == NULL){
            leaves++;
        }
    }
    return leaves;
}
//Find the first name in alphabetical order (this should not go through every node, unless the tree happens to be a linked list).
string returnFirst(Link* root){
    if(root != NULL) {
        if(root->left != NULL){     
            return returnFirst(root->left);
        }
        return root->name;
    }
}
//Determine the lowest weight contained in the tree.
int returnLightest(Link* root){
    int lightest = root->weight;
    if(root != NULL){
        if(root->left != NULL){
            if(returnLightest(root->left) < lightest){
                lightest = returnLightest(root->left);
            }
        }
        if(root->right != NULL){
            if(returnLightest(root->right) < lightest){
                lightest = returnLightest(root->right);
            }
        }
    }
    return lightest;
}
int main()
{
    Tree* datalist = new Tree();
    string name;
    int weight = 0;
    cout << "Welcome to Weight Sorter!\n";
    cout << "Please enter 3 names and weights: ";
    for(int i = 0; i < 3; i++){
        cin >> name;
        cin >> weight;
        datalist->insert(name, weight);
    }
    cout << "pre_order traversal: \n";
    pre_order_traversal(datalist->root);
    cout << "inorder traversal: \n";
    inorder_traversal(datalist->root);
    cout << "post_order traversal: \n";
    post_order_traversal(datalist->root);
    cout << "The Height of the Tree is: " << returnHeight(datalist->root) << endl;
    cout << "The First Name in Alphabetical Order is: " << returnFirst(datalist->root) << endl;
    cout << "The lightest weight in the Tree is: " << returnLightest(datalist->root) << endl;
    return 0;
}
/* Sample Output
Welcome to Weight Sorter!
Please enter 15 names and weights: Mark 150 Tina 115 Zach 55 Amy 140 Steve 220 Brian 250 Liz 125 Laura 115 Alex 175 Jason 210Eric 175 Aaron 195 Kim 135 Brandon 78
Brian 220
pre_order traversal: 
Mark: 150
Amy: 140
Alex: 175
Aaron: 195
Brian: 250
Brandon: 78
Liz: 125
Laura: 115
Jason: 210
Eric: 175
Brian: 220
Kim: 135
Tina: 115
Steve: 220
Zach: 55
inorder traversal:
Aaron: 195
Alex: 175
Amy: 140
Brandon: 78
Brian: 250
Brian: 220
Eric: 175
Jason: 210
Kim: 135
Laura: 115
Liz: 125
Mark: 150
Steve: 220
Tina: 115
Zach: 55
post_order traversal:
Aaron: 195
Alex: 175
Brandon: 78
Brian: 220
Eric: 175
Kim: 135
Jason: 210
Laura: 115
Liz: 125
Brian: 250
Amy: 140
Steve: 220
Zach: 55
Tina: 115
Mark: 150
The Height of the Tree is: 8
The First Name in Alphabetical Order is: Aaron
The lightest weight in the Tree is: 55
*/