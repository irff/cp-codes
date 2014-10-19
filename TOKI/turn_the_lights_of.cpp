#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char name[1000];
char m[20][20];
bool ori[20][20], s[20][20];
int main() {
    scanf("%s", &name);
    while(strcmp(name,"end")!=0) {
        R(i,0,10) {
            scanf("%s", &m[i]);
        }
        R(i,0,10) {
            R(j,0,10) {
                if(m[i][j]=='O') ori[i][j]=1;
                else ori[i][j] = 0;
            }
        }
        //R(i,0,10) R(j,0,10) printf("%d%c", ori[i][j], j==9?'\n':' ');
        
        int mins = 2000111222;
        R(i,0,(1<<10)) {
            //printf("%d\n", i);
            int pencet = 0;
            R(j,0,10) R(k,0,10) s[j][k] = ori[j][k];
            R(k,0,10) {
                if(i&(1<<k)) {
                    pencet++;
                    s[0][k-1] = !s[0][k-1];
                    s[0][k]   = !s[0][k];
                    s[0][k+1] = !s[0][k+1];
                    s[1][k]   = !s[1][k];
                }
            }
            R(j,1,10) {
                R(k,0,10) {
                    if(s[j-1][k]) {
                        pencet++;
                        s[j][k-1] = !s[j][k-1];
                        s[j][k]   = !s[j][k];
                        s[j][k+1] = !s[j][k+1];
                        s[j+1][k] = !s[j+1][k];
                    }
                }
            }
            bool bisa = 1;
            R(k,0,10) {
                if(s[9][k]) bisa = 0;
            }
            if(bisa) mins = min(pencet, mins);
        }
        
        if(mins>100) printf("%s -1\n", name);
        else printf("%s %d\n", name, mins);
        scanf("%s", &name);
    }
    return 0;
}
