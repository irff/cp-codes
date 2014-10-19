#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int k, n;

int rek(int ke, int n) {

    return 0;
}

int main() {
    scanf("%d%d", &k, &n);
    
    while(k!=0 and n!=0) {
        rek(0, n);
        scanf("%d%d", &k, &n);
    }
    return 0;
}
