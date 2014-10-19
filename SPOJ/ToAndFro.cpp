#include <cstring>
#include <cstdio>

char s[300];
char k[300][300];
int n;
int main(){
    scanf("%d", &n);
    while(n!=0){
        strcpy(s,"");
        scanf("%s", &s);
        int len=strlen(s);
        int m=len/n;
        int ct=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i%2==0) k[i][j]=s[ct];
                else k[i][n-j-1]=s[ct];
                ct++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                printf("%c", k[j][i]=='\0'?'x':k[j][i]);
            }
        }
        puts("");
        scanf("%d", &n);
    }
    return 0;
}
