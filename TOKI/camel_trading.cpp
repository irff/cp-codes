#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int teskes;
char ina[300], ini[300];
int n[300], nang, nop;
char oper[300];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%s", &ina);
        strcpy(ini, ina);
        char delima[] = "0123456789";
        char delimi[] = "*+";
        char *dum = strtok(ini, delimi);
        
        int nang = 0;
        
        int len = strlen(dum), num = 0;
       
        while(dum != NULL) {
            int len = strlen(dum), num = 0;
            for(int i=len-1, sep = 1; i>=0; i--,sep*=10) {
                num+=(dum[i]-'0')*sep;
            }
            n[nang++] = num;
            dum = strtok(NULL, delimi);
        }
        
        char *dim = strtok(ina, delima);
        int nop = 0;
        while(dim != NULL) {
            oper[nop++] = dim[0];
            dim = strtok(NULL, delima);
        }
        //R(i,0,nang) printf("%d ", n[i]);
        //R(i,0,nop) printf("%c", oper[i]);
        //MINIMAL
        vector<LLD> v;
        LLD x = n[0], mins = 0;
        R(i,0,nop) {
            if(oper[i]=='+') {
                v.push_back(x);
                x = n[i+1];
            } else {
                x*=(LLD)n[i+1];
            }
        }
        v.push_back(x);
        int lena = v.size();
        R(i,0,lena) { mins+=(LLD)v[i];}
        
        // MAXIMAL
        vector<int> w;
        x = n[0]; LLD maks = 1;
        R(i,0,nop) {
            if(oper[i] == '*') {
                w.push_back(x);
                x = n[i+1];
            } else {
                x+=n[i+1];
            }
        }
        w.push_back(x);
        int leni = w.size();
        R(i,0,leni) { maks = (LLD) maks * w[i]; }
        printf("The maximum and minimum are %lld and %lld.\n", maks,mins);
    }
    return 0;
}
