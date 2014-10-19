#include <cstdio>

int t, a, b, n;
int main() {
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++) {
		scanf("%d", &n);
		for(int i = 0; i<=10; i++) {
			if(n-i >= 0 and n-i<=10) {
				printf("%d %d\n", i, n-i);
				break;
			}
		}
	}

}
