#include<bits/stdc++.h>
using namespace std;

using number = unsigned long long;
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(void)
{
    faster();
    vector<number> list;
    string s = "";
    char ch;
    number a;
    while (true)
    {
        if(cin >> a)
        {
            list.emplace_back(a);
            continue;
        }
        else
        {
            cin.clear();
            break;
        }
    }
    while(cin >> ch) s += ch;

    int n = s.size(), m = list.size()/s.size();
    number net = 0;
    for(int i = 0; i < n; i++)
    {
        number ans;
        if(s[i] == '*')
        {
            ans = 1;
            for(int j = i; j < m*n; j += n)
            {
                ans *= list[j];
            }
        }
        else
        {
            ans = 0;
            for(int j = i; j < m*n; j += n)
            {
                ans += list[j];
            }
        }
        net += ans;
    }
    cout << net;
}
