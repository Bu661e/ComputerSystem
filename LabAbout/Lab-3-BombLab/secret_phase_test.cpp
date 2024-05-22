#include <iostream>

using namespace std;

struct Node
{
	int val;
	int left;
	int right;
};

int arr_val[16] = {
	0,
	36,
	8,
	50,
	6,
	22,
	45,
	107,
	1,
	7,
	20,
	35,
	40,
	47,
	99,
	1001
};
Node arr_Node[16];

void insert()
{
	for(int i = 1; i <= 15; i++)
	{
		arr_Node[i] = {arr_val[i], 2*i, (2*i + 1)};
	}
	
}
void print_all_node()
{
	int pau = 1;
	for(int i = 1; i <= 15; i++)
	{
		printf("%d ", arr_Node[i].val);
		if(i == pau)
		{
			printf("\n");
			pau = 2 * pau + 1;
		}


	}
}

int fun7(int tar, int addr)
{
	int l = 2 * addr;
	int r = 2 * addr + 1;
	if(arr_Node[addr].val == tar) return 0;
	if(arr_Node[addr].val < tar) return 2 * fun7(tar, r) + 1;
	if(arr_Node[addr].val > tar) return 2 * fun7(tar, l);
}

int main()
{
	insert();
//	print_all_node();
	
	for(int i = 1; i <= 15; i++)
	{
		if(fun7(arr_val[i], 1) == 3)
			cout << arr_val[i] << endl;
	}
	return 0;
}
