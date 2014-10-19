#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

typedef pair<int,string> PIS;
typedef map<string, int> MSI;
int teskes, n;
int poin[10] = {25,18,15,12,10,8,6,4,2,1};
vector<PIS> v;
MSI m;

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        v.clear(); m.clear();
        R(i,0,n) {
            R(j,0,10) {
                string s;
                cin >> s;
                m[s]+=poin[j];
            }
        }
        for(MSI::iterator it=m.begin(); it!=m.end(); it++) {
            v.push_back(PIS(-(it->second), it->first));
        }
        sort(v.begin(), v.end());
        int len = v.size();
        R(i,0,len) {
            printf("%d. %d POINT : %s\n", i+1, -v[i].first, v[i].second.c_str());
        }
        printf("---\n");
    }
    return 0;
}
