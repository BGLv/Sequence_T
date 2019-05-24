// rd_str.cpp
// 24/7/98
// Demo of multi-file programs with a very small string library!
// Ken Brownsey
#include "pch.h"
#include <iostream>
#include <string.h>
#include "rd_str.h"
using namespace std;
char
*Read_String() {
	char	*Result;
	char	Buffer[200];

	cin >> Buffer;
	Result = new char[strlen(Buffer) + 1];
	strcpy_s(Result, strlen(Buffer) + 1 , Buffer);
	return(Result);
}
