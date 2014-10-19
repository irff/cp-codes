#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1000];
char sa[1000];
char si[1000][1000];
int main() {
    int ctr=0;
    while(scanf("%s", &s) >0) {
        strcpy(sa,s);
        reverse(sa,sa+strlen(sa));
        if(strcmp(s,sa)==0) {
            strcpy(si[ctr++],s);
        }
    }
    for(int i=0; i<ctr; i++) {
        printf("%s", si[i]);
        if(i==ctr-1) printf("\n");
        else printf(" ");
    }
    return 0;
}
