#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, h;
int main() {
    scanf("%d%d", &n, &h);
    vector<bool> v(n-h,0);
    R(i,0,h) v.push_back(1);
    R(i,0,n) printf("%d", (int)v[i]);
    printf("\n");
    while(next_permutation(v.begin(), v.end())){
        R(i,0,n) printf("%d", (int)v[i]);
        printf("\n");
    }
}
