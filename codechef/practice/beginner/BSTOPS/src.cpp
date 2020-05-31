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
	int value,position;
	Node *left = NULL, *right = NULL;
	Node(int val, int pos){
		this->value = val;
		this->position = pos;
	}
};

/*void traverseForFun(Node *a,int place){
	if(a == NULL){
		cout<<" what the heck !!! Found none at "<<place<<endl;
		return;
	}
	if(a->left != NULL) traverseForFun(a->left,place<<1);
	cout<<" Fun "<<a->value<<" at "<<place<<endl;
	if(a->right != NULL) traverseForFun(a->right,(place<<1)+1);
}*/
Node* findRightMost(Node *a, int *valueOfTarget, int *found, int place){
	if( a != NULL){
		//In else if it has no children. Then a is our dude. b =a
		if(a->right != NULL){
			a->right= findRightMost(a->right, valueOfTarget, found, (place<<1)+1);
			return a;
		}
		else{
			//a->right is NULL
			*found = place;
			*valueOfTarget = a->value;
			if(a->left != NULL) {
				Node *tbr = a->left;
				delete a;
				return tbr;
			};
			return NULL;
		}
	}
	return a;
}
Node* findLeftMost(Node *a, int *valueOfTarget, int *found, int place){
	if( a != NULL){
		//In else if See if it has no children. Then a is our dude. b =a
		if(a->left != NULL){
			a->left= findLeftMost(a->left, valueOfTarget, found, place<<1);
			return a;
		}
		else{
			//a->left is NULL
			*found = place;
			*valueOfTarget = a->value;
			if(a->right != NULL) {
				Node *tbr = a->right;
				delete a;
				return tbr;
			}
			return NULL;
		}
	}
	return a;
}
Node* traverseToDelete(Node *node,int place,int val){
	if(node==NULL) return node;
	if(val > node->value) node->right = traverseToDelete(node->right, (place<<1)+1, val);
	else if(val < node->value) node->left = traverseToDelete(node->left,place<<1, val);
	else if(node->value ==  val){
		cout<<node->position<<endl;
		//1. no children
		if(node->left == NULL && node->right == NULL){
			free(node);
			return NULL;
		}
		//2. got two children
		if(node->left != NULL && node->right != NULL){
			int valueOfTarget;
			int found = 0;
			node->right = findLeftMost(node->right, &valueOfTarget, &found,(place<<1)+1);
			//if(!found) node->left = findRightMost(node->left, &valueOfTarget, &found,place<<1);
			node->value = valueOfTarget;
			return node;
		}
		//3. got one child
		else{
			Node *toBeReturned= (node->left != NULL)?node->left:node->right;
			free(node);
			return toBeReturned;
		}
	}
	return node;
}
Node* delete_node(Node *root,int val, bool flag){
	
}
Node* traverseToInsert(Node *node, int place, int val){
	if(node == NULL){
		node = new Node(val,place);
		cout<<place<<endl;
	}
	else if(val > node->value) node->right = traverseToInsert(node->right,(place<<1)+1, val); 
	else if(val < node->value) node->left = traverseToInsert(node->left, place<<1, val);
	return node;
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	/*std::ifstream in("test.txt");
	std::streambuf*cinbuf = std::cin.rdbuf(); // save old buff
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to be in  .txt!*/
	std::string line;
	Node *head = NULL;
	int N,T,temp;
	char Instr;
	cin>>T;
	while(T--){
		cin>>Instr;
		cin>>N;
		head = (Instr == 'i')?traverseToInsert(head,1,N):traverseToDelete(head,1,N);
	}
	return 0;
}
