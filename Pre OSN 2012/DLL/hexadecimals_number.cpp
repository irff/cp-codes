#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int n;
map<int,bool> m;
char s[100];
int main() {
    scanf("%d", &n);
    for(int i=1; i<1024; i++) {
        int x = i, ctr=0;
        memset(s,0,sizeof s);
        while(x > 0) {s[ctr++]=(x%2)+'0'; x/=2; }
        reverse(s,s+strlen(s));
        m[atol(s)]=1;
    }
    int hasil=0;
    for(map<int,bool>::iterator it=m.begin(); it!=m.end(); it++) if( it->first <= n) hasil++;
    printf("%d\n", hasil);
    return 0;
}
