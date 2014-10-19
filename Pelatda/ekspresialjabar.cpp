#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

char s[1000];
int ctr = 1;
stack<char> op;
stack<string> eks;
string oa[1000], oi[1000];
char oper[1000];

void evaluate() {
    string bawah = eks.top(); eks.pop();
    string atas = eks.top(); eks.pop();

    oa[ctr] = atas;
    oi[ctr] = bawah;
    oper[ctr] = op.top();

    string x(1,'x');
    string tmp = "";

    int c = 0;
    int num = ctr;

    while(num>0) { tmp.push_back(num%10+'0'); num/=10; }
    reverse(tmp.begin(), tmp.end());
    x = x + tmp;
    eks.push(x);
    op.pop(); ctr++;
}

int prec(char ch) {
    if(ch == '-' or ch == '+') return 0;
    if(ch == '/' or ch == '*') return 1;
    return 2;
}

int main() {
    scanf("%s", &s);
    printf("%s\n", s);
    int len = strlen(s);

    for(int i=0; i<len; i++) {
        if(s[i] >= 'a' and s[i] <='z' or s[i] >='A' and s[i] <='Z'){
            string s(1,s[i]);
            eks.push(s);
        } else {
            if(op.size() >= 1 and eks.size() >=2) {
                int x = op.top();
                if(x == '^') {
                    if(s[i]=='^') op.push(s[i]);
                    else {
                      evaluate();
                      while(!op.empty() and prec(op.top()) >= prec(s[i])) evaluate();
                      op.push(s[i]);
                    }
                    //printf("c%c\n", op.top());
                } else if(x == '/' or x == '*') {
                    if(s[i] == '^') {
                    
                        op.push(s[i]);  
                    
                    } else {
                    
                        evaluate();
                        while(!op.empty() and prec(op.top()) >= prec(s[i])) evaluate();
                        op.push(s[i]);
                    
                    }
                } else if(x == '-' or x == '+') {
                    if(s[i] == '/' or s[i] == '*' or s[i] == '^') {
                    
                        op.push(s[i]);
                    
                    } else {
                    
                        evaluate();
                        while(!op.empty() and prec(op.top()) >= prec(s[i])) evaluate();
                        op.push(s[i]);
                    
                    }
                } 
                
            } else {
                op.push(s[i]);
            }
        }
    }
    //while(!op.empty()) evaluate();
    for(int i=1; i<ctr; i++) {
        cout << "x" << i << "=" << oa[i] << oper[i] << oi[i] << endl;
        //printf("x%d=%s%c%s\n", i, oa[i].c_str(), oper[i], oi[i].c_str());
    }
    return 0;
}
