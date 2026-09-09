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
	int x = 2;
	int y = 3;
	printb(x);
	printb(y);

	printf("Result \n");
	printb(~y);
	return 0;
}
