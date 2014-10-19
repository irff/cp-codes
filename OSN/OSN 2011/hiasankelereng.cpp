#include <cstring>
#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

int n,hasil=0;
char s[1000];
int a[26];
int main() {
    scanf("%d%s", &n,s);
    int len=strlen(s);
    for(int i=0; i<len; i++) a[ s[i]-'A' ]++;
    sort(a, a+26,greater<int>());
    if(a[0]==0 or a[1]==0 or a[2]==0) hasil=-1;
    else {
        for(int i=0; ; i++,i%=3) {
            if(a[i]==0) break;
            a[i]--; hasil++;
        }
    }
    printf("%d\n", hasil);
    return 0;
}
