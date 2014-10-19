#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;

int a[51000], n;
int ans = 0;
int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &a[i]);
    R(i,0,n-1) {
        int mins = INF, id = 0;
        R(j,i+1,n) {
            if( a[j] < mins ) mins = a[j], id = j;
        }
        if(mins < a[i]) {
            swap(a[i], a[id]);
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
