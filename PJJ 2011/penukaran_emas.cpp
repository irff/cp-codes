#include <cstdio>
#include <algorithm>
using namespace std;

int n, maks;

int rek(int n) {
    if( n == 0) return 0;
    return max(n, rek(n/2)+rek(n/3)+rek(n/4));
}

int main() {
    scanf("%d", &n);
    maks=rek(n);
    printf("%d\n", maks);
    scanf("\n");
    return 0;
}
