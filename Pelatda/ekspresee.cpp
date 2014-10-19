#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

char s[1000];
int ctr = 1;
vector<char> op;
vector<string> eks;
string oa[1000], oi[1000];
char oper[1000];

void evaluate() {
    string bawah = eks.back(); eks.pop_back();
    string atas = eks.back(); eks.pop_back();

    oa[ctr] = atas;
    oi[ctr] = bawah;
    oper[ctr] = op.back();

    string x(1,'x');
    string tmp = "";

    int c = 0;
    int num = ctr;

    while(num>0) { tmp.push_back(num%10+'0'); num/=10; }
    reverse(tmp.begin(), tmp.end());
    x = x + tmp;
    eks.push_back(x);
    op.pop_back(); ctr++;
}

int prec(char ch) {
    if(ch == '-' or ch == '+') return 0;
    if(ch == '/' or ch == '*') return 1;
    return 2;
}

int main() {
    scanf("%s", &s);
    int len = strlen(s);

    for(int i=0; i<len; i++) {
        if(s[i] >= 'a' and s[i] <='z' or s[i] >='A' and s[i] <='Z'){
            string s(1,s[i]);
            eks.push_back(s);
        } else {
            if(op.size() >= 1 and eks.size() >=2) {
                int x = op.back();
                if(x == '^') {
                    if(s[i]=='^') op.push_back(s[i]);
                    else {
                      evaluate();
                      while(!op.empty() and prec(op.back()) >= prec(s[i])) evaluate();
                      op.push_back(s[i]);
                    }
                    //printf("c%c\n", op.top());
                } else if(x == '/' or x == '*') {
                    if(s[i] == '^') {
                    
                        op.push_back(s[i]);  
                    
                    } else {
                    
                        evaluate();
                        while(!op.empty() and prec(op.back()) >= prec(s[i])) evaluate();
                        op.push_back(s[i]);
                    
                    }
                } else if(x == '-' or x == '+') {
                    if(s[i] == '/' or s[i] == '*' or s[i] == '^') {
                    
                        op.push_back(s[i]);
                    
                    } else {
                    
                        evaluate();
                        while(!op.empty() and prec(op.back()) >= prec(s[i])) evaluate();
                        op.push_back(s[i]);
                    
                    }
                } 
                
            } else {
                op.push_back(s[i]);
            }
        }
    }
    while(!op.empty()) evaluate();
    for(int i=1; i<ctr; i++) {
        cout << "x" << i << "=" << oa[i] << oper[i] << oi[i] << endl;
        //printf("x%d=%s%c%s\n", i, oa[i].c_str(), oper[i], oi[i].c_str());
    }
    return 0;
}
