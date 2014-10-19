#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
int n;
int quad[20000],ten[10];
int ndigit(int x) {
    if(x<10) return 1;
    if(x<100) return 2;
    if(x<1000) return 3;
    if(x<10000) return 4;
    if(x<100000) return 5;
    if(x<1000000) return 6;
    if(x<10000000) return 7;
    if(x<100000000) return 8;
}
int main() {
    ten[0] = 1;
    R(i,1,10) ten[i] = ten[i-1] * 10;
    while(scanf("%d", &n) > 0) {
        R(i,0,20000) {
            int num = i*i;
            if(num>=ten[n]) break;
            int a = num%ten[n/2];
            int b = num/ten[n/2];
            if(a+b == i) {
                R(i,0,n-ndigit(num)) printf("0");
                printf("%d\n", num);
            }
        }
    }
    return 0;
}
