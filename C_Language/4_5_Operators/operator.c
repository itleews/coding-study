#include <stdio.h>

int main() {
	int a = 3;
	int b = 7;
	int c = 6;
	int d = 0;

	printf("%d\n", a == b);
	printf("%d\n", a != b);
	printf("%d\n", a || b);
	printf("%d\n", a || d);
	printf("%d\n", a && b);
	printf("%d\n", a && d);
}
