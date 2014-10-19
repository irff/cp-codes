#include <cstdio>
#include <cstring>

int teskes,n;
char c[8][4]={{'T','T','T'},{'T','T','H'},{'T','H','T'},{'T','H','H'},{'H','T','T'},{'H','T','H'},
              {'H','H','T'},{'H','H','H'}};
char s[100];
int has[8];
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        memset(has,0,sizeof has);
        scanf("%d", &n);
        scanf("%s", &s);
        printf("%d ", n);
        for(int j=0; j<8; j++){
           for(int i=0; i<(40-2); i++) if(s[i]==c[j][0] and s[i+1]==c[j][1] and s[i+2]==c[j][2]) has[j]++;
           printf("%d ", has[j]);
        }
        puts("");
    }
    return 0;
}
