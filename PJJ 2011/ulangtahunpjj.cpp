#include <map>
#include <string>
#include <iostream>
using namespace std;

int norang,nquery;
map<string,string> m;
int main() {
    cin >> norang >> nquery;
    for(int i=0; i<norang; i++) {
        string a,b; cin >> a >> b;
        m[a]=b;
    }
    for(int i=0; i<nquery; i++) {
        string a; cin >> a;
        cout << m[a] << endl;
    }
    return 0;
}
