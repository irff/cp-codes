#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[1200][1200];

int main() {
    int ctr = 0;
    int makslen = 0;
    while(gets(s[ctr])>0) {
        //printf("%s\n", s[ctr]);
        makslen = max(makslen, (int)strlen(s[ctr]));
        ctr++;
    }
    R(i,0,makslen+2) printf("*");
    printf("\n");
    int gakurut = 0;
    R(i,0,ctr) {
        int len = strlen(s[i]);
        int left = (makslen-len)/2;
        int right = left;
        printf("*");
        if(makslen%2 and len%2==0) {
            if(gakurut%2==0) right++;
            else left++;
            gakurut++;
        } else
        if(makslen%2==0 and len%2) {
            if(gakurut%2==0) right++;
            else left++;
            gakurut++;
        }
        R(j,0,left) printf(" ");
        printf("%s", s[i]);
        R(j,0,right) printf(" ");
        printf("*\n");
    }
    R(i,0,makslen+2) printf("*");
    printf("\n");

    return 0;
}
