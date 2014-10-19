// Curse - DP :D
// Maximum Sum 
// sum table : now+top+left-topleft
// sum query : now-top-left+topleft
#include <cstdio>
#include <algorithm>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar,kol,mbatu,a[55][55],b[55][55],c[2],d[2];
int main(){
    // init
    d[0]=-(101*100*50),d[1]=(101*100*50);
    
    scanf("%d%d%d", &bar, &kol, &mbatu);
    // generating sum table
    R(i,0,bar) R(j,0,kol){
        scanf("%d", &a[i][j]);
        if(a[i][j]==9999) a[i][j]=0,b[i][j]=1;
        if( i > 0 ) a[i][j]+=a[i-1][j],b[i][j]+=b[i-1][j];   // plus top
        if( j > 0 ) a[i][j]+=a[i][j-1],b[i][j]+=b[i][j-1];   // plus left
        if( i > 0 and j > 0 ) a[i][j]-=a[i-1][j-1],b[i][j]-=b[i-1][j-1]; // minus top-left ( avoid duplicate )
    }
    // R(i,0,bar) { R(j,0,kol) printf("%d ", b[i][j]); puts(""); }
    // R(i,0,bar) { R(j,0,kol) printf("%d ", a[i][j]); puts(""); }
    // Maximum Sum Process
      R(i,0,bar) R(j,0,kol)
        R(k,i,bar) R(l,j,kol){
            c[0]=a[k][l];
            c[1]=b[k][l];
            if( i > 0) c[0]-=a[i-1][l],c[1]-=b[i-1][l];      // minus top
            if( j > 0) c[0]-=a[k][j-1],c[1]-=b[k][j-1];      // minus left
            if( i > 0 and j > 0) c[0]+=a[i-1][j-1],c[1]+=b[i-1][j-1]; // plus top-left ( avoid duplicate )
            
            if(d[0]<=c[0] and c[1]<=mbatu){ // if greater but pass the max-stone limit
              if(d[0]<c[0]){                // priority
                  d[0]=c[0];
                  d[1]=c[1];
              }
              else d[1]=std::min(d[1],c[1]); // if maxsum==sumnow
            }
        }
    printf("%d %d\n", d[0],d[1]);
    return 0;
}
