#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

char s[1005];
int n,x;
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%s", &s);
        reverse(s,s+strlen(s));
        x=atoi(s);
        printf("%d\n", x);
    }
    return 0;
}
