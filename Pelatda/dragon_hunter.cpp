#include <cstdio>
#include <cstring>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
char s[1000];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%s", &s);
        int len = strlen(s);
        bool ada = 0;
        R(i,0,len) if(s[i]=='D') { ada = 1; break; }
        if(ada) printf("KETEMU\n");
        else printf("TIDAK KETEMU\n");
    }
    return 0;
}
