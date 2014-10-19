#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n,k,tinggi,maks;
long long total;
int main(){
    total=2;
    maks=-1;
    scanf("%d%d", &n,&k);
    R(i,1,n+1){
        scanf("%d", &tinggi);
        maks=max(maks,tinggi);
        if(i%k==0 or i==n){
            total++;
            total+=maks;
            maks=-1;
        }
    }
    printf("%lld\n", total-1);
    return 0;
}
