#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, Q;

int p[1000111], senyawa[1000111];
int sum = 0;
char s[100];

int set_num = 0, bebas = 0;
int x, y;

int find(int a) {
    if(p[a]==a) return a;
    return p[a] = find(p[a]);
}

void join(int a, int b) {
     int x = find(a), y = find(b);
     if(x!=y) {
         if(senyawa[x]==1) bebas--;
         if(senyawa[y]==1) bebas--;
         if(senyawa[x]==1 and senyawa[y]==1) set_num++;
         if(senyawa[x]!=1 and senyawa[y]!=1) set_num--;
         if(senyawa[x] > senyawa[y]) {
             p[y] = p[x];
             senyawa[x]+=senyawa[y];
         } else {
             p[x] = p[y];
             senyawa[y]+=senyawa[x];
         }
     }
}
int sampah;
int main() {
    scanf("%d%d", &n, &Q);
    R(i,0,n+3) {
        p[i] = i;
        senyawa[i] = 1;
    }
    bebas = n, set_num = 0;
    R(i,0,Q) {
        scanf("%s", &s);
        if(s[0]=='G') {
            scanf("%d%d", &x, &y);
            join(x,y);
        } else
        if(s[1]=='1') {
            printf("%d\n", set_num);
        } else
        if(s[1]=='2') {
            printf("%d\n", bebas);
        } else
        if(s[1]=='3') {
            int x;
            scanf("%d", &x);
            printf("%d\n", senyawa[find(x)]);
        } else scanf("%d", &sampah);
    }
    return 0;
}
