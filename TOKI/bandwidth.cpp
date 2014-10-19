#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

bool adj[10][10];
char s[100];
int sol[10], c = 0;
int uk[10];
char perm[10][40400][10], x[10];
int main() {
    R(k,0,9) {
        c = 0;
        R(i,0,k) x[i] = i+'A';
        strcpy(perm[k][c],x);
        c++;
        while(next_permutation(x,x+k)) {
            strcpy(perm[k][c],x);
            c++;
        }
        uk[k] = c;
    }
    while(scanf("%s", &s) > 0) {
        if(s[0] == '#') break;
        char *str = strtok(s, ";");
        int n = 0;
        while(str!=NULL) {
            int len = strlen(str);
            n = max(n,str[0]-'A');
            R(i,2,len) {
                adj[str[0]-'A'][str[i]-'A'] = 1;
                n = max(n,str[i]-'A');
            }
            str = strtok(NULL, ";");
        }
        n++;
        int ans = 2000111222, now = 0;
        R(k,0,uk[n]) {        
            now = 0;
            R(i,0,n) {
                R(j,0,n) {
                    if(adj[perm[n][k][i]-'A'][perm[n][k][j]-'A']) {
                        now = max(now, abs(i-j));
                    }
                }
            }
            if(ans > now) {
                ans = min(ans, now);
                R(i,0,n) sol[i] = x[i];
            }
        }
        R(i,0,n) printf("%c ", sol[i]);
        printf("-> %d\n", ans);
    }
    return 0;
}
