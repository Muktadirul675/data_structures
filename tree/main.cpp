#include<iostream>

using namespace std;

typedef struct Node{
	int data;
	struct Node * left;
	struct Node * right;
	Node(): left(NULL), right(NULL), data(0){}
	Node(int item): left(NULL), right(NULL), data(item){}
	struct Node * add_left(int item){
		struct Node * newNode = new struct Node(item);
		left = newNode;
		return newNode;
	}
	struct Node * add_right(int item){
		struct Node * newNode = new struct Node(item);
		right = newNode;
		return newNode;
	}
	void pre_order(){
		cout << data << ' ';
		if(left){
			left->pre_order();
		}
		if(right){
			right->pre_order();
		}
	}
	void inorder(){
		if(left){
			left->inorder();
		}
		cout << data << ' ';
		if(right){
			right->inorder();
		}
	}
	void postorder(){
		if(left){
			left->postorder();
		}
		if(right){
			right->postorder();
		}
		cout << data << ' ';
	}
} node;

int main(){
	node two(2);
	node * seven = two.add_left(7);
	node * nine = two.add_right(9);
	node * one = seven->add_left(1);
	node * six = seven->add_right(6);
	node * five = six->add_left(5);
	node * ten = six->add_right(10);
	node * eight  = nine->add_right(8);
	node * three = eight->add_left(3);
	node * four = eight->add_right(4);
	two.pre_order();
	cout << endl;
	two.inorder();
	cout << endl;
	two.postorder();
	return 0;
}
