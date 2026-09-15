#include <stdio.h>

#define CHOOSE(e,f,g) ((e & f) | ((~e) & g))
#define MEDIAN(a,b,c) (((a | b) & ((a) | c)) & (b | c))
#define ROTATE(m,n) ((m >> n) | (m << (8-n)))

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
	int e = 15;
	int f = 51;
	int g = 85;

	unsigned int n = 3;
	unsigned int m = 45;

	printb(CHOOSE(e,f,g));
	printb(MEDIAN(e,f,g));
	printb(ROTATE(m,n));
	return 0;
}
