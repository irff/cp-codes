/*
    ID: irfan1
    LANG: C++
    TASK: preface
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb push_back

typedef vector<char> VI;

int m[300];

int n;

VI convert(int n) {
    VI ans;
    int ribuan = n/1000;
    R(i,0,ribuan) ans.pb('M');
    n%=1000;
    int ratusan = n/100;
    if(ratusan<4) R(i,0,ratusan) ans.pb('C');
    if(ratusan==4) { ans.pb('C'); ans.pb('D'); }
    if(ratusan>=5 and ratusan<9) ans.pb('D');
    if(ratusan>5 and ratusan <9) R(i,0,ratusan-5) ans.pb('C');
    if(ratusan==9) { ans.pb('C'); ans.pb('M'); }
    n%=100;
    int puluhan = n/10;
    if(puluhan<4) R(i,0,puluhan) ans.pb('X');
    if(puluhan==4) { ans.pb('X'); ans.pb('L'); }
    if(puluhan>=5 and puluhan < 9) ans.pb('L');
    if(puluhan>5 and puluhan < 9) R(i,0,puluhan-5) ans.pb('X');
    if(puluhan==9) { ans.pb('X'); ans.pb('C'); }
    n%=10;
    if(n<4) R(i,0,n) ans.pb('I');
    if(n==4) { ans.pb('I'); ans.pb('V'); }
    if(n>=5 and n<9) ans.pb('V');
    if(n>5 and n<9) R(i,0,n-5) ans.pb('I');
    if(n==9) { ans.pb('I'); ans.pb('X');}
    return ans;
}

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    scanf("%d", &n);
    R(i,1,n+1) {
        VI x = convert(i);
        int len=x.size();
        R(j,0,len) {
            m[ x[j] ]++;
        }
    }
    if(m['I'] > 0) printf("I %d\n", m['I']);
    if(m['V'] > 0) printf("V %d\n", m['V']);
    if(m['X'] > 0) printf("X %d\n", m['X']);
    if(m['L'] > 0) printf("L %d\n", m['L']);
    if(m['C'] > 0) printf("C %d\n", m['C']);
    if(m['D'] > 0) printf("D %d\n", m['D']);
    if(m['M'] > 0) printf("M %d\n", m['M']);
    return 0;
}
