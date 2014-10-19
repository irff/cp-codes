#include <cstdio>

int teskes;
int ha,ma,sa;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int utama=24*3600;
        scanf("%d:%d:%d", &ha,&ma,&sa);
        int x=ha*3600+ma*60+sa;
        x=utama-x;
        if(x==utama) x=0;
        if(x/3600 < 10) printf("0");
        printf("%d:", x/3600);
        if( (x%3600) / 60 < 10) printf("0");
        printf("%d:", (x%3600)/60);
        if(x%60 < 10) printf("0");
        printf("%d\n", x%60);
    }
    return 0;
}
