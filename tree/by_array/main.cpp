#include<iostream>
#include<cmath>

using namespace std;

#define SIZE 1000
#define debug 0

int bst[SIZE+1], last_index;

int left(int index){
	return index * 2;
}

int right(int index){
	return index*2 +1;
}

int parent(int index){
	return index/2;
}

void add(int item, int index){
	if(index == SIZE){
		cout << "Tree full\n";
		return;
	}
	if(item < bst[index]){
		int li = left(index);
		if(bst[li] == -1){
			bst[li] = item;
			if(li>last_index) last_index = li;
			if(debug == 1 || debug == 100)cout << "addded. " << item << " at " << "index : " << li << endl;
			return;
		}else{
			add(item, li);
		}
	}else if(item > bst[index]){
		int ri = right(index);
		if(bst[ri] == -1){
			bst[ri] = item;
			if(ri>last_index) last_index = ri;
			if(debug == 1 || debug == 100)cout << "addded. " << item << " at " << "index : " << ri << endl;
			return;
		}else{
			add(item,ri);
		}
	}
}

void inorder(int from){
	if(bst[from] == -1){
		cout << "empty\n";
	}else{
		int li = left(from);
		if(bst[li] != -1){
			inorder(li);
		}
		cout << bst[from] << ' ';
		int ri = right(from);
		if(bst[ri] != -1){
			inorder(ri);
		}
	}
}

void preorder(int from){
	if(bst[from] == -1){
		cout << "empty\n";
	}else{
		cout << bst[from] << ' ';
		int li = left(from);
		if(bst[li] != -1){
			preorder(li);
		}
		int ri = right(from);
		if(bst[ri] != -1){
			preorder(ri);
		}
	}
}

void addd_tabs(int ch, int mh){
	int numbers_spaces = pow(2,mh) * 2, spaces = numbers_spaces-2, total_spaces = numbers_spaces+spaces;
	int base_spaces = total_spaces/2 - 1;
	base_spaces -= 4 * ch;
	if(debug == 5 || debug == 100) cout << base_spaces << ": ";
	for(int i=0;i<base_spaces;i++) cout << ".";
}
	
int check_height(int from, int ch){
	if(debug == 2 || debug == 100) cout << "Number; " << bst[from] << " index: " << ch << endl;
	int li = left(from), ri = right(from);
	if(bst[li] == -1 && bst[ri] == -1) return ch;
	int h = ch+1;
	if(bst[li] != -1){
		int left_height = check_height(li, h);
		if(left_height>ch) ch = left_height;
	}
	if(bst[ri] != -1){
		int right_height = check_height(ri,h);
		if(right_height>ch) ch = right_height;
	}
	return ch;
}

// void print(int from){
// 	int h = check_height(from,0), els = pow(2,h), side = els * 2 + (els-1)*2;
// 	int arr[side][side];
// 	for(int i=0;i<side;i++) for(int j=0;j<side;j++) arr[i][j] = -1;
// 	for(int i=0;i<side;i+=4){
// 		arr[side-1][i] = 0;
// 	}
// 	for (int i = side-1; i >= 0; i--){
// 		int started = 0, first_occurance, last_occurance, interval, index;
// 		for(int j=0;j<side;j++){
// 			if(debug == 6 || debug == 100) cout << "i: " << i << " j: " << j << "el: " << arr[i][j] << endl;
// 			if(arr[i][j] == 0){
// 				if(started){
// 					last_occurance = j+1;
// 					interval = (last_occurance - first_occurance) / 2;
// 					index = first_occurance+interval;
// 					arr[i-1][index] = 0;
// 					arr[i-1][index+1] = 0;
// 					started = 0;
// 				}else{
// 					first_occurance = j;
// 					started = 1;
// 				}
// 				j++;
// 			}
// 		}
// 	}
// 	for(int i=0;i<side;i++){
// 		for(int j=0;j<side;j++){
// 			if(arr[i][j] == -1) cout << ' ';
// 			else cout << arr[i][j];
// 		}
// 		cout << endl;
// 	}
// }


void print(int from){
	int h = check_height(from,0), els = pow(2,h), side = els * 2 + (els-1)*4;
	h++;
	// int total_nodes = pow(2,h)-1, nodes[total_nodes], nodes_id = 0;
	// get_childs(nodes,from, 0);
	char arr[h][side];
	for(int i=0;i<h;i++) for(int j=0;j<side;j++) arr[i][j] = '.';
	for(int i=0;i<side;i+=6){
		arr[h-1][i] = 'o';
		arr[h-1][i+1] = 'o';
	}
	for (int i = h-1; i >= 0; i--){
		int started = 0, first_occurance, last_occurance, interval, index;
		for(int j=0;j<side;j++){
			if(debug == 6 || debug == 100) cout << "i: " << i << " j: " << j << "el: " << arr[i][j] << endl;
			if(arr[i][j] == 'o'){
				if(started){
					last_occurance = j+1;
					interval = (last_occurance - first_occurance) / 2;
					index = first_occurance+interval;
					arr[i-1][index] = 'o';
					arr[i-1][index+1] = 'o';
					started = 0;
				}else{
					first_occurance = j;
					started = 1;
				}
				j++;
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<side;j++){
			if(arr[i][j] == 'o'){
				int num = bst[from++];
				if(num != -1){
					int last_num = num % 10;
					num/=10;
					arr[i][j] = num + '0';
					if(arr[i][j] == '0') arr[i][j] = ' ';
					arr[i][j+1] = last_num + '0';
				}
				j++;
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<side;j++){
			if(arr[i][j] == '.' || arr[i][j] == 'o'){
				cout << ' ';
			}else{
				cout << arr[i][j];
			}
		}
		cout << endl << endl;
	}
}

int minimum(int from){
	while(bst[left(from)] != -1){
		from = left(from);
	}
	return bst[from];
}

int main(int argc, char const *argv[])
{
	bst[1] = 10;
	for(int i=2;i<SIZE;i++) bst[i] = -1;
	add(5,1);
	add(17,1);
	add(3,1);
	add(7,1);
	add(12,1);
	add(19,1);
	add(1,1);
	add(4,1);
	add(13,1);
	add(18,1);
	add(18,1);
	add(2,1);
	print(1);
	return 0;
}