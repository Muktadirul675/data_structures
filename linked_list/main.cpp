#include<iostream>

using namespace std;

#define SIZE 100
#define DEBUG 0

int head[SIZE], data[SIZE*SIZE], next_index[SIZE*SIZE], id, head_index;

void append(int x,int y){
	if(head[x]==-1){
		head[x] = id;
		data[id] = y;
		next_index[id] = -1;
		id++;
		if(DEBUG) cout << "Added at first\n";
	}else{
		int index = head[x];
		while(next_index[index] != -1){
			index = next_index[index];
		}
		data[id] = y;
		next_index[index] = id;
		next_index[id] = -1;
		id++;
		if(DEBUG) cout << "Added at last\n";
	}
	if(x>head_index){
		head_index = x;
	}
}

void prepend(int x,int y){
	data[id] = y;
	next_index[id] = head[x];
	head[x] = id;
	id++;
	if(DEBUG) cout << "Added at first\n";
}

void display(int x){
	int index = head[x];
	cout << "List at " << x << ": ";
	while(index != -1){
		cout << data[index] << ' ';
		index = next_index[index];
	}
	cout << endl;
}

int main(){
	for(int i=0;i<SIZE;i++) head[i] = -1;
	for(int i=0;i<SIZE*SIZE;i++) next_index[i] = -1;
	append(1,2);
	append(1,7);
	append(1,4);	
	prepend(2,12);	
	append(2,7);	
	append(2,9);	
	append(2,3);	
	display(1);
	display(2);
	if(DEBUG) {
		cout << "Head: ";
		for(int i=0;i<=head_index;i++){
			cout << head[i] << ' ';
		}	
		cout << "\nData: ";
		for(int i=0;i<id;i++){
			cout << data[i] << ' ';
		}
		cout << "\nNext: ";
		for(int i=0;i<id;i++){
			cout << next_index[i] << ' ';
		}
	}
	return 0;
}
