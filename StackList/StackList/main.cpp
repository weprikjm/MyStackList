#include "MyStackList.h"
#include <iostream>

int main(int argc, char** argv)
{
	MyStackList<int> stackList;
	
	stackList.Push(0);
	stackList.Push(1);

	int n = 0;
	stackList.Pop(n);
	stackList.Pop(n);
	stackList.Pop(n);
	
	getchar();
	return 0;
}