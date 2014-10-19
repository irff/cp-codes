#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int glob[100];
int n, a[100];

void rek(int ke, int num) {
    if(ke > 5) {
        R(i,0,6) printf("%d%c", glob[i], i==5?'\n':' ');
        return ;
    }
    R(i,num,n) {
        glob[ke] = a[i];
        rek(ke+1,i+1);
    }
}

int main() {
    bool tamax = 0;
    while(scanf("%d", &n), n) { 
        R(i,0,n) scanf("%d", &a[i]);
        if(tamax) printf("\n");
        rek(0,0);
        tamax = 1;
    }
    return 0;
}
