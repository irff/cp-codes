#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int hsize=1000007;

struct yellowpages {
    string name;
    int no;
} ;

yellowpages t[1000007];
string s;

int encode(string s) {
    int val=0,len=s.length();
    R(i,0,len) {
        val+=((s[i]-'A')*(i*2+1))%hsize;
    }
    return val;
}

int place(int key) {
    if(t[key].no==0) return key%hsize;
    for(int i=key; ; (i++)%hsize) {
        if(t[i].no==0) return i;
    }
}

int cari(int key) {
    for(int i=key; ; (i++)%hsize) {
        if(t[i].name==s) return t[i].no;
    }
}

int nnum,ncari,nomor;
int main() {
    scanf("%d%d", &nnum, &ncari);
    R(i,0,nnum) {
        cin >> s >> nomor;
        int key=encode(s);
        int pos=place(key);
        t[key].name=s; t[key].no=nomor;
    }
    R(i,0,ncari) {
        cin >> s;
        int key=encode(s);
        int nomor=cari(key);
        printf("%d\n", nomor);
    }
    return 0;
}
