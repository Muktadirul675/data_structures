#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAX 20
#define test 0

bool is_balanced(char s[]){
	int top=0, n = strlen(s);
	char stack[n]; 
	for(int i=0;i<n;i++){
		if(s[i] == '('){
			if(top >= n){
				return 0;
			}
			stack[top++] = s[i];
		}else{
			if(top==0) return 0;
			top--;
		}
	}
	if(top==0) return 1;
	else return 0;
}

int main(){
	int t; cin >> t;
	while(t--) {
	    char s[MAX];
	    scanf("%s",s);
	    if(is_balanced(s)) cout << s << " is balanced\n";
	    else cout << s << " is not balanced\n";
	}
	return 0;
}
