#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

int n, ans;
char s[1000];
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%s", &s);
        int len = strlen(s);
        reverse(s,s+len);
        ans = atoi(s);
        printf("%d\n", ans);
    }

    return 0;
}
