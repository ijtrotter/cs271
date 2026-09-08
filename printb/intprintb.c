#include <stdio.h>


int printb(int m) {
	int p = 1;
	int ans = 0;

	while ( m > 0 ) {
		/*printf("%d\n", m & 1);*/
		ans += (m & 1) * p;
		p *= 10;

		m = m >> 1;
	}
	printf("%d\n", ans);
	return ans;
}


int main() {
	int f = 13;
	printb(f);
	return 0;
}
