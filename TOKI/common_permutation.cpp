#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char sa[1200], si[1200];
int ca[300], ci[300];
int main() {
    while(gets(sa) > 0) {
        gets(si);
        int lena = strlen(sa), leni = strlen(si);
        R(i,0,lena) ca[ sa[i] ]++;
        R(i,0,leni) ci[ si[i] ]++;
        R(i,'a','z'+1) {
            R(j,0,min(ca[i],ci[i])) printf("%c", i);
            ca[i] = 0, ci[i] = 0;
        }
        printf("\n");
    }

    return 0;
}
