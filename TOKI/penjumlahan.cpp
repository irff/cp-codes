#include <cstdio>
#include <cstring>
#include <algorithm>
#define NGEPOL 1000
using namespace std;

char s1[1000],s2[1000],s3[1000];
int sisa;
int maks;
int i,j,k;
bool habis;
void hitung(){
     int l1=strlen(s1);
     int l2=strlen(s2);
     reverse(s1,s1+l1);
     reverse(s2,s2+l2);
     if(l1>l2) maks=l1; else maks=l2;
     memset(s3,'\0',NGEPOL);
     
     for(i=0; i<l1; i++) s1[i]-=48;
     for(i=0; i<l2; i++) s2[i]-=48;
     sisa=0;
     for(i=0; i<maks; i++){
         s3[i]=(s1[i]+s2[i]+sisa)%10;
         sisa=(s1[i]+s2[i]+sisa)/10;
     }
     if(sisa>0) {s3[maks]=sisa;maks++;}
}

int main()
{
        scanf("%s %s", &s1, &s2);
        hitung();
        habis=false;
        for(i=maks-1; i>=0; i--){
            if(s3[i]!=0 or habis) {
                printf("%d", s3[i]); habis=true;
            }
        }
        
        printf("\n");
        memset(s1,'\0',NGEPOL);
        memset(s2,'\0',NGEPOL);
    
    
    return 0;
}
