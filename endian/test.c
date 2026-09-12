#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t bytes[64];
	char *f_name = "my_file.txt";
	FILE *fp = fopen(f_name, "r");
	if (fp == NULL) {
		printf("failure yo\n");
		exit(1);
	}
	fread(bytes, 1, 64, fp);
	return 0;
}
