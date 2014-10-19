#include <cstdio>
#include <cstring>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar,kol,hasil=0;
char m[1200][1200];
int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) scanf("%s", m[i]);
    
    R(i,0,bar) {
        char prev=m[i][0];
        int n=1;
        R(j,1,kol) {
            if(m[i][j]!=prev) {
                if(n>2) hasil+=(n-2);
                n=1;
                prev=m[i][j];
            } else n++;
        }
        if(n>2) hasil+=(n-2);
    }
    R(i,0,kol) {
        char prev=m[0][i];
        int n=1;
        R(j,1,bar) {
            if(m[j][i]!=prev) {
                if(n>2) hasil+=(n-2);
                n=1;
                prev=m[j][i];
            } else n++;
        }
        if(n>2) hasil+=(n-2);
    }
    
    printf("%d\n", hasil);
    return 0;
}
