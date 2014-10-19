#include <cstdio>

int total,maks,nkucing,k,num;
int main() {
    scanf("%d%d", &nkucing, &k);
    total=2;
    for(int i=1; i<=nkucing; i++) {
        scanf("%d", &num);
        if(num > maks) maks=num;
        if(i%k==0) {
            total+=maks;
            maks=0;
        }
    }
    if(nkucing%k!=0) total+=maks;
    total+=(nkucing-1)/k;
    printf("%d\n", total);
    return 0;
}
