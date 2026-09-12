#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main() {
	uint8_t buffer[64];
	size_t i;
	size_t rbuffer;
	
	char *f_name = "lipsum.txt";
	FILE *fp = fopen(f_name, "r");
	if (fp == NULL) {
		fprintf(stderr, "file failed to open..probably not real: \"%s\", exiting...\n", f_name);
		exit(1);
	}

	
	do {
		rbuffer = fread(buffer, 1, 64, fp);
		for (i = 0 ; i < rbuffer ; i++ ) {
			if (i != 0) {
				if (i % 4 == 0) { printf(" "); }
				if (i % 16 == 0) { printf("\n"); }
			}
			printf("%02x", buffer[i]);
		}
		printf("\n");
	
	} while ( rbuffer == 64 );
	
	printf("\n");
	return 0;
}
