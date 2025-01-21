#include <stdio.h>

void printBinary(char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
	char a = 8;
	char b = 4;
	char c = 24;
	char d = 0b00001111;

	printf("%d\n", a | b);
	printf("%d\n", a & b);
	printf("%d\n", c << 1);
	printf("%d\n", c >> 1);
	printBinary(~d);
	printf("\n");

}
