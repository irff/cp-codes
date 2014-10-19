#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct data {
    string no,email,ttl;
} ;

map<string,data> m;
map<string,string> mno,memail,mttl;
string op;
int main() {
    while(cin >> op) {
        if(op=="ADD") {
            string a,b,c,d;
            cin >> a >> b >> c >> d;
            data tmp; tmp.no=b,tmp.email=c,tmp.ttl=d;
            m[a]=tmp;
            mno[b]=a; memail[c]=a; mttl[d]=a;
        } else {
            string a;
            cin >> a;
            if(m.find(a)!=m.end()) {
                cout << "nama, " << m[a].no << " " << m[a].email <<" "<< 
                m[a].ttl << endl;
            } else
            if(mno.find(a)!=mno.end()) {
                string s=mno[a]; data tmp=m[s];
                cout << "nomor telepon, " << s << " " << tmp.email << " "<< 
                tmp.ttl << endl;
            } else
            if(memail.find(a)!=memail.end()) {
                string s=memail[a]; data tmp=m[s];
                cout << "email, " << s << " " << tmp.no <<" " << 
                tmp.ttl << endl;
            } else
            if(mttl.find(a)!=mttl.end()) {
                string s=mttl[a]; data tmp=m[s];
                cout << "tanggal lahir, " << s << " " << tmp.no << " " <<
                tmp.email << endl;
            } else cout << "NO SUCH ENTRY" << endl;
        }
    }
    return 0;
}
