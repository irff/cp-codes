#include <cstdio>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
char s[10][10];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        R(i,0,3) scanf("%s", &s[i]);
        
        bool a=0,b=0;
        
        R(i,0,3) {
          int na=0,nb=0;
          
          R(j,0,6) {
            if(s[i][j]=='A') na++;
            if(s[i][j]=='B') nb++;
          }
         
          if(na==3) a=1;
          if(nb==3) b=1;
          
          na=0,nb=0;
          R(j,0,3) {
              if(s[j][i*2+1]=='A') na++;
              if(s[j][i*2+1]=='B') nb++;
          }
          if(na==3) a=1;
          if(nb==3) b=1;
        }
        
        if(s[0][1]==s[1][3] and s[0][1]==s[2][5] and s[0][1]=='A') a=1;
        if(s[0][1]==s[1][3] and s[0][1]==s[2][5] and s[0][1]=='B') b=1;
        if(s[0][5]==s[1][3] and s[0][5]==s[2][1] and s[0][5]=='A') a=1;
        if(s[0][5]==s[1][3] and s[0][5]==s[2][1] and s[0][5]=='B') b=1;
        if(a and !b) printf("A\n");
          else if(b and !a) printf("B\n");
          else printf("S\n");
    }
    return 0;
}
