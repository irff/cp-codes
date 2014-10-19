#include <cstdio>

char awal,tujuan,dum;
int teskes,k,MOD,adj[8][4];

int rek(int pre, int now, int left) {
    if(left<=0 and now==tujuan) return 1;
    if(left<=0) return 0;
    int hasil=0;
    for(int i=0; i<3; i++)
      if(adj[now][i]!=pre)
        hasil+=rek(now,adj[now][i],left-1);
    
    return hasil;
}
int main() {
    adj={{1,3,4},
         {0,2,5},
         {1,3,6},
         {0,2,7},
         {0,5,7},
         {1,4,6},
         {2,5,7},
         {3,4,6} };
    for(int i=0; i<8; i++) {
        for(int j=0; j<3; j++) printf("%d ", adj[i][j]);
        printf("\n");
    }
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%c%c%c%c%d%d", &dum,&awal,&dum,&tujuan,&k,&MOD);
        awal-='A',tujuan-='A';
        printf("%d %d\n", awal,tujuan);
        int hasil=0;
        awal=0,tujuan=1;
        for(int i=0; i<20; i++) {
            hasil=0;
            hasil+=rek(awal,adj[awal][0],i-1);
            hasil+=rek(awal,adj[awal][1],i-1);
            hasil+=rek(awal,adj[awal][2],i-1);
            printf("%d-%d\n", i, hasil);
            
            
        }
    }
    return 0;
}
