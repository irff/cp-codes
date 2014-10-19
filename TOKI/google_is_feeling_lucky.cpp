#include <cstdio>
#include <cstring>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, val[20];
char s[20][100];
int main() {
    scanf("%d", &teskes);
    R(k,0,teskes) {
        int maks = -2000111222;
        R(i,0,10) {
            scanf("%s %d", &s[i], &val[i]);
            if(val[i] > maks) maks = val[i];
        }
        printf("Case #%d:\n", k+1);
        R(i,0,10) if(val[i]==maks) printf("%s\n", s[i]);
        //printf("---\n");
    }
    return 0;
}
