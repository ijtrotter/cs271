#include <stdio.h>


int printb(char m) {
	int i;
	for ( i = 7 ; i >= 0 ; i--) {
		int bit = (m >> i) & 1;
		printf("%d", bit);
	}
	printf("\n");
	return 0;
}


int main() {
	int f = 255;
	printb(f);
	return 0;
}
