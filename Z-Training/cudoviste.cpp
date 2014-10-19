#include <cstdio>
#include <cstring>

int bar,kol,a[5];
char m[51][51];
int main(){
    scanf("%d%d", &bar,&kol);
    for(int i=0; i<bar; i++)
        scanf("%s", &m[i]);
    for(int i=0; i<bar-1; i++)
     for(int j=0; j<kol-1; j++){
             
      int mobil=0; bool ada=1;
      
      for(int k=i; k<i+2; k++)
       for(int l=j; l<j+2; l++)
        if(m[k][l]=='#') ada=0;
        else if(m[k][l]=='X') mobil++;
      
      if(ada) a[mobil]++;
     }
     
    for(int i=0; i<5; i++) printf("%d\n", a[i]);
    
    return 0;
}
