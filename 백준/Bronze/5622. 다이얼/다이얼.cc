#include <stdio.h>

int main() {
	char a[16]; int t = 0;
	scanf("%s", a);

	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] >= 65 && a[i] <= 67)
			t += 3;
		else if (a[i] >= 68 && a[i] <= 70)
			t += 4;
		else if (a[i] >= 71 && a[i] <= 73)
			t += 5;
		else if (a[i] >= 74 && a[i] <= 76)
			t += 6;
		else if (a[i] >= 77 && a[i] <= 79)
			t += 7;
		else if (a[i] >= 80 && a[i] <= 83)
			t += 8;
		else if (a[i] >= 84 && a[i] <= 86)
			t += 9;
		else if (a[i] >= 87 && a[i] <= 90)
			t += 10;
	}

	printf("%d", t);
}