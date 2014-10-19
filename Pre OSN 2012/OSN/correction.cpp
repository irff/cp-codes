// submitan pertama selama liburan!!! :D ALHAMDULILLAH!!!
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
 
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
 
int n,len,mins,now;
char dict[5005][5005],s[5005];
int panjang[5005];
 
int main(){
 
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%s", dict[i]);
        panjang[i]=strlen(dict[i]);
    }
    scanf("%s", s);
    len=strlen(s);
     
    R(i,1,len+1){
        mins=2000123;
        now=-1;
        R(j,0,n){
          if(i<=panjang[j]){
            int nilai=0,x=0;
            R(k,0,i){
                x=abs(s[k]-dict[j][k]);
                if(x>13) x=26-x+1;
                nilai+=x;
            }
             
            if(nilai<mins){
                mins=nilai;
                now=j;
            }
          }
        }
        if(now==-1){
            R(j,0,i) printf("%c", s[j]);
        }
        else{
            R(j,0,i) printf("%c", dict[now][j]);
            //printf(" (%d)", mins);
        }
        puts("");
         
    }
     
    return 0;
} 
