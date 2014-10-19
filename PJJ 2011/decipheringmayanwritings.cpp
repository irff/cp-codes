#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

char key[4000],s[1200000],delims[100],tmp[4000];
int lenkey,lens,total=0;
bool ada[256];
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

int main() {
    scanf("%d%d%s%s", &lenkey,&lens,key,s);
    sort(key,key+lenkey);
    R(i,0,lenkey) ada[ key[i] ]=1;
    int ctr=0;
    R(i,'A','Z'+1) if(!ada[i]) delims[ctr++]=i;
    R(i,'a','z'+1) if(!ada[i]) delims[ctr++]=i;
    char *result=strtok(s,delims);
    while(result!=NULL) {
        int len=strlen(result);
        for(int i=0; i+lenkey<=len; i++) {
            int x=0;
            R(j,0,lenkey) tmp[j]=result[i+j];
            sort(tmp,tmp+lenkey);
            if(strcmp(tmp,key)==0) total++;
        }
        result=strtok(NULL, delims);
    }
    printf("%d\n", total);
    return 0;
}
