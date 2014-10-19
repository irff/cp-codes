#include <cstdio>

int n, total;
int maks[100],mins[100];
int ske[100],totalmins,totalmaks;
int main() {
    scanf("%d%d", &n, &total);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &mins[i], &maks[i]);
        totalmins+=mins[i];
        totalmaks+=maks[i];
    }
    if(totalmins > total or totalmaks < total) printf("NO\n");
    else {
        for(int i=0; i<n; i++) { ske[i]+=mins[i]; total-=mins[i]; }
        int x = 0;
        while(total > 0) {
            if(ske[x] < maks[x]) {
                if(ske[x]+total <= maks[x]) {
                    ske[x]+=total; total=0;
                } else {
                    total-=(maks[x]-ske[x]);
                    ske[x] = maks[x];
                }
            }
            x++; if(x==n) x=0;
        }
        printf("YES\n");
        for(int i=0; i<n; i++) printf("%d\n", ske[i]);
    }
    return 0;
}
