#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;


map<string,string> name,num;
string op;

int main() {
    while(cin >> op) {
        if(op=="ADD") {
            string a,b;
            cin >> a >> b;
            name[a]=b; num[b]=a;
        } else if(op=="FIND") {
            string a;
            cin >> a;
            map<string,string>::iterator it=name.find(a);
            if(it!=name.end()) cout << it->second << endl;
            else cout << "NO SUCH ENTRY" << endl;
        } else {
            string a;
            cin >> a;
            map<string,string>::iterator it=num.find(a);
            if(it!=num.end()) cout << it->second << endl;
            else cout << "NO SUCH ENTRY" << endl;
        }
    }
    return 0;
}
