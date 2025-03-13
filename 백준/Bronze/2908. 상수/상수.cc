#include <stdio.h>

int main() {
	char a[4], b[4];
	scanf("%s %s", a, b);
	int A = 100 * (a[2] - '0') + 10 * (a[1] - '0') + a[0] - '0';
	int B = 100 * (b[2] - '0') + 10 * (b[1] - '0') + b[0] - '0';
	if (A > B)
		printf("%d", A);
	else
		printf("%d", B);
}