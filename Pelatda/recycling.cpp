#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[200][100], x[100];
int score[200], ctr = 0;

int decode1(char a) {
    if(a=='r') return 0;
    if(a=='o') return 1;
    if(a=='y') return 2;
    if(a=='g') return 3;
    if(a=='b') return 4;
}

int decode2(char a) {
    if(a=='P') return 0;
    if(a=='G') return 1;
    if(a=='A') return 2;
    if(a=='S') return 3;
    if(a=='N') return 4;
}

int main() {
    while(scanf("%s", &x) > 0) {
        if(x[0] == 'e') {
            int maks = -1, pos = 0;
            R(i,0,ctr) {
                int now = 0;
                R(j,0,ctr) {
                    R(k,0,5) {
                        if(s[i][k]==s[j][k]) now++;
                    }
                }
                if(maks < now) maks = now, pos = i;
            }
            printf("%d\n", pos+1);
            ctr = -1;
        } else
        if(x[0]=='#') {
            break;
        } else {
            s[ctr][decode1(x[0])] = decode2(x[2]);
            s[ctr][decode1(x[4])] = decode2(x[6]);
            s[ctr][decode1(x[8])] = decode2(x[10]);
            s[ctr][decode1(x[12])] = decode2(x[14]);
            s[ctr][decode1(x[16])] = decode2(x[18]);
        }
        ctr++;
    }
    return 0;
}
