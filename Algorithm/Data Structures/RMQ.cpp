// Range Minimum Query
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAKS 10000
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
int a[MAKS],tree[MAKS];
int n,teskes,awal,akhir;

void build(int ix,int ki, int ka){
     if(ki==ka) { tree[ix]=ki; return ; }
     build(ix*2+1,ki,(ki+ka)/2);
     build(ix*2+2,(ki+ka)/2+1,ka);
     
     tree[ix]=a[tree[ix*2+1]] < a[tree[ix*2+2]] ? tree[ix*2+1] : tree[ix*2+2];
}

int req(int ix,int ki, int ka, int le, int ri){
    if(ki<le) ki=le;
    if(ka>ri) ka=ri;
    if(ki>ka) return -1;
    if(ki==le and ka==ri) return tree[ix];
    
    int lc = req(ix*2+1,ki,ka,le,(le+ri)/2);
    int rc = req(ix*2+2,ki,ka,(le+ri)/2+1,ri);
    
    if( lc == -1 ) return rc;
    if( rc == -1 ) return lc;
    
    return a[lc] < a[rc] ? tree[lc] : tree[rc];
}
int main(){
    scanf("%d%d", &n,&teskes);
    R(i,0,n) scanf("%d", &a[i]);
    build(0,0,n-1);
    while(teskes--){
        scanf("%d%d", &awal, &akhir);
        printf("%d\n", req(0,awal,akhir,0,n-1));
    }
    return 0;
}
