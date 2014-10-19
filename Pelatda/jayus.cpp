#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define fs first
#define sc second

typedef long long LLD;
typedef pair<int,string> PSI;
typedef vector<PSI> VSI;

const int INF = 2000111222;

int n;
string s, sa;
VSI v;

int main() {
    cin >> s;
    scanf("%d", &n);
    R(i,0,n) {
        cin >> sa;
        int len = sa.length(), skor = 0;
        R(j,0,n) {
            if(sa[j] != s[j]) skor++;
        }
        v.push_back(PSI(skor, sa));
    }
    sort(v.begin(), v.end());
    cout << s << endl;
    R(i,0,n) {
        cout << v[i].second << endl;
    }
    return 0;
}
