#include <stdio.h>

int main() {
	int a = 2 + 3;
	int b = 2 - 1;

	int c = 3;
	int d = 4;

	int f = c + d;

	int e = 1;

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n\n", f);

	printf("%d\n", e++); // 1에서 1을 더함. 하지만 다음 줄에 적용. 결과 1
	printf("%d\n", ++e); // 2가 내려옴. 그리고 바로 1을 더함. 결과 3
	printf("%d\n", e--); // 3이 내려옴. 하지만 다음 줄에 -1을 적용. 결과 3
	printf("%d\n", --e); // 2가 내려옴. 그리고 바로 1을 뺌. 결과 1
}
