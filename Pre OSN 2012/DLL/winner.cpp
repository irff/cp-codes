#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;

string winner, name[2000];
int maks = -2000111222, score[2000], n;

map<string, int> m, winners;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        cin >> name[i] >> score[i];
        m[name[i]]+=score[i];
    }
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++) {
        if(it->second > maks) maks=it->second;
    }
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++) {
        if(it->second == maks) winners[it->first]=1;
    }
    m.clear();
    for(int i=0; i<n; i++) {
        if(winners[name[i]]) {
            m[name[i]]+=score[i];
            if(m[name[i]]>=maks) {
                winner = name[i];
                break;
            }
        }
    }
    printf("%s\n", winner.c_str());
    return 0;
}
