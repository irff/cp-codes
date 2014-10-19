#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[1000];
int main() {
    while(scanf("%s", &s) > 0) {
        if(strcmp(s,"0")==0) break;
        int len = strlen(s);
        reverse(s,s+len);
        int ans = 0;
        R(i,0,len) {
            int num = s[i] - '0';
            ans+=((1<<(i+1))-1)*num;
        }
        printf("%d\n", ans);
    }
    return 0;
}
