#include <stdio.h>

int main() {

	int a = 10;
	int b = 0;

	while(a) {
		a--;
		printf("a : %d\n", a);
	}

	do {
		b++;
		printf("b: %d\n", b);
	} while (b < 10);

	return 0;

}
