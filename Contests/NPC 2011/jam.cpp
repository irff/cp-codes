#include <cstdio>

int teskes,nkeg,sisa;
int jam,men,sec;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        sisa=24*3600;
        scanf("%d", &nkeg);
        for(int i=0; i<nkeg; i++) {
            scanf("%d%d%d", &jam,&men,&sec);
            sisa-=(jam*3600+men*60+sec);
        }
        if(sisa/3600 < 10 ) printf("0");
        printf("%d:",sisa/3600);
        if( (sisa%3600)/60 < 10) printf("0");
        printf("%d:", (sisa%3600)/60);
        if(sisa%60 < 10) printf("0");
        printf("%d\n",sisa%60);
    }
    return 0;
}
