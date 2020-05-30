#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <tuple>
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define max(a,b) a>b?a:b
using namespace std;

struct Node{
	int value;
	int place;
	Node *left = NULL;
	Node *right = NULL;
};
Node *head = NULL;
Node* findRightMost(Node *a, int *valueOfTarget, char *found){
	if( a != NULL){
		//In else if it has no children. Then a is our dude. b =a
		if(a->right != NULL){
			a->right= findRightMost(a->right, valueOfTarget, found);
			return a;
		}
		else if(a->right == NULL && a->left == NULL){
			cout<<" Found "<<a->value<<" in findRightMost at position "<<a->place<<endl;
			*found = 'y';
			*valueOfTarget = a->value;
			return NULL;
		}
	}
	return a;
}
Node* findLeftMost(Node *a, int *valueOfTarget, char *found){
	if( a != NULL){
		//In else if See if it has no children. Then a is our dude. b =a
		if(a->left != NULL){
			a->right= findLeftMost(a->left, valueOfTarget, found);
			return a;
		}
		else if(a->right == NULL && a->left == NULL){
			cout<<" Found "<<a->value<<" in findLeftMost at position "<<a->place<<endl;
			*found = 'y';
			*valueOfTarget = a->value;
			return NULL;
		}
	}
	return a;
}
Node* traverseToDelete(Node *node,int val){
	
	if(node==NULL) return node;
	
	if(node->value ==  val){
		
		//1. no children
		if(node->left == NULL && node->right == NULL){
			delete node;
			return NULL;
		}
		//2. got two children
		if(node->left != NULL && node->right != NULL){
			int valueOfTarget;
			char found = 'n';
			node->left = findRightMost(node->left, &valueOfTarget, &found);
			if(found != 'n'){
				cout<<" Found in left treee child with value"<<valueOfTarget<<" at position"<<endl;
			}
			else{
				node->right = findLeftMost(node->right, &valueOfTarget, &found);
				cout<<" Found in right tree child with value"<<valueOfTarget<<" at position "<<endl;
			}
			return node;
		}
		//3. got one child
		else{
			Node *toBeReturned= (node->left != NULL)?node->left:node->right;
			delete node;
			return toBeReturned;
		}
	}
	if(val > node->value) node->right = traverseToDelete(node->right, val);
	else node->left = traverseToDelete(node->left, val);
	return node;
}
Node* traverseToInsert(Node *node, int place, int val){
	if(node == NULL){
		node = new Node();
		node->value = val;
		node->place = place;
		cout<<place<<endl;
		return node;
	}
	if(val > node->value) node->right = traverseToInsert(node->right, node->place*2+1, val); 
	if(val < node->value) node->left = traverseToInsert(node->left, node->place*2, val);
	return node;
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	std::ifstream in("test.txt");
	std::streambuf*cinbuf = std::cin.rdbuf(); // save old buff
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to be in  .txt!
	std::string line;
	int N,T,temp;
	char Instr;
	cin>>T;
	while(T--){
		cin>>Instr;
		cin>>N;
		head = (Instr == 'i')?traverseToInsert(head,1,N):traverseToDelete(head,N);
	}
	return 0;
}
