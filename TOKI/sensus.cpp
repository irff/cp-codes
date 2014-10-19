#include <cstdio>
#include <algorithm>
using namespace std;
#define MAKS 1001000
#define LL long long
#define PLLL pair<LL,long>
PLLL rumah[MAKS];
long long num,maksimal,awal,akhir,minimal;
long nrumah, teskes;
int main(){
    
    scanf("%ld%ld", &nrumah, &teskes);
    for(long i=1; i<=nrumah; i++) {
        scanf("%lld", &num);
        rumah[i].first=num;
        rumah[i].second=i;
    }
    sort(rumah+1,rumah+nrumah+1);
    while(teskes--){
        maksimal=-2000000001;
        minimal=2000000001;
        scanf("%ld%ld", &awal, &akhir);
        //for(long i=1; i<=nrumah; i++) printf("%d ", rumah[i].first); printf("\n");
        //for(long i=1; i<=nrumah; i++) printf("%d ", rumah[i].second); printf("\n");
        for(long i=1; i<=nrumah; i++)
            if(rumah[i].first<=minimal and rumah[i].second>=awal and rumah[i].second<=akhir) { minimal=rumah[i].first; break; }
        for(long i=nrumah; i>=1; i--)
            if(rumah[i].first>=maksimal and rumah[i].second>=awal and rumah[i].second<=akhir) { maksimal=rumah[i].first; break; }
        printf("%lld\n", maksimal-minimal);
    }
    return 0;
}
