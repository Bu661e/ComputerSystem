#include<iostream>

using namespace std;

int func4(int a, int b, int c)
{
	int v1 = ((a - b) / 2 + b);
	int v2 = c;
	if(v1 == v2)
	{
		return( (a - b) / 2 + b);
	}
	else if(v1 < v2)
	{
		return (func4(a, (a-b)/2 + b + 1, c) + (a-b)/2 + b);
	}
	else
	{
		return (func4((a-b)/2 + b - 1, b, c) + (a-b)/2 + b);
	}
}

int main()
{
	 for(int i= 0; i <= 13; i++){
	 	if(func4(14, 0, i) == 35)
	 	{
	 		cout << i << endl;
	 	}
	 }

	return 0;
}

