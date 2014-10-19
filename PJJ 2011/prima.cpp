#include <algorithm>
#include <cstdio>
#include <bitset>
using namespace std;

int prima[100200];
int teskes;
bitset<1000200> bs;
int main() {
    bs.set();
    bs[0]=0;bs[1]=0;
    for(int i=2; i*i<=1000200; i++) {
        for(int j=i*i; j<=1000200; j+=i) bs[j] = 0;
    }
    for(int i=2,ctr=0; i<=1000000; i++) {
        if(bs[i]) {
            prima[ctr]=i;
            ctr++;
        }
    }
    scanf("%d", &teskes);
    while(teskes--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", prima[n-1]);
    }
    return 0;
}
