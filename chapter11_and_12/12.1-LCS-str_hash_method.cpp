/**
 * Given two strings whose length is 
 * no more than 1000, you are supposed to
 * get the longest common substring of them.
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// number system and mod
typedef long long LL;
const LL p = 10000019;
const LL mod = 1000000007;
const LL maxn = 1010;
// to store the common substrings and their hash value
vector<pair<LL, pair<LL, LL> > > substr1, substr2; 
// powP[i] stores the p^i%mod
LL powP[maxn], H1[maxn] = {0}, H2[maxn] = {0};

// init powP[], high digit is in back
void initP(int len) {
    powP[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        powP[i] = (powP[i-1] * p) % mod;
    }
    
}

void calH(LL H[], const string &str) {
    H[0] = str[0];
    for (int i = 0; i < str.size(); i++)
    {
        // there can be numbers in the str
        H[i] = (H[i-1] * p + str[i] - 'a') % mod;
    }
    
}

// calculate single substring's hash value 
// substring's indexes are from i to j
int calSingleH(LL H[], int i, int j) {
    if (i == 0)
    { // i - 1, so note the boundary 
        return H[j];
    }
        
    return ((H[j] - H[i-1] * powP[j - i + 1]) % mod + mod) % mod;

}

// calculate all the substrings of the two strings
void calAllH(LL H[], int len, vector<pair<LL , pair<LL, LL> > > &vp) {
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            int hash = calSingleH(H, i, j);
            vp.push_back(make_pair(hash, make_pair(i, j)));
        }
        
    }
    
}

// to get the longest common substring
string getLCS(vector<pair<LL , pair<LL, LL> > > &a, vector<pair<LL , pair<LL, LL> > > &b, string &str) {
    LL ans = 0LL;
    string res;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i].first == b[j].first)
            {
                if(ans < (a[i].second.second - a[i].second.first + 1)) {
                    ans = a[i].second.second - a[i].second.first + 1;
                    res = str.substr(a[i].second.first, a[i].second.second + 1);
                }
                
            }
            
        }
        
    }
    return res;
}

int main() {
    // input
    string str1("abc"), str2("mabcd");
    getline(cin, str1);
    getline(cin, str2);
    // init
    initP(max(str1.length(), str2.length()));

    
    calH(H1, str1);
    calH(H2, str2);

    calAllH(H1, str1.length(), substr1);
    calAllH(H2, str2.length(), substr2);

    string ans_str = getLCS(substr1, substr2, str1);
    cout << ans_str << endl;
    return 0;
}