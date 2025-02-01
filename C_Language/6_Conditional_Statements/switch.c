#include <stdio.h>

int main() {
	
	int op = 0;
	int a = 0;
	scanf("%d", &op);
	
	switch(op) {
		
		case 1 :
			a = 1;
			break;
		case 2 :
			a = 2;
			break;
		case 3 :
			a = 3;
			break;
		case 4 :
			a = 4;
			break;
		case 5 :
			a = 5;
			break;
		default :
			a = 99;
			break;
	}

	printf("결과 : %d\n", a);

}
