#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, len=0,now=0,ctr=0, maxstep=0,m[200][200], pkt[20], bar, kol;
char s[20000][100];

void fill(int a, int b, int step) {
    int pan = pkt[maxstep-step+1];
    int pen = pkt[maxstep-step];
    
    if(step>=len) {
        R(i,a,a+pan) {
            R(j,b,b+pan) {
                m[i][j]=1;
            }
        }
        return ;
    }
    if(s[now][step]=='0') fill(a, b, step+1);
    if(s[now][step]=='1') fill(a, b+pen, step+1);
    if(s[now][step]=='2') fill(a+pen, b, step+1);
    if(s[now][step]=='3') fill(a+pen, b+pen, step+1);
}

int main() {
    pkt[0]=1;
    R(i,1,15) pkt[i]=pkt[i-1]*2;
    while(scanf("%s", &s[ctr])>0) {
        if(s[ctr][0]=='E') break;
        ctr++;
    }
    scanf("%d%d", &bar, &kol);
    n = max(bar, kol);
    R(i,0,12) {
        if(pkt[i]>=n) { maxstep=i; n = pkt[i]; break; }
    }
    R(i,0,ctr) {
        now = i;
        len = strlen(s[i]);
        fill(0,0,1);
    }
    R(i,0,bar)
        R(j,0,kol) {
            printf("%d%c", m[i][j], (j==kol-1)?'\n':' ');
        }
    return 0;
}
