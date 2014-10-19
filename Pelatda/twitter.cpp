#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int nakun, nact;
string akun[30], tweet[100];
int siapa[100];
int main() {
    scanf("%d", &nakun);
    R(i,1,nakun+1) {
        cin >> akun[i];
    }
    scanf("%d", &nact);
    R(i,0,nact) {
        int id; scanf("%d", &id);
        siapa[i] = id;
        string action;
        cin >> action;
        if(action=="TWEET") {
            string twit; char dum;
            scanf("%c", &dum);
            scanf("%c", &dum);
            while(dum!='\n') {
                twit.push_back(dum);
                if(scanf("%c", &dum) <=0) break;
            }
            if( twit.length() <= 50) tweet[i] = twit;
            else {
                R(j,0,50) tweet[i].push_back(twit[j]);
            }
        } else
        if(action=="MENTION") {
            int to;
            scanf("%d", &to);
            
            string twit; char dum;
            scanf("%c", &dum);
            scanf("%c", &dum);
            while(dum!='\n') {
                twit.push_back(dum);
                if(scanf("%c", &dum)<=0) break;
            }
            twit = "@" + akun[to] + " " + twit;
            if( twit.length() <= 50) tweet[i] = twit;
            else {
                R(j,0,50) tweet[i].push_back(twit[j]);
            }
        } else {
            int indeks;
            scanf("%d", &indeks);
            
            string twit;
            twit = "RT @" + akun[ siapa[indeks-1] ] + ": " + tweet[ indeks-1 ];
            
            if( twit.length() <= 50) tweet[i] = twit;
            else {
                R(j,0,50) tweet[i].push_back(twit[j]);
            }
        }
    }
    R(i,0,nact) cout << tweet[i] << endl;
}
