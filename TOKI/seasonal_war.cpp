#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
char m[30][30];

void dfs(int a, int b) {
    if(a>=0 and a<n and b>=0 and b<n and m[a][b]=='1') {
        m[a][b] = '0';
        dfs(a-1,b-1);
        dfs(a-1,b);
        dfs(a-1,b+1);
        dfs(a,b+1);
        
        dfs(a+1,b+1);
        dfs(a+1,b);
        dfs(a+1,b-1);
        dfs(a,b-1);
    }
}

int main() {
    int kasus = 0;
    while(scanf("%d", &n) > 0) {
        R(i,0,n) scanf("%s", &m[i]);
        int com = 0;
        R(i,0,n) {
          R(j,0,n) {
            if(m[i][j]=='1') {
              com++;
              dfs(i,j);
            }
          }
        }
        printf("Image number %d contains %d war eagles.\n", ++kasus, com);
    }
    return 0;
}
