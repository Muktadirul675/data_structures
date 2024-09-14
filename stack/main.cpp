#include<iostream>

using namespace std;

#define MAX 20
#define test 0

typedef struct Struct {
	int top;
	int stack[MAX];
	Struct() : top(0){}
	void display(){
		if(top == 0){
			cout << "Stack is empty!\n";
			return;
		}
		for(int i=0;i<top;i++){
			cout << stack[i] << ' ';
		}
		cout << endl;
		cout << "-----" << endl;
	}
	void push(int item){
		if(top < MAX) stack[top++] = item;
		else cout << "Stack is full\n";
		if(test) display();
	}
	int pop(){
		if(top == 0) {
			cout << "Stack is empty\n";
			if(test) display();
			return -1;
		}
		else{
			if(test) display();
			return stack[--top];
		}
	}
} stack;

int main(){
	stack s;
	s.push(7);
	s.push(3);
	s.push(3);
	s.push(5);
	s.display();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.display();
	s.push(11);
	s.push(34);
	s.push(30);
	s.display();
	return 0;
}
