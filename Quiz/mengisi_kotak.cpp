#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef pair<int,int> II;

int teskes;
int n;
char m[15][15];

void dfs(int a, int b) {
    if( a >= 0 and a < n and b >= 0 and b < n and m[a][b] == '.') {
        for(char i = 'A'; i<='Z'; i++) {
            //atas
            if(a > 0 and m[a-1][b]==i) continue;
            //kiri
            if(b > 0 and m[a][b-1]==i) continue;
            //kanan
            if(b < n-1 and m[a][b+1]==i) continue;
            //bawah
            if(a < n-1 and m[a+1][b]==i) continue;
            m[a][b]=i; break;
        }
        //dfs(a,b+1);
        //dfs(a+1,b);
    }
}

int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%s", m[i]);
    int posx = 0, posy = 0;
    R(i,0,n) R(j,0,n) if(m[i][j]=='.') dfs(i,j);
    R(i,0,n) printf("%s\n", m[i]);
    return 0;
}
