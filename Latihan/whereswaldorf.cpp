#include <cctype>
#include <cstdio>
#include <cstring>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int bar,kol,ntebak;
char m[60][60],s[60];
int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) scanf("%s", m[i]);
    R(i,0,bar) R(j,0,kol) if(isupper(m[i][j])) m[i][j]=m[i][j]-'A'+'a';
    scanf("%d", &ntebak); 
    R(i,0,ntebak) {
        int ni=0,nj=0;
        scanf("%s", s);
        int len=strlen(s);
        R(i,0,len) if(isupper(s[i])) s[i]=s[i]-'A'+'a';
        bool ketemu=0;
        R(j,0,bar) {
          R(k,0,kol) {
              if(m[j][k]==s[0]) {
                  bool a=1,b=1,c=1,d=1,e=1,f=1,g=1,h=1;
                  // kiri atas
                  if(j-len+1 >=0 and k-len+1 >=0) {
                    R(l,0,len)
                      if(m[j-l][k-l]!=s[l]) { a=0; break; }
                  } else a=0;
                  //atas
                  if( j-len+1 >=0) {
                    R(l,0,len)
                       if(m[j-l][k]!=s[l]) { b=0; break; }
                  } else b=0;
                  //kanan atas
                  if( j-len+1 >=0 and k+len-1 < kol) {
                    R(l,0,len)
                        if(m[j-l][k+l]!=s[l]) { c=0; break; }
                  } else c=0;
                  //kanan
                  if( k+len-1 < kol ) {
                    R(l,0,len)
                       if(m[j][k+l]!=s[l]) { d=0; break; }
                  } else d=0;
                  //kanan bawah
                  if( k+len-1 < kol and j+len-1 < bar ) {
                    R(l,0,len)
                      if(m[j+l][k+l]!=s[l]) { e=0; break;}
                  } else e=0;
                  //bawah
                  if( j+len-1 < bar) {
                    R(l,0,len)
                      if(m[j+l][k]!=s[l]) { f=0;  break; }
                  } else f=0;
                  // kiri bawah
                  if( j+len-1 < bar and k+len+1 >=0) {
                    R(l,0,len)
                      if(m[j+l][k-l]!=s[l]) { g=0; break; }
                  } else g=0;
                  //kiri
                  if( k-len+1 >=0 ) {
                    R(l,0,len)
                      if(m[j][k-l]!=s[l]) { h=0; break; }
                  } else h=0;  
                  //printf("%d %d %d %d %d %d %d %d\n", a,b,c,d,e,f,g,h);
                  if(a or b or c or d or e or f or g or h) { 
                    ketemu=1; ni=j,nj=k; break;
                  }
             }
          }
          if(ketemu) break;
        }
        printf("%d %d\n", ni+1, nj+1);
    }
    return 0;
}
