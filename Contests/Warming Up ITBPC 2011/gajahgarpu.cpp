#include <cstdio>
#include <algorithm>
using namespace std;

int n,a,b,hasil=-1;
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &a, &b);
        hasil=max(hasil,a+b);
    }
    printf("%d\n", hasil);
    return 0;
}
