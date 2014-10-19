#include <cstdio>
using namespace std;

int n;
short memo[1000000];

short rek(int n) {
    if(n > 0 and n < 3) return n;
    if( n < 10000) {
        if( memo[n]!=0 ) return memo[n];
        return memo[n]=( rek(n/2) + rek(n/2+1) ) % 12345;
    }
    return ( rek(n/2) + rek(n/2+1) ) % 12345;
}

int main() {
    scanf("%d", &n);
    printf("%d\n", rek(n));
    return 0;
}
