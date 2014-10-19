#include <cstdio>


int n;

void hundred(int n) {
    if(n==1) printf("C");
    if(n==2) printf("CC");
    if(n==3) printf("CCC");
    if(n==4) printf("CD");
    if(n==5) printf("D");
    if(n==6) printf("DC");
    if(n==7) printf("DCC");
    if(n==8) printf("DCCC");
    if(n==9) printf("CM");
}

void ten(int n) {
    if(n==1) printf("X");
    if(n==2) printf("XX");
    if(n==3) printf("XXX");
    if(n==4) printf("XL");
    if(n==5) printf("L");
    if(n==6) printf("LX");
    if(n==7) printf("LXX");
    if(n==8) printf("LXXX");
    if(n==9) printf("XC");
   
}

void unit(int n) {
    if(n==1) printf("I");
    if(n==2) printf("II");
    if(n==3) printf("III");
    if(n==4) printf("IV");
    if(n==5) printf("V");
    if(n==6) printf("VI");
    if(n==7) printf("VII");
    if(n==8) printf("VIII");
    if(n==9) printf("IX");
}

int main() {
    scanf("%d", &n);
    if(n>1000) {
        int x=n/1000;
        for(int i=0; i<x; i++) printf("M");
    }
    n%=1000;
    hundred(n/100);
    n%=100;
    ten(n/10);
    n%=10;
    unit(n);
    printf("\n");
}
