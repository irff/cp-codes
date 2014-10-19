#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef pair<int,int> II;

int k, n;
int main() {
    scanf("%d%d", &k, &n);
    int mins = 0, maks = -2000111222;
    R(i,0,n) {
        int num; scanf("%d", &num);
        maks = max(maks, max(num, k-num));
        mins = max(mins, min(num, k-num));
    }
    printf("%d %d\n", mins, maks);
    return 0;
}
