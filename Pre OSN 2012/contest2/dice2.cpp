#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define fs first
#define sc second

typedef map<int,int> MII;
typedef pair<int,int> PII;
typedef long long LLD;
int teskes;
vector<string> key;

void rek(string s, int step, int arah, string a) {
    if(arah==0) {
        //atas
        char tmp=s[0];
        s[0]=s[1];
        s[1]=s[5];
        s[5]=s[4];
        s[4]=tmp;
        a.push_back('0');
    }
    if(arah==1) {
        //kanan
        char tmp=s[2];
        s[2]=s[4];
        s[4]=s[3];
        s[3]=s[1];
        s[1]=tmp;
        a.push_back('1');
    }
    if(arah==2) {
        //bawah
        char tmp=s[1];
        s[1]=s[0];
        s[0]=s[4];
        s[4]=s[5];
        s[5]=tmp;
        a.push_back('2');
    }
    if(arah==3) {
        //kiri
        char tmp=s[1];
        s[1]=s[3];
        s[3]=s[4];
        s[4]=s[2];
        s[2]=tmp;
        a.push_back('3');
    }
    bool ketemu=0;
    R(i,0,key.size()) {
        if(key[i]==s) { ketemu=1; break; }
    }
    if(!ketemu) key.push_back(s);
    if(step > 3) return;
    if(arah!=2) rek(s,step+1,0,a);
    if(arah!=3) rek(s,step+1,1,a);
    if(arah!=0) rek(s,step+1,2,a);
    if(arah!=1) rek(s,step+1,3,a);
}
char sa[100], si[100];
char k[30][10];
string a;
int main() {
    string s = "012345";
    rek(s,0,-1,a);
    //R(i,0,key.size()) cout << key[i] << endl;
    while(scanf("%s", &sa)>0) {
        R(i,0,6) si[i]=sa[i+6];
        bool ketemu=0;
        R(i,0,24) {
            R(j,0,6) {
                k[i][j] = sa[ key[i][j]-'0'];
            }
            if(strcmp(si, k[i])==0) ketemu=1;
        }
        printf("%s\n", ketemu?"TRUE":"FALSE");
    }
    return 0;
}
