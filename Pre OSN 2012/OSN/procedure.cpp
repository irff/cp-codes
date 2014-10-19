#include <algorithm>
#include <cstdio>
using namespace std;

int n;
int main() {
    scanf("%d", &n);
    if(n>=10000) printf("puluhribuan");
    else if(n>=1000) printf("ribuan");
    else if(n>=100) printf("ratusan");
    else if(n>=10) printf("puluhan");
    else printf("satuan");
    printf("\n");
    return 0;
}
