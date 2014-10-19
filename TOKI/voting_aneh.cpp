#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, m, x, ctr, i, pos, sisa;
int a[10111];

int main() {
    scanf("%d%d%d", &n, &m, &x);
    
    R(i,0,n) a[i] = i+1;
    
    sisa = n;
    pos = 0;
    
    while(sisa != 1) {
        ctr = x % ((sisa-1)*m+1);
        
        if(ctr==0) ctr = (sisa-1)*m+1;
        
        if(ctr==1) ctr = 0;
        else ctr = (ctr + m - 2) / m;
        
        pos = (pos + ctr) % sisa;
        sisa--;
        R(i,pos,sisa) a[i] = a[i+1];
        
        pos = pos % sisa;
    }
    printf("%d\n", a[0]);
    
    return 0;
}
