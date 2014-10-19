#include <cstdio>

int teskes,n;
char s[150];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        bool nyala=0;
        scanf("%d", &n);
        scanf("%s", s);
        for(int i=0; i<n; i++) if(s[i]=='N') nyala=1;
        if(nyala) printf("tidak mati lampu\n");
        else printf("mati lampu\n");
    }
    return 0;
}
