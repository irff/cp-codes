#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;


int a, b;
int main() {
    while(scanf("%d%d", &a, &b) > 0) {
        printf("%d\n", __gcd(a,b));
    }
    return 0;
}
