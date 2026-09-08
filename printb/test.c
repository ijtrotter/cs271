#include <stdio.h>

char main() {
	char m = 42;
	char p = 1;
	char ans = 0;

	while ( m > 0 ) {
		printf("%d\n", m & 1);
		ans += (m & 1) * p;
		p *= 10;
		
		m = m >> 1;
	}
	printf("%d\n", ans);

	return 0;
}
