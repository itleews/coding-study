#include <stdio.h>

int main() {
	int a = 8;
	double b = 1.0;
	char c = 'c';
	int d[5];

	printf("a의 값 : %d, size : %ld\n", a, sizeof(a));
	printf("b의 값 : %lf, size : %ld\n", b, sizeof(b));
	printf("c의 값 : %c, size : %ld\n", c, sizeof(c));
	printf("d의 값 : 배열, size : %ld\n", sizeof(d));
}
