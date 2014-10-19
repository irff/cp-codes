#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

string a, c;
int eks = 0;
string tambah(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int lena = a.length(), leni=b.length();
    if(lena > leni) {
        R(i,leni,lena) b.push_back('0'); 
        leni = lena;
    } else if(leni > lena) {
        R(i,lena,leni) a.push_back('0');
        lena = leni;
    }
    string c;
    //cout << a << endl << b << endl;
    int sisa = 0;
    R(i,0,lena) {
        c.push_back((a[i]-'0'+b[i]-'0'+sisa)%10+'0');
        sisa = (a[i]-'0'+b[i]-'0'+sisa)/10;
    }
    if(sisa>0) c.push_back(sisa+'0');
    
    while(c[c.length()-1]=='0') c.erase(c.length()-1,1);
    reverse(c.begin(), c.end());
    return c;
}

string kali(string a, char b) {
    reverse(a.begin(), a.end());
    int lena = a.length();
    int sisa = 0;
    string c;
    b-='0';
    
    R(i,0,lena) {
        c.push_back( ((a[i]-'0')*b+sisa)%10+'0');
        sisa = ((a[i]-'0')*b+sisa)/10;
    }
    if(sisa > 0) c.push_back(sisa+'0');
    reverse(c.begin(), c.end());
    return c;
}

string perkalian(string a, string b) {
    string c;
    int lena = a.length(), leni = b.length();
    reverse(b.begin(), b.end());
    R(i,0,leni) {
        string d;
        d = kali(a,b[i]);
        R(j,0,i) d.push_back('0');
        c = tambah(c, d);
    }
    return c;
}

string pangkat(string a, int b) {
    string c; c.push_back('1');
    R(i,0,b) c = perkalian(c,a);
    return c;
}

int main() {
    while( (cin >> a >> eks) > 0) {
        string b;
        int pos=0;
        while(a[a.length()-1]=='0') a.erase(a.length()-1,1);
        //cout << a << endl;
        int lena=a.length();
    
        R(i,0,lena) {
            if(a[i]=='.') pos = i+1;
            else b.push_back(a[i]);
        }
    
        c = pangkat(b,eks);
        int lene=c.length();
        pos = lena-pos;
        pos = (pos*eks);
        if(pos >= lene) {
            printf(".");
            RV(i,pos,lene+1) printf("0");
        }
        R(i,0,lene) {
            if(i==lene-pos) printf(".");
            printf("%c", c[i]);
        }
        if(pos==0) printf(".");
        printf("\n");
    }
    return 0;
}
