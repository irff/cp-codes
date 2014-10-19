#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char awal[300][300],m[1200][1200];
int bar,kol,tertutup;

void flood(int i, int j) {
    if(i>=0 and i<bar and j>=0 and j<kol and m[i][j]=='.') {
        m[i][j]='x';
        flood(i-1,j);
        flood(i,j+1);
        flood(i+1,j);
        flood(i,j-1);
    }
}

int main() {
    scanf("%d%d", &bar,&kol);
    R(i,0,bar) {
        scanf("%s", awal[i]);
    }
    R(i,0,4*bar) R(j,0,4*kol) m[i][j]='.';
    R(i,0,bar) {
        R(j,0,kol) {
            if(awal[i][j]=='/') {
                m[i*4][j*4+3]='x';
                m[i*4+1][j*4+2]='x';
                m[i*4+2][j*4+1]='x';
                m[i*4+3][j*4]='x';
            } else if(awal[i][j]=='\\') {
                m[i*4][j*4]='x';
                m[i*4+1][j*4+1]='x';
                m[i*4+2][j*4+2]='x';
                m[i*4+3][j*4+3]='x';
            }
        }  
    }
    bar*=4; kol*=4;
    
    printf("diperbesar:\n");
    R(i,0,bar) printf("%s\n", m[i]);
    
    R(i,0,bar) if(m[i][0]=='.') flood(i,0);
    R(i,0,kol) if(m[0][i]=='.') flood(0,i);
    R(i,0,bar) if(m[i][kol-1]=='.') flood(i,kol-1);
    R(i,0,kol) if(m[bar-1][i]=='.') flood(bar-1,i);
    printf("digrepesi:\n");
    R(i,0,bar) printf("%s\n", m[i]);
    
    R(i,0,bar) R(j,0,kol) {
          if(m[i][j]=='.') {
              tertutup++;
              flood(i,j);
          }
    }
    
    printf("%d\n", tertutup);
    
    return 0;
}
