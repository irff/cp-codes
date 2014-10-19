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
typedef pair<int,string> PIS;
typedef map<string, bool> MSB;
typedef map<string, MSB> MSR;

int teskes;

MSR m;
MSB blacklist;
string in, now;
PIS out[200];

bool cp(PIS a, PIS b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    getline(cin, in);
    while(in != "0") {
        if(in != "1") {
            bool gede = 1;
            int len = in.length();
            R(i,0,len) if((in[i]<'A' or in[i] >'Z') and in[i] !=' ') gede=0;
            if(gede) {
                //cout << "project : " << in << endl;
                MSB tmp;
                m[in]=tmp;
                now = in;
            } else {
                for(MSR::iterator it=m.begin(); !blacklist[in] and it!=m.end(); it++) {
                    string s = it->first; MSB tmp = it->second;
                    if(s!=now and tmp[in]==1) {
                        blacklist[in]=1;
                        it->second.erase(in);
                    }
                }
                if(!blacklist[in] and !m[now][in]) {
                    m[now][in]=1;
                }
            }
        } else {
            int ctr=0;
            for(MSR::iterator it=m.begin(); it!=m.end(); it++) {
                out[ctr].first = it->second.size();
                out[ctr].second = it->first;
                ctr++;
            }
            blacklist.clear();
            m.clear();
            sort(out, out+ctr, cp );
            R(i,0,ctr) cout << out[i].second << " " << out[i].first << endl;
        }
        getline(cin, in);
    }
    return 0;
}
