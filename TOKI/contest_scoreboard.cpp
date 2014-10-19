#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
char s[100];
bool solve[120][11];
bool sub[120];
int waktu[120][11];

typedef struct {
    int id, so, ti;
} peserta;
peserta ans[101];

bool cp(peserta a, peserta b) {
    if(a.so == b.so) {
        if(a.ti == b.ti) return a.id < b.id;
        return a.so < b.so;
    }
    
    return a.so > b.so;
}

int main() {
    scanf("%d\n", &teskes);
    bool pertamax = 0;
    while(teskes--) {
        memset(waktu, 0, sizeof waktu);
        memset(solve, 0, sizeof solve);
        memset(sub, 0, sizeof sub);
        memset(ans, 0, sizeof ans);
        if(pertamax) printf("\n");
        pertamax = 1;
        while( gets(s) > 0) {
            int c, p, t, ch = 0;
            int len = strlen(s);
            if(len==0) break;
            char *str = strtok(s," ");
            int ctr = 0;
            while(str!=NULL) {
                if(ctr==0) c = atoi(str);
                if(ctr==1) p = atoi(str);
                if(ctr==2) t = atoi(str);
                if(ctr==3) {
                    if(str[0] == 'I') ch = -1;
                    else if(str[0] == 'C') ch = 1;
                }
                ctr++;
                str = strtok(NULL, " ");
            }
            sub[c]=1;
            //printf("%d %d %d %d\n", c, p, t, ch);
            if(ch==1 and !solve[c][p]) {
                waktu[c][p] += t;
                solve[c][p] = 1;
            }
            if(ch==-1 and !solve[c][p]) {
                waktu[c][p]+=20;
            }
        }
        int ctr = 0;
        R(i,1,100+1) {
            int sol = 0, t = 0;
            R(j,0,10) {
                if(solve[i][j]) sol++,t+=waktu[i][j];
            }
            if(sub[i]) {
                ans[ctr].so = sol;
                ans[ctr].ti = t;
                ans[ctr].id = i;
                ctr++;
            }
        }
        sort(ans, ans+ctr, cp);
        R(i,0,ctr) {
            printf("%d %d %d\n", ans[i].id, ans[i].so, ans[i].ti);
        }
    }
    return 0;
}
