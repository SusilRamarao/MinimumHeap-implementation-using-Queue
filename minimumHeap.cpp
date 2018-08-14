#include<iostream>
#include<stdlib.h>
#include<queue>
#define COUNT 10

using namespace std;

//Dynamic allocation of elements in array
class Node{
	
	public:
		int data;
		Node *parent;
		Node *left;
		Node *right;
		
	Node(){
		
	}
	
	Node(int temp){
		
		this->data = temp;
		this->left = NULL;
		this->right = NULL;
	}
};

void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}

class minHeap{
	
	public:
		
		queue<Node*> nodeQueue;
		Node *root;
	
	minHeap(){
		
		Node *root = NULL;
	}
	
	void insert(int temp){
		
		if(this->nodeQueue.empty()){
			cout<<"EMPTY\n";
			this->root = new Node(temp);
			root->left = new Node(-1);
			root->left->parent = root;
			root->right = new Node(-1);
			root->right->parent = root;
			
			root->parent = NULL;
			
			this->nodeQueue.push(root->left);
			this->nodeQueue.push(root->right);
		}
		else{
			
			//Node *root = new Node(temp);
			Node *current = this->nodeQueue.front();
			current->left = new Node(-1);
			current->left->parent = current;
			current->right = new Node(-1);
			current->right->parent = current;
			
			this->nodeQueue.push(current->left);
			this->nodeQueue.push(current->right);
			
			while(current->parent != NULL){
				
				cout<<"test\n";
				cout<<"CURRENT DATA\n";
				cout<<current->data<<endl;
				cout<<"Current PArent data\n";
				cout<<current->parent->data<<endl;
				
				if(current->parent->data <= temp){
					
					cout<<"NO NEED TO TRAVERSE\n";
					current->data = temp;
					break;
				}
				cout<<"NEED TO TRAVERSE\n";
				current->data = current->parent->data;
				current->parent->data = temp;
				current = current->parent;
			}
			
			cout<<"AFTER ADDING CURRENT DATA\n";
				cout<<current->data<<endl;
				if(current->parent != NULL){
				
				cout<<"Current PArent data\n";
				
				cout<<current->parent->data<<endl;
			}
			this->nodeQueue.pop();
			
			
			/*
			if(current->parent->data < data){
				
				current->data = temp;
				this->nodeQueue.pop();
			}
			else{
				
				current->data = current->parent->data;
				current->parent->data = temp;
			}
			*/
		}
	}
		
	
};


int main(){
	
	
	minHeap *mHeap = new minHeap();
	
	int t;
	while(true){
		
		cin>>t;
		
		if(t== 0){
			break;
		}
		
		mHeap->insert(t);
		print2DUtil(mHeap->root, 0);
		
	}
	
}
