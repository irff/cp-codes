#include <cstdio>

int teskes,ha,ma,hb,mb;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int n=0;
        scanf("%d%d%d%d", &ha,&ma,&hb,&mb);
        double awal=ha+(double)ma/60;
        double akhir=hb+(double)mb/60;
        for(int i=0; i<22; i++)
          if( (double)12/11*i > awal and (double)12/11*i <= akhir ) n++;
        printf("%d\n", n);
    }
    return 0;
}
