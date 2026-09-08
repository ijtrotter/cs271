#include <stdio.h>

void printb(int n) {
	int counter = 0;
	
	if (n == 0) {
		printf("0");
		return;
	}

	while (n > 0) {
		printf("%d", n % 2);
		counter++;
		n = n / 2;
	}
	
	printf("\n");
}

int main() {
	printb(12);
	return 0;
}
