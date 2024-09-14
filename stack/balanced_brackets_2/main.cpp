#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define test 1
#define MAX 50

bool is_balanced(char s[]){
	int n = strlen(s), top=0;
	char stack[n];
	for(int i=0;i<n;i++){
		if(s[i] == '(' || s[i] == '{' || s[i] == '['){
			stack[top++] = s[i];
		}else{
			if(top==0) return 0;
			top--;
			if(s[i] == ')'){
				if(stack[top] != '(') return 0;
			}else if(s[i] == '}'){
				if(stack[top] != '{') return 0;
			}else if(s[i] == ']'){
				if(stack[top] != '[') return 0;
			}
		}
	}
	if(top == 0){
		return 1;
	}else return 0;
}

int main()
{
	int t; cin >> t;
	while(t--) {
	    char s[MAX];
	    scanf("%s",s);
	    if(is_balanced(s)) cout << s << " is balanced\n";
	    else cout << s << " is not balanced\n";
	}
	return 0;
}

