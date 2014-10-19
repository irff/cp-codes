#include <cstdio>
#include <algorithm>
using namespace std;

char a, b[5], c[5];
int getval(char ch) {
    if(ch >= '6' and ch <= '9') return ch-'0';
    if(ch=='T') return 10;
    if(ch=='J') return 11;
    if(ch=='Q') return 12;
    if(ch=='K') return 13;
    if(ch=='A') return 14;
}
int main() {
    scanf("%c", &a);
    scanf("%s %s", &b, &c);
    if(b[1]==c[1]) printf("%s\n", (getval(b[0]) > getval(c[0])?"YES":"NO"));
    else if(b[1]==a) printf("YES\n");
    else if(c[1]==a) printf("NO\n");
    else printf("NO\n");
    return 0;
}
