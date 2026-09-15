#include <stdio.h>

#define CHOICE(e,f,g) ((e & f) | ((~e) & g))
#define MEDIAN(a,b,c) ((a | b) & (a | c) & (b | c))
#define ROTATE(m,n) ((m >> (n % 32)) | (m << ((32-n) % 32)))
#define LROTATE(m,n) ((m << (n % 32)) | (m >> ((32-n) % 32)))
