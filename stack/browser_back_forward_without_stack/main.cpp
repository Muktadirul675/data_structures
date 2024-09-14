#include <bits/stdc++.h>

using namespace std;

#define MAX 20
char pages[MAX];
int current_index;
int after;

void current(){
	cout << "Current page: " << pages[current_index] << endl;
}

void go_backward(){
	if(current_index == 0){
		cout << "Can't go back\n";
	}else{
		current_index--;
		after++;
	}
}

void go_forward(){
	if(after == 0) cout << "Can't go forward\n";
	else{
		after--;
		current_index++;
	}
}

void browse(char page){
	pages[++current_index] = page;
	after = 0;
}

int main(){
	char c;
	pages[0] = 'h';
	while(cin >> c){
		if(c=='0') break;
		else{
			if(c=='p') go_backward();
			else if(c=='f') go_forward();
			else{
				browse(c);
			}
			current();
		}
	}
	return 0;
}