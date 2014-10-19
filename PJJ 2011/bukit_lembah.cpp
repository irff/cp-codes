#include <cstdio>
#include <algorithm>
using namespace std;

int tadi,naik=-1, awal=0, now=0, selisih=0;
int tadib, turun=-1, awalb=0;
int main() {
    int n,ctr=0;
    while(scanf("%d", &n)>0) {
        if(naik==-1) awal=n, tadi=n, naik=1;
        else {
            if(n >= tadi) {
                selisih=max(selisih,n-awal);
                tadi=n;
            } else {
                awal=n;
                tadi=n;
            }
        }
        if(turun==-1) awalb=n,tadib=n,turun=1;
        else {
            if( n <= tadib) {
                selisih=max(selisih, awalb-n);
                tadib=n;
            } else {
                awalb=n;
                tadib=n;
            }
        }
        //printf("--%d\n", awalb);
    }
    printf("%d\n", selisih);

}
