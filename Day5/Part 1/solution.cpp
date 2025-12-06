#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(void)
{
    faster();
    map<unsigned long long, unsigned long long> mp;
    unsigned long long a, b;
    char ch;
    int ans = 0;

    while(cin >> a >> ch >> b)
    {   
        if(ch != 45) break;
        if(mp[a] == 0) mp[a] = b;
        else mp[a] = max(b, mp[a]);
    }
    unsigned long long k = a;
    while(true)
    {
        for(auto &p : mp)
        {
            if(k >= p.first && k <= p.second)
            {
                ans++;
                break;
            }
        }
        if(k == a)
        {
            k = ch - 48;
            continue;
        }
        if(k == ch-48)
        {
            k = b;
            continue;
        }
        if(k == b) break;
    }
    while(cin >> k)
    {
        for(auto &p : mp)
        {
            if(k >= p.first && k <= p.second)
            {
                ans++;
                break;
            }
        } 
    }

    cout << ans;


}
