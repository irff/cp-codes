#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(_x) push_back(_x)
string a, b;

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

string sub(string a, string b) {
    int lena = a.length(), leni = b.length();
    int x = min(lena, leni);
    int y = max(lena, leni);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    R(i,x,y) if(lena==x) a.pb('0'); else b.pb('0');
    R(i,0,y) a[i]-='0', b[i]-='0';
    string c;
    R(i,0,y) {
        if(a[i] < b[i]) {
            a[i+1]--;
            a[i]+=10;
        }
        c.pb(a[i]-b[i]+'0');
    }
    while(c[c.length()-1]=='0') c.erase(c.length()-1);
    reverse(c.begin(), c.end());
    return c;
}

string div(string a) {
    int len = a.length();
    R(i,0,len) a[i]-='0';
    string c;
    R(i,0,len) {
        c.pb(a[i]/2+'0');
        if(i<len-1) {
            a[i+1] += (a[i]%2)*10;
        }
    }
    while(c[0]=='0') c.erase(0,1);
    return c;
}

int main() {
    string c, d;
    cin >> c >> d;
    string a = add(c,d);
    a = div(a);
    string b = sub(c,d);
    b = div(b);
    cout << a << endl << b << endl;
    return 0;
}
