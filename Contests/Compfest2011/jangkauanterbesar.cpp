#include <cstdio>
#include <cstdlib>
#include <cmath>

int teskes,nkelas,nsiswa,now,maks;
int a[50];
int main () {
    scanf("%d", &teskes);
    while(teskes--) {
        now=1,maks=0;
        scanf("%d", &nkelas);
        for(int i=0; i<nkelas; i++) {
            scanf("%d", &nsiswa);
            for(int j=0; j<nsiswa; j++) scanf("%d", &a[j]);
            for(int j=0; j<nsiswa; j++) {
                for(int k=j; k<nsiswa; k++) {
                    if( abs(a[j]-a[k]) > maks) maks=abs(a[j]-a[k]),now=i+1;
                }
            }
        }
        printf("%d\n", now);
    }
    return 0;
}
