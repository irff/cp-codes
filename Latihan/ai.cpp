#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

int n;
char soal[1000];
double ni,nu,np;

double checkprefix(char ch, double a) {
    if(ch=='m') return (double) a/1000;
    if(ch=='k') return a*1000;
    if(ch=='M') return a*1000000;
    return a;
}

double findformula(int i, char quan, char unit) {
    char num[100]; memset(num, 0, sizeof num);
    int j,x;
    if(soal[i]==quan and soal[i+1]=='=') {
        j=i+2,x=0;
        while(soal[j]!='m' and soal[j]!='k' and soal[j]!='M' and soal[j]!=unit) num[x++]=soal[j++];    
        double angka=atof(num);
        return checkprefix(soal[j], angka);
    }
    
    return -1;
}

int main() {
    scanf("%d\n", &n);
    for(int k=1; k<=n; k++) {
        ni=-1,nu=-1,np=-1;
        gets(soal);
        int len=strlen(soal);
        for(int i=0; i<len; i++) {
            double tmp;
            tmp=findformula(i, 'I', 'A');
            if(tmp!=-1) ni=tmp;            
            tmp=findformula(i, 'U', 'V');
            if(tmp!=-1) nu=tmp;
            tmp=findformula(i, 'P', 'W');
            if(tmp!=-1) np=tmp;
        }
        printf("Problem #%d\n", k);
        if(np==-1) {
            double hasil=nu*ni;
            printf("P=%.2lfW\n", hasil);
        } else 
        if(nu==-1) {
            double hasil=(double) np/ni;
            printf("U=%.2lfV\n", hasil);
        } else {
            double hasil=(double) np/nu;
            printf("I=%.2lfA\n", hasil);
        }
        printf("\n");
    }
    return 0;
}
