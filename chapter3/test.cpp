#include <cstdio>
#include <algorithm>
#include <iostream>

int main() {
	char str[100];
	int num = 12345;
	sprintf(str, "%d", num);
	printf("%s", str);
	return 0;
}

