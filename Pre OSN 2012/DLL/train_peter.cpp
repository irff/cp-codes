#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100200], a[500], b[500];
bool maju=0, mundur=0;
int main() {
    scanf("%s %s %s", &s, &a, &b);
    int len = strlen(s), lena = strlen(a), leni = strlen(b);
    for(int i=lena, j=0; j<leni; j++,i++) {
        a[i] = b[j];
    }
    lena = strlen(a);
    //printf("%s\n", a);
    int ctr = 0;
    for(int i=0; i<len; i++) {
        if(a[ctr]==s[i]) ctr++;
    }
    if(ctr==lena) maju=1;
    reverse(s,s+len);
    //printf("%s\n", s);
    ctr=0;
    for(int i=0; i<len; i++) {
        if(a[ctr]==s[i]) ctr++;
    }
    if(ctr == lena) mundur=1;
    
    if(maju and mundur) printf("both\n");
    else if(maju) printf("forward\n");
    else if(mundur) printf("backward\n");
    else printf("fantasy\n");
    
    return 0;
}
