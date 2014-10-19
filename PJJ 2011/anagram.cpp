#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int n;
pair<string,string> s[12000];
map<string,int> m;
string ana;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s[i].first;
        string tmp=s[i].first;
        sort(tmp.begin(),tmp.end());
        s[i].second=tmp;
        m[tmp]++;
    }
    
    int maks=-1;
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++) {
        if(it->second > maks) {
            maks=it->second;
        }
    }
    
    if(maks>1) {
        sort(s,s+n);
        bool uda=0;
        R(i,0,n) {
            if(m[ s[i].second ]==maks and !uda) {
                ana=s[i].second;
                uda=1;
            }
            if(uda) if(s[i].second==ana) cout << s[i].first << endl;       
        }
    } else cout << "TIDAK ADA" << endl;
       
    return 0;
}
