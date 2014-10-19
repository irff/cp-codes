#include <cstdio>

int t, a, b;
int main() {
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++) {
		scanf("%d%d", &a, &b);
		printf("Case %d: %d\n", tc, a+b);
	}

}
