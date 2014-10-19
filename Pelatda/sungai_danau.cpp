#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define fs first
#define sc second

typedef long long LLD;
typedef pair<int,int> PII;
typedef pair<int,PII> PIE;
typedef vector<PIE> VIE;
const int INF = 2000111222;

VIE danau;
int bar, kol, d[120][120], ndanau = 0;
char m[120][120], color, now, s[120][120], newcolor = 'a';

void dfs(PIE tadi, int h, int a, int b) {
    VIE v; PIE tmp = PIE(h, PII(a,b));
    if(a > 0) v.push_back(PIE(d[a-1][b],PII(a-1,b)));
    if(a < bar-1) v.push_back(PIE(d[a+1][b],PII(a+1,b)));
    if(b > 0) v.push_back(PIE(d[a][b-1],PII(a,b-1)));
    if(b < kol-1) v.push_back(PIE(d[a][b+1],PII(a,b+1)));
    int len = v.size();
    sort(v.begin(), v.end());
    if(!v.empty() and v[0] == tadi) {
        m[a][b] = color;
        R(i,1,len) {
            int pa = v[i].sc.fs, pb = v[i].sc.sc;
            if(v[i].fs > h and m[pa][pb]=='\0') {
                //printf("dari:%d-%d ke:%d-%d = %d -> %d (%c)\n", a,b, pa, pb, h, v[i].fs, color);
                dfs(tmp,v[i].fs, pa, pb);
            }
        }
    }
}

void fill(int h, int a, int b) {
    m[a][b] = color;
    VIE v;
    PIE tmp = PIE(h,PII(a,b));
    if(a > 0) v.push_back(PIE(d[a-1][b],PII(a-1,b)));
    if(a < bar-1) v.push_back(PIE(d[a+1][b],PII(a+1,b)));
    if(b > 0) v.push_back(PIE(d[a][b-1],PII(a,b-1)));
    if(b < kol-1) v.push_back(PIE(d[a][b+1],PII(a,b+1)));
    sort(v.begin(), v.end());
    int len = v.size();
    R(i,0,len) {
        int pa = v[i].sc.fs, pb = v[i].sc.sc;
        //printf("dari:%d-%d ke:%d-%d = %d -> %d (%c)\n", a,b, pa, pb, h, v[i].fs, color);
        if(v[i].fs > h and m[pa][pb]=='\0') dfs(tmp, v[i].fs, pa, pb);
    }
    color++;
    
}

void flood(int a, int b) {
    if(a >= 0 and a < bar and b >= 0 and b < kol and m[a][b] == now) {
        m[a][b] = '#';
        s[a][b] = newcolor;
        flood(a-1,b);
        flood(a,b+1);
        flood(a+1,b);
        flood(a,b-1);
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) R(j,0,kol) { scanf("%d", &d[i][j]); }
    R(i,0,bar) R(j,0,kol) {
        bool jadi = 1;
        if(i>0 and d[i-1][j] < d[i][j]) jadi = 0;
        if(i<bar-1 and d[i+1][j] < d[i][j]) jadi = 0;
        if(j>0 and d[i][j-1] < d[i][j]) jadi = 0;
        if(j<kol-1 and d[i][j+1] < d[i][j]) jadi = 0;
        if(jadi) {
            danau.push_back(PIE(d[i][j],PII(i,j)));
        }
    }
    ndanau = danau.size();
    color = 'a';
    //sort(danau.begin(), danau.end());
    R(i,0,ndanau) {
        fill(danau[i].fs, danau[i].sc.fs, danau[i].sc.sc);
    }
    /*
    R(i,0,ndanau) {
        printf("%d %d %d\n", danau[i].fs, danau[i].sc.fs, danau[i].sc.sc);
    }
    */
    color = 'a';
    R(i,0,bar) {
        R(j,0,kol) {
            if(s[i][j] == '\0') {
                now = m[i][j];
                flood(i,j);
                newcolor++;
            }
        }
    }

    R(i,0,bar) { R(j,0,kol) printf("%c", s[i][j]); printf("\n"); }
    
    return 0;
}
