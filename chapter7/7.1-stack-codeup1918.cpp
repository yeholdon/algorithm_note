#include <cstdio>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

struct node
{
    double num;
    char op;
    bool flag;
};

string str;
stack<node> st;
queue<node> q;
map<char, int> op;

void initOp(map<char, int> &op) {
    op['+'] = 1;
    op['-'] = 1;
    op['*'] = 2;
    op['/'] = 2;
}

string eraseSpace(string str) {
    for (string::iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it == ' ')
        {
            str.erase(it);// pay attention to it otherwise *it
        }
        
    }
    return str;
}

void infixToSuffix(string &str, stack<node> &st, queue<node> &q) {
    str = eraseSpace(str);
    while (!st.empty())
    {
        st.pop();
    }
    while (!q.empty())
    {
        q.pop();
    }

    for (string::iterator it = str.begin(); it != str.end();)
    {
        if (*it >= '0' && *it <= '9')
        {
            string::iterator it2 = it + 1;
            double tmp = *it - '0';
            while (*it2 >= '0' && *it2 <= '9')
            {
                tmp = tmp * 10 + (*it2 - '0');
                it2++;
            }
            node t;
            t.flag = false;// operand
            t.num = tmp;
            q.push(t);
            it = it2;
        }
        else // operator
        {
            node t;
            t.flag = true; 
            while (!st.empty() && op[st.top().op] >= op[*it] )
            {
                q.push(st.top());// note: pop has bo return value
                st.pop();
            }
            t.op = *it;
            st.push(t);
            it++;
        }
        
    }
    // handle the remaining operator
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    
    
}

// calculate suffix expression
double cal(queue<node> q, stack<node> st) { 
    node cur, tmp;
    double operand1, operand2;
    while (!q.empty())
    {
        cur = q.front();
        q.pop(); // remember to pop
        if (cur.flag == false)
        {
            st.push(cur);
        }
        else
        {
            operand2 = st.top().num;
            st.pop();
            operand1 = st.top().num;
            st.pop();
            tmp.flag = false;
            if (cur.op == '+')
            {
                tmp.num = operand1 + operand2;
            }
            else if(cur.op == '-')
            {
                tmp.num = operand1 - operand2;
            }
            else if(cur.op == '*')
            {
                tmp.num = operand1 * operand2;
            }
            else
            {
                tmp.num = operand1 / operand2;
            }
            
            st.push(tmp);
        }
        
        
    }
    return st.top().num;
}

int main() {
    initOp(op);
    while (getline(cin, str) , str != "0")
    {
        infixToSuffix(str, st, q);
        printf("%.2f\n", cal(q, st));
    }

    return 0;
}