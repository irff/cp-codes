#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> VI;

int a[100];

// faster way for passing vector
// but should use const_iterator for traversing
int rek(const VI& v) {
    for(int i=0; i<5; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}

// passing array -> a[] or *a

void f(int a[]) {
    for(int i=0; i<4; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    VI n(5,1);
    printf("%d\n", rek(n));
    a[0] = 1; a[2] = 1;
    f(a);
    return 0;
}
