#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

unsigned long long n, k[15], beli[15], money;
unsigned long long pjg;
bool gabisabeli = 0, nolnol = 0;
int main() {
    scanf("%llu", &n);
    R(i,0,n+1) scanf("%llu", &k[i]);
    scanf("%llu", &money);
    unsigned long long mins = 9223372036854775809ULL, murah=0;
    R(i,1,n+1) if(mins > k[i]) mins=k[i],murah=i;
    
    if(mins <= k[0]) {
        if( mins > money ) {
            gabisabeli = 1;
        } else {
            pjg = money/k[murah];
            beli[murah] = pjg;
            money = money - pjg*k[murah];
            
            for(int i=n; i>murah; i--) {
                unsigned long long tmp = money / (k[i]-mins);
                if(tmp > beli[murah]) tmp = beli[murah];
                beli[i] = tmp;
                beli[murah] = beli[murah] - tmp;
                money = money - tmp*(k[i]-mins);
            }
        }
    } else {
        if( k[0] > money) gabisabeli = 1;
        else if(mins > money) nolnol = 1;
        else {
            pjg = 1+(money - mins) / k[0];
            beli[0] = pjg;
            money = money - pjg*k[0];
            for(int i=n; i>0; i--) {
                unsigned long long tmp = money / (k[i]-k[0]);
                if(tmp > beli[0]) tmp = beli[0];
                beli[i] = tmp;
                beli[0] = beli[0] - tmp;
                money = money - tmp*(k[i]-k[0]);
            }
        }
    }
    if(gabisabeli) printf("0\n");
    else if(nolnol) printf("1\n0\n0\n");
    else {
        string s;
        int ctr = 0;
        printf("%llu\n", pjg);
        if(pjg < 50) ctr = pjg; else ctr = 50;
        s = "";
        for(int i=9; i>=0; i--) if(beli[i] > ctr) {
            R(j,0,ctr) s.push_back('0'+i);
            ctr = 0;
        } else {
            R(j,0,beli[i]) s.push_back('0'+i);
            ctr -= beli[i];
        }
        cout << s << endl;
        if(pjg < 50) ctr = pjg; else ctr = 50;
        s = "";
        R(i,0,10) if(beli[i] > ctr) {
            R(j,0,ctr) {
                s.push_back('0'+i);
            }
            ctr = 0;
        } else {
            R(j,0,beli[i]) {
                s.push_back('0'+i);
            }
            ctr = ctr - beli[i];
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}
