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

II a[1000];
int k, jarak, n;
int main() {
    scanf("%d%d%d", &k, &jarak, &n);
    R(i,0,n) {
      int pos, banyak, harga;
      scanf("%d %d %d", &pos, &banyak, &harga);
      a[i].second = banyak;
      a[i].first  = (jarak-pos)+harga;
    }
    int hatot = 0;
    sort(a,a+n);
    R(i,0,n) {
        if(a[i].second >=k) {
            hatot += k * a[i].first;
            k = 0;
            break;
        } else if(a[i].second < k) {
            k     -= a[i].second;
            hatot += a[i].second * a[i].first;
        }
    }
    //R(i,0,n) printf("%d %d\n", a[i].second, a[i].first);
    printf("%d\n", hatot);
    return 0;
}
