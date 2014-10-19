#include <cstdio>
#include <cstring>

char x[1002],y[1002];
int c[1002][1002],b[1002][1002];
void print(int i,int j){
    if(i==0 or j==0) return ;
    if(b[i][j]==1){
        print(i-1,j-1);
        printf("%c", x[i]);
    }
    else if(b[i][j]==3)
        print(i-1,j);
    else print(i,j-1);
}
int main(){
    scanf("%s%s", &x,&y);
    int m=strlen(x),n=strlen(y);
    for(int i=m; i>=1; i--) x[i]=x[i-1]; // geser ke kanan, karena indeks string mulai dari 1
    for(int i=n; i>=1; i--) y[i]=y[i-1]; // geser ke kanan, karena indeks string mulai dari 1
    for(int i=1; i<=m; i++)
        c[i][0]=0;
    for(int i=1; i<=n; i++)
        c[0][i]=0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i]==y[j]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=2; // panah k
            }
            else {
                if(c[i-1][j]>=c[i][j-1]){
                    c[i][j]=c[i-1][j];
                    b[i][j]=3;
                }
                else{
                    c[i][j]=c[i][j-1];
                    b[i][j]=1;
                }
            }
        }
    }
    printf("%d\n", c[m][n]);
    return 0;
}
