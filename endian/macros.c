#include <stdint.h> 

#define CHOICE(e,f,g) ((e & f) | ((~e) & g))
#define MEDIAN(a,b,c) ((a | b) & (a | c) & (b | c))
#define ROTATE(m,n) ((m >> (n % 32)) | (m << ((32-n) % 32)))
#define LROTATE(m,n) ((m << (n % 32)) | (m >> ((32-n) % 32)))

int main(){
	uint32_t e = 0xAA, f = 0x55, g = 0x66;
	CHOICE(e,f,g);
	MEDIAN(e,f,g);
	ROTATE(e,f);
	return 0;
}
