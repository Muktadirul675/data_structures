#include<stdio.h>

#define SIZE 100
#define debug 1

int bst[SIZE+1];

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
			cout << "Added. index : " << li << endl;
		}else{
			add(item, li);
		}
	}else if(item > bst[index]){
		int ri = right(index);
		if(bst[ri] == -1){
			bst[ri] = item;
			cout << "Added. index : " << ri << endl;
		}else{
			add(item,ri);
		}
	}
}

int main(int argc, char const *argv[])
{
	bst[1] = 10;
	for(int i=2;i<SIZE;i++) bst[i] = -1;
	add(5);
	add(17);
	return 0;
}
