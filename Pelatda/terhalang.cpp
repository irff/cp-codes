#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
int a[1000111], x[1000111], y[1000111], id[1000111], ans[1000111];
char s[100];
int main() {
    gets(s);
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &a[i]);
    ans[n-1]=-1;
    x[0]=a[n-1];
    id[0]=n-1;
    int now = 1, size = 1;
    for(int i=n-2; i>=0; i--) {
        now = size;
        while(now and x[now-1] <= a[i]) now--;
        x[now]=a[i];
        id[now]=i;
        if(now) ans[i]=id[now-1];
        else ans[i] = -1;
        size=now+1;
    }
    R(i,0,n) printf("%d%c", ans[i]+1,i==n-1?'\n':' ');
    return 0;
}
