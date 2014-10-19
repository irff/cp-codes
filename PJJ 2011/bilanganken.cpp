#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n,ke,a[100200];
int main() {
    scanf("%d%d", &n,&ke);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a,a+n,greater<int>());
    printf("%d\n", a[ke-1]);

}
