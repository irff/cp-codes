#include <cstdio>
#include <algorithm>
using namespace std;

int nbebek, nisi=0, nkandang, now=-1, total=0,maks=-1,ki=0,ka=0;
bool k[1000200];
int main() {
    scanf("%d%d", &nbebek, &nkandang);
    for(int i=0; i<nbebek; i++) {
        int num;
        scanf("%d", &num);
        if(!k[num]){
            k[num]=1;
            total+=num;
            nisi++;
        }
    }
    ka=nisi;
    for(int i=1; i<=nkandang; i++) {
        if(k[i]) {
            //kalo ada isinya
            total=total-ka+ki;
            ki++; ka--;
        } else {
            // kalo kosong
            total=total-ka+ki;
            if(total > maks) now=i,maks=total;
        }
    }
    printf("%d\n", now);
    return 0;
}
