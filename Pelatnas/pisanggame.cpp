#include <cstdio>
#include <algorithm>
using namespace std;

char m[1200][1200];
int n,maks=0;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%s", m[i]);
    for(int i=1; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(m[i][j]=='.') {
                if(m[i-1][j-1]=='.') m[i-1][j-1]='X'; 
                else if(m[i-1][j]=='.') m[i-1][j]='X';
                else if(m[i-1][j+1]=='.') m[i-1][j+1]='X';
                else m[i][j]='X';
            }
        }
        if(i==n-1) for(int j=0; j<n; j++) if(m[i][j]=='.') maks++;
    }
    printf("%d\n", maks);
    return 0;
}
