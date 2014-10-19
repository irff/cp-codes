#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

int teskes, n;
string ratus = "Ratus", puluh = "Puluh", ribu = "Ribu";
string x[1005];
int main() {
    scanf("%d", &teskes);
    x[0] = "Nol";
    x[1] = "Satu";
    x[2] = "Dua";
    x[3] = "Tiga";
    x[4] = "Empat";
    x[5] = "Lima";
    x[6] = "Enam";
    x[7] = "Tujuh";
    x[8] = "Delapan";
    x[9] = "Sembilan";
    x[10] = "Sepuluh";
    x[11] = "Sebelas";
    R(i,12,20) x[i] = x[i%10]+"Belas";
    R(i,20,100) {
        if(i%10==0) {
            x[i] = x[i/10]+"Puluh";
        } else {
           x[i] = x[i/10] + "Puluh" + x[i%10];
        }
    }
    R(i,100,1000) {
        if(i/100==1) x[i] = "Seratus";
        else x[i] = x[i/100]+"Ratus";
        
        if(i%100!=0) {
            x[i] = x[i] + x[i%100];
        }
    }
    
    //R(i,100,1000) printf("%s\n", x[i].c_str());
    while(teskes--) {
        scanf("%d", &n);
        string s = "";
        if(n<1000) s = x[n];
        else {
            int m = n/1000;
            if(m == 1) s = "Se";
            else {
               s = x[m];
            }
            s+="Ribu";
            if(n%1000!=0) s+=x[n%1000];
        }
        //printf("%s\n", s.c_str());
        printf("%d : %d Huruf\n", n, s.size());
    }
    return 0;
}
