#include<iostream>

using namespace std;

#define MAX 20
#define test 0

typedef struct Stack {
	int top;
	char stack[MAX];
	Stack() : top(0){}
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
	bool empty(){
		return top == 0;
	}
	void clear(){
		top = 0;
	}
	void push(char item){
		if(top < MAX) stack[top++] = item;
		else cout << "Stack is full\n";
		if(test) display();
	}
	char pop(){
		if(top == 0) {
			cout << "Stack is empty\n";
			if(test) display();
			return '_';
		}
		else{
			if(test) display();
			return stack[--top];
		}
	}
} stack;

stack previous, after;
char current_page = 'h';

void go_backward(){
	if(previous.empty()) cout << "Can't go back\n";
	else{
		after.push(current_page);
		current_page = previous.pop();
	}
}

void go_forward(){
	if(after.empty()) cout << "Can't go forward\n";
	else{
		previous.push(current_page);
		current_page = after.pop();
	}
}

void browse(char page){
	previous.push(current_page);
	current_page = page;
	if(!after.empty()) after.clear();
}

void current(){
	cout << "Current page: " << current_page << endl;
}


int main(){
	char page;
	while(cin >> page){
		if(page == '0') break;
		else{
			if(page == 'p') go_backward();
			else if(page == 'f') go_forward();
			else{
				browse(page);
			}
			current();
		}
	}
	return 0;
}
