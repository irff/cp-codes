#include <cstring>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
char sa[12000], si[12000];
int main() {
    scanf("%d", &teskes);
    gets(sa);
    for(int i=0; i<teskes; i++) {
        gets(sa); int lena = strlen(sa);
        int c = 0;
        R(j,0,lena) if(sa[j]>='a' and sa[j]<='z') si[c++]=sa[j];
        strcpy(sa,si);
        reverse(sa,sa+c);
        printf("Case #%d:\n", i+1);
        int x = (int)sqrt(c);
        if(strcmp(sa,si)==0 and x*x==c) {
            printf("%d\n", (int)sqrt(c));
        } else printf("No magic :(\n");
    }
    return 0;
}
