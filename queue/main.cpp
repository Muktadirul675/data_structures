#include<bits/stdc++.h>

using namespace std;

#define SIZE 5
#define test 1

int head,tail;
int que[SIZE+1];

void display(){
	int h = head, t = tail;
	cout << "Queue: ";
	while(h!=t){
		cout << que[h];	
		h = (h+1) % (SIZE +1);
		cout << ' ';
	}
	cout << endl;
}

void enquque(int item){
	if((tail+1) % (SIZE+1) == head){
		cout << "Queue is full\n";
		return;
	}
	que[tail] = item;
	tail = (tail+1) % (SIZE+1);
}

void dequeue(){
	if(head == tail){
		cout << "Queue is empty\n";
		return;
	}
	head = (head+1) % (SIZE +1);
}

int main(){
	int c;
	while(cin >> c){
		if(c==-1) break;
		else{
			if(c == -2){
				dequeue();
			}else{
				enquque(c);
			}
		}
		display();
	}
	return 0;
}
