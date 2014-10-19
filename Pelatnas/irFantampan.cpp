#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

struct fanatic {
    int a,b,h;
} ;

fanatic fans[100200];
int nfans,ntampan,maks=0;
int salon[100200];
int main() {
    scanf("%d%d", &nfans, &ntampan);
    R(i,1,ntampan+1) scanf("%d", &salon[i]);
    R(i,0,nfans) {
        scanf("%d%d%d", &fans[i].a,&fans[i].b,&fans[i].h);
    }
    R(i,1,ntampan+1) {
        int res=-salon[i];
        R(j,0,nfans)
            if(fans[j].a <=i and fans[j].b >= i) res+=fans[j].h;
        maks=max(maks,res);
    }
    printf("%d\n", maks);
    return 0;
}
