#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

int n;

bitset<1000111> bs;
void sieve() {
    bs.set(); bs[0]=0,bs[1]=0;
    for(int i=2; i*i<=n; i++)
        for(int j=i*i; j<=n; j+=i) bs[j]=0;

}
int main() {
    scanf("%d", &n);
    sieve();
    for(int i=2; i<=n; i++) {
        if(bs[i] and bs[n-i]) {
            printf("%d = %d + %d\n", n, i, n-i);
            break;
        }
    }
    printf("x");
    return 0;
}
