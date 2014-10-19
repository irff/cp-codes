#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)
#define RV(i,_a,_b) for(int i=int(_a); i>=int(_b); i--)

char dummy[500200],s3[500200],utama[500200], p[1000][1000], m[1000][1000], totalp[500200], posi[500200],nega[500200];
bool op[500000],kebalik=0;
int lnega=0,lposi=0,sisa=0,sampah,nop=0,lent,maks=0;

void hitung(int x){
     int lenp=strlen(p[x]);
     if(lent>lenp) maks=lent; else maks=lenp;
     memset(s3,'\0',sizeof s3);
     reverse(p[x],p[x]+lenp);
     R(i,0,lenp) p[x][i]-='0';
     sisa=0;
     R(i,0,maks) {
         s3[i]=(totalp[i]+p[x][i]+sisa)%10;
         sisa=(totalp[i]+p[x][i]+sisa)/10;
     }
     if(sisa>0) {s3[maks]=sisa;maks++;}
     R(i,0,maks) totalp[i]=s3[i];
     lent=maks;
}
void hitung2(int x){
     int lenm=strlen(m[x]);
     if(lent>lenm) maks=lent; else maks=lenm;
     memset(s3,'\0',sizeof s3);
     reverse(m[x],m[x]+lenm);
     R(i,0,lenm) m[x][i]-='0';
     sisa=0;
     R(i,0,maks) {
         s3[i]=(totalp[i]+m[x][i]+sisa)%10;
         sisa=(totalp[i]+m[x][i]+sisa)/10;
     }
     if(sisa>0) {s3[maks]=sisa;maks++;}
     R(i,0,maks) totalp[i]=s3[i];
     lent=maks;
}

int main() {
    scanf("%d", &sampah);
    scanf("%s", utama);
    int len=strlen(utama);
    nop=1;
    if(utama[0]=='-') op[0]=0;
    else op[0]=1;
    R(i,1,len) {
        if(utama[i]=='+') {
            op[nop++]=1;
        } else 
        if(utama[i]=='-') {
            op[nop++]=0;
        }
    }
    char delimsa[] = "-+";
    char *all=NULL;
    all=strtok(utama, delimsa);
    int ctr=0,nplus=0,nminus=0;
    while(all!=NULL) {
        if(op[ctr]==1) {
            strcpy(p[nplus++],all);
            ctr++;
        } else
        if(op[ctr]==0){
            strcpy(m[nminus++],all);
            ctr++;
        }
        all=strtok(NULL, delimsa);
    }
    //printf("%d %d\n", nplus, nminus);
    if( nplus <= 1) strcpy(posi, p[0]);
    else {
        strcpy(totalp, p[0]);
        lent=strlen(totalp);
        reverse(totalp,totalp+lent);
        R(i,0,lent) totalp[i]-='0';
        R(i,1,nplus) {
            hitung(i);
        }
        bool habis=false;
        ctr=0;
    
        RV(i,lent,0) {
            if(s3[i]!=0 or habis) {
                habis=true;
                posi[ctr++]=totalp[i]+'0';
            }
        }
    }
    
    if(nminus <= 1) strcpy(nega, m[0]);
    else {
        strcpy(totalp,m[0]);
        lent=strlen(totalp);
        reverse(totalp,totalp+lent);
        R(i,0,lent) totalp[i]-='0';
        R(i,1,nminus) {
            hitung2(i);
        }
        //----------
        bool habis=false;
        ctr=0;
        RV(i,lent,0) {
            if(s3[i]!=0 or habis) {
                habis=true;
                nega[ctr++]=totalp[i]+'0';
            }
        }
    }
    lposi=strlen(posi),lnega=strlen(nega);
    if(lposi < lnega) {
        strcpy(dummy,posi);
        strcpy(posi,nega);
        strcpy(nega,dummy);
        swap(lnega,lposi);
        kebalik=1;
    } else if(lnega==lposi and strcmp(posi,nega) < 0 ) {
        strcpy(dummy,posi);
        strcpy(posi,nega);
        strcpy(nega,dummy);
        swap(lnega,lposi);
        kebalik=1;
    }
    
    reverse(nega,nega+lnega);                                   123
    reverse(posi,posi+lposi);                                    90
    //printf("%d - %d\n", lposi, lnega);                        321
    //printf("%s - %s\n", posi, nega);                          09
    R(i,lnega,lposi) nega[i]='0';

    if(kebalik) printf("-");
    for(int i=0,hold=0; i<lposi; i++) {
        posi[i]-='0',nega[i]-='0';
        if(posi[i]<0) posi[i]=0;
        if(nega[i]<0) nega[i]=0;
        int diff=posi[i]-(nega[i]+hold); if(diff < 0) hold=1, totalp[i]=10+diff+'0';
        else totalp[i]=diff+'0',hold=0;
    }
    bool habis=false;
    ctr=0;
    RV(i,lposi-1,0) {
        if(totalp[i]!='0' or habis) {
            printf("%c", totalp[i]);
            habis=true;
        }
    }
    if(!habis) printf("0");
    printf("\n");   
    return 0;
}
