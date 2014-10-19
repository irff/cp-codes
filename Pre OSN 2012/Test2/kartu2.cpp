#include <cstdio>

char s[4];
int npemain, nkartu, dapat=1, udah=0, tadi;
int main() {
    scanf("%d%d", &npemain, &nkartu);
    for(int i=0; i<nkartu; i++) {
        scanf("%s", &s);
        if(i==0) tadi = s[0]-'0';
        if(i>0 and !udah) {
            int x = s[0]-'0';
            if(x >= tadi) dapat++;
            else udah=0;
        }
    }
    printf("%d\n", dapat);
    
    return 0;
}
