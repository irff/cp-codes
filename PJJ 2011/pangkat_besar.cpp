#include <cstdio>

const int MOD=1000000;

int a, b;
long long c;

long long pangkat(int a, int b) {
    if(b==0) return 1;
    long long x = pangkat(a,b/2)%MOD;
    if(b%2) return x*x%MOD*a%MOD;
    return x*x%MOD;
}

int main() {
    scanf("%d%d", &a, &b);
	int x = 1;
	bool lebih=0;
    for(int i=0; i<b; i++) {
	    x*=a;
		if(x>=1000000) {
		    lebih=1; break;
		}
	}
	c = pangkat(a,b)%MOD;
    if(!lebih) printf("%lld\n", c);
	else {
	    if(c>=100000) ; //diem
		else if(c>=10000) printf("0");
		else if(c>=1000) printf("00");
		else if(c>=100) printf("000");
		else if(c>=10) printf("0000");
		else printf("00000");
		printf("%lld\n", c);
	}
    return 0;
}
