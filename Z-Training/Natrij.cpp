#include <cstdio>

int ha,ma,sa,hi,mi,si,hu,mu,su,TA,TI,TU;
int main(){
    scanf("%d:%d:%d", &ha,&ma,&sa);
    scanf("%d:%d:%d", &hi,&mi,&si);
    TA=ha*3600+ma*60+sa;
    TI=hi*3600+mi*60+si;
    if(TI<=TA) TI+=24*3600;
    TU=TI-TA;
    hu=TU/3600;
    TU%=3600;
    mu=TU/60;
    TU%=60;
    su=TU;
    if(hu<10) printf("0%d:", hu);
    else printf("%d:",hu);
    if(mu<10) printf("0%d:", mu);
    else printf("%d:", mu);
    if(su<10) printf("0%d", su);
    else printf("%d",su);
    printf("\n");
    return  0;
}
