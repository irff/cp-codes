#include <cstdio>
#include <cstring>
using namespace std;

char s[100];
int main() {
    scanf("%s", &s);
    int len = strlen(s);
    int n4=0, n7=0;
    for(int i=0; i<len; i++) { if(s[i]=='4') n4++; if(s[i]=='7') n7++; }
    if(n4==0 and n7==0) printf("-1\n");
    else if(n4>n7) printf("4\n");
    else if(n4<n7) printf("7\n");
    else printf("4\n");

    return 0;
}
