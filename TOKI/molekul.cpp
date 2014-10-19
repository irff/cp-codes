#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

bool m[1200][1200];
int n, s;
LLD aa, ab;
LLD pkt[40];

void rek(int ord, LLD a, LLD b, LLD ax, LLD ay, LLD bx, LLD by, int pos) {
    if(ax>ay or bx>by or a+ax-aa>s or b+ay-ab>s) return ;
    /*printf("%d - ", ord);
    printf("%lld ", ax);
    printf("%lld-", ay);
    printf("%lld ", bx);
    printf("%lld\n", by);
    */
    if(ord==0) {
        //printf("%lld - ", ax-aa);
        //printf("%lld\n", ay-ab);
        //printf("%lld - ", a+ax-aa);
        //printf("%lld\n", b+ay-ab);
        m[a+ax-aa][b+ay-ab] = 1;
    } else {
        LLD p = pkt[ord-1];
        if(ax <= p and ay<=p) {
            rek(ord-1, a,b,max((LLD)1,ax), max((LLD)1,ay), min(bx,p), min(by,p), 1);
        }
        if(ax <= p and ay<=3*p) {
            rek(ord-1, a,b+2*p,max((LLD)1,ax), max((LLD)2*p+1,ay)-2*p, min(bx,p), min(by,3*p)-2*p,2);
        }
        if(ax <= 2*p and ay<=2*p) {
            rek(ord-1, a+p,b+p,max(p+1,ax)-p, max(p+1,ay)-p, min(bx, 2*p)-p, min(by, 2*p)-p,3);
        }
        if(ax <= 3*p and ay<=p) {
            rek(ord-1, a+2*p,b,max(2*p+1, ax)-2*p, max((LLD)1,ay), min(bx, 3*p)-2*p, min(by, p),4);
        }
        if(ax <=3*p and ay<=3*p) {
            rek(ord-1, a+2*p,b+2*p,max(2*p+1,ax)-2*p, max(2*p+1,ay)-2*p, min(bx, 3*p)-2*p, min(by, 3*p)-2*p,5);
        }
    } 
}

int main() {
    pkt[0] = 1;
    R(i,1,40) pkt[i] = pkt[i-1]*3;
    //R(i,1,40) printf("%lld\n", pkt[i]);
    scanf("%d%d", &n, &s);
    scanf("%lld%lld", &aa, &ab);
    rek(n, 0,0,aa, ab, aa+s-1, ab+s-1,1);
    
    R(i,0,s) {
        R(j,0,s) {
            if(m[i][j]) printf("O");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}
