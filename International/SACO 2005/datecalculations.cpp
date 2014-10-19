#include <cstdio>

int da,ma,ya,db,mb,yb;
int total=0;
int main() {
    int nday[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d%d%d", &da,&ma,&ya);
    scanf("%d%d%d", &db,&mb,&yb);
    for(int i=ya+1; i<yb; i++) {
        if( (i%400==0 or i%4==0) and i%100!=0) total+=366;
        else total+=365;
    }
    bool kab=0;
    if( (ya%400==0 or ya%4==0) and ya%100!=0 ) kab=1;
    for(int i=ma+1; i<=12; i++) {
        if(i==2 and kab) total+=29;
        else total+=nday[i-1];
    }
    if(ma==2 and kab) total+=(29-da);
    else total+=(nday[ma-1]-da);
    
    kab=0;
    if( (yb%400==0 or yb%4==0) and yb%100!=0 ) kab=1;
    for(int i=1; i<mb; i++) {
        if(i==2 and kab) total+=29;
        else total+=nday[i-1];
    } 
    total+=db;
    printf("%d\n", total);
    return 0;
}
