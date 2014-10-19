#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1100];
int main() {
    scanf("%s", &s);
    while(strcmp(s,"#")!=0) {
        if(next_permutation(s,s+strlen(s))) printf("%s\n", s);
        else printf("No Successor\n");
        scanf("%s", &s);
    }
    return 0;
}
