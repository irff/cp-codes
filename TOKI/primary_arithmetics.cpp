#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

string a, b;
int main() {
    cin >> a >> b;
    while(a!="0" and b!="0") {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len = max(a.length(), b.length());
        
        R(i,a.length(), len) a.push_back('0');
        R(i,b.length(), len) b.push_back('0');
        
        int bank = 0, carry = 0;
        R(i,0,len) {
            int res = (a[i]-'0'+b[i]-'0'+bank);
            bank = res/10;
            printf("%c + %c = %d, carry = %d\n", a[i], b[i], res, bank);
            if(bank) carry++;
        }
        if(carry==0) printf("No carry operation.\n");
        else if(carry==1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n", carry);
        cin >> a >> b;
    }
    return 0;
}
