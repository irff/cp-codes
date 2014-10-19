#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(_x) push_back(_x)
int n;
string dp[260];

string add(string a, string b) {
    int lena = a.length(), leni = b.length();
    int x = min(lena, leni);
    int y = max(lena, leni);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    R(i,x,y) if(lena==x) a.pb('0'); else b.pb('0');
    R(i,0,y) a[i]-='0', b[i]-='0';
    string c;
    int sisa = 0;
    R(i,0,y) {
        int num = a[i]+b[i]+sisa;
        c.pb(num%10+'0');
        sisa = num/10;
    }
    if(sisa) c.pb(sisa+'0');
    reverse(c.begin(), c.end());
    return c;
}

int main() {
    dp[0] = "1";
    dp[1] = "1";
    dp[2] = "3";
    R(i,3,252) {
        dp[i] = "0";
        dp[i] = add(dp[i], dp[i-1]);
        dp[i] = add(dp[i], dp[i-2]);
        dp[i] = add(dp[i], dp[i-2]);
    }
    while(scanf("%d", &n) > 0) {
        cout << dp[n] << endl;
    }
    return 0;
}
