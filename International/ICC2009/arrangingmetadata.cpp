#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

#define x first
#define y second

#define name x.x.x
#define type x.x.y
#define day x.y.y.x
#define month x.y.y.y
#define year x.y.x
#define author y.x
#define filesize y.y
#define date x.y

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<string,string> PSS;
typedef pair<PSS,PIII> SSD;
typedef pair<string,int> SI;
typedef pair<SSD,SI> SSDSI;

SSDSI d[100111];
vector<SSDSI> d[
int n;
string action,param;

void show(int i) {
    cout << d[i].name << " " << d[i].type << " ";
    cout << d[i].day << " " << d[i].month << " " << d[i].year << " ";
    cout << d[i].author << " " << d[i].filesize << endl;
}

bool namesort(SSDSI a, SSDSI b) {
    return a.name < b.name;
}

bool typesort(SSDSI a, SSDSI b) {
    return a.type < b.type;
}

bool datesort(SSDSI a, SSDSI b) {
    return a.date < b.date;
}

bool authorsort(SSDSI a, SSDSI b) {
    return a.author < b.author;
}

bool filesizesort(SSDSI a, SSDSI b) {
    return a.filesize < b.filesize;
}

int main() {

    scanf("%d", &n);
    R(i,0,n) {
        cin >> d[i].name >> d[i].type;
        cin >> d[i].day >> d[i].month >> d[i].year;
        cin >> d[i].author >> d[i].filesize;
    }

    while(cin >> action and action!="EXIT") {

        if(action=="SHOW"){
            char s[20];
            scanf("%s", s);
            if(s[0]=='A') {
                R(i,0,n) {
                    show(i);
                }
            } else {
                int x=atoi(s);
                show(x-1);
            }
        } else
        if(action=="SORT") {
            cin >> param;
            if(param=="NAME") {
                sort(d,d+n,namesort);
            } else
            if(param=="TYPE") {
                sort(d,d+n,typesort);
            } else
            if(param=="DATE") {
                sort(d,d+n,datesort);
            } else
            if(param=="AUTHOR") {
                sort(d,d+n,authorsort);
            } else
            if(param=="SIZE") {
                sort(d,d+n,filesizesort);
            }
        }
 
    }
 
    return 0;
}
