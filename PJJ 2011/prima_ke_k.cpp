#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

int teskes, n;
vector<int> v;
bitset<1000111> bs;
int main() {
    bs.set();
    bs[0] = 0, bs[1] = 0;
    for(int i = 2; i*i<=1000000; i++) {
        for(int j=i*i; j<=1000000; j+=i) {
            bs[j] = 0;
        }
    }
    for(int i = 2; i<=1000000; i++) {
        if(bs[i]) v.push_back(i);
    }
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        printf("%d\n", v[n-1]);
    }
    return 0;
}
