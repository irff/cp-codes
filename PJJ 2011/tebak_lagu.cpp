#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
int n;
char sa[300], s[300];
vector<int> v[25];
int lagu_lookup(char a, char b) {
    if(a=='c' and b=='.') return 0;
    if(a=='c' and b=='#') return 1;
    if(a=='d' and b=='.') return 2;
    if(a=='d' and b=='#') return 3;
    if(a=='e' and b=='.') return 4;
    if(a=='f' and b=='.') return 5;
    if(a=='f' and b=='#') return 6;
    if(a=='g' and b=='.') return 7;
    if(a=='g' and b=='#') return 8;
    if(a=='a' and b=='.') return 9;
    if(a=='a' and b=='#') return 10;
    if(a=='b' and b=='.') return 11;
    
    if(a=='C' and b=='.') return 12;
    if(a=='C' and b=='#') return 13;
    if(a=='D' and b=='.') return 14;
    if(a=='D' and b=='#') return 15;
    if(a=='E' and b=='.') return 16;
    if(a=='F' and b=='.') return 17;
    if(a=='F' and b=='#') return 18;
    if(a=='G' and b=='.') return 19;
    if(a=='G' and b=='#') return 20;
    if(a=='A' and b=='.') return 21;
    if(a=='A' and b=='#') return 22;
    if(a=='B' and b=='.') return 23;
    
}

int main() {
    scanf("%s", &sa);
    int lena=strlen(sa);
    int mins = 25, maks=-1;
    for(int i=0; i<lena; i+=2) {
        int x = lagu_lookup(sa[i], sa[i+1]);
        v[0].push_back(x);
        mins = min(mins, x);
        maks = max(maks, x);
    }
    lena/=2;
    for(int i=0; i<lena; i++) v[0][i]-=mins;
    maks-=mins;  int ctr=1;
    for(int i=1; i+maks<=23; i++,ctr++) {
        for(int j=0; j<lena; j++) {
            v[ctr].push_back(v[0][j]+i);
        }
    }
    /*for(int i=0; i<ctr; i++) {
        for(int j=0; j<lena; j++) printf("%d ", v[i][j]);
        printf("\n");
    }*/
    scanf("%d", &n); bool ketemu = 0;
    for(int ii=1; ii<=n; ii++) {
        scanf("%s", &s);
        vector<int> lagu;
        int len = strlen(s);
        for(int i=0; i<len; i+=2) lagu.push_back( lagu_lookup(s[i], s[i+1]) );
        len/=2;
        //for(int i=0; i<len; i++) printf("%d ", lagu[i]);
        //printf("\n");
        bool jadi=0;
        for(int i=0; i<ctr; i++) {
            for(int j=0; j+lena<=len; j++) {
                jadi=1;
                for(int k=0; k<lena; k++) {
                    if(lagu[j+k]!=v[i][k]) { jadi=0; break; }
                }
                if(jadi) break;
            }
            if(jadi) break;
        }
        if(jadi and !ketemu) { printf("%d\n", ii); ketemu=1; }
    }
    if(!ketemu) printf("#\n");
    return 0;
}
