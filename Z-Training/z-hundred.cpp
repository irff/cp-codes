#include <iostream>
#include <set>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int n,k;
string s[2011],str;
set<string> tmp;
bool mantab(string a, string b){
    int lena=a.size(),leni=b.size();
    if(lena!=leni) return lena<leni;
    int x=0;
    while(a[x]==b[x]){
        x++;
    }
    return a[x]<b[x];
}

int main(){
    scanf("%d%d", &n,&k);
    for(int i=0; i<n; i++){
        cin >> str;
        tmp.insert(str);
    }
    int ctr=0;
    for(set<string>::iterator it=tmp.begin(); it!=tmp.end(); it++){
        s[ctr]=*it;
        ctr++;
    }
    unique(s,s+ctr);
    cout << s[k-1] << endl;
    return 0;
}
