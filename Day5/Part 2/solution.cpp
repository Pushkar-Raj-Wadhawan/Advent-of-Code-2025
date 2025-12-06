#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

map<unsigned long long, unsigned long long> mp;

unsigned long long count(unsigned long long a, unsigned long long b, unsigned long long i)
{
    
    unsigned long long index = i-1, ans = 0, potency = b-a+1;
    for(auto it = next(mp.begin(), i); it != mp.end(); it++)
    {
        index++;
        if((a < it->first && b < it->first) || (a > it->second)) continue;

        // if a is in range
        if(it->first <= a && it->second >= a)
        {
            if(b <= it->second)
            {
                potency = 0;
                break;
            }
            else
            {
                potency -= (it->second - a + 1);
                a = it->second + 1;
                continue;
            }
        }

        // if b is in range
        if(it->first <= b && it->second >= b)
        {
            potency -= (b - it->first + 1);
            b = it->first - 1;
            continue;
        }
        
        // if elements between a and b are in range
        if(a < it->first && b > it->second)
        {
            potency = count(a, it->first - 1, index+1) + count(it->second + 1, b, index+1);
            break;
        }
    }
    return potency;
}



int main(void)
{
    faster();
    unsigned long long a, b, ans = 0;
    char ch;
    while(cin >> a >> ch >> b)
    {
        if(mp[a] == b) continue;
        ans += count (a, b, 0);
        mp[a] = max(b, mp[a]);
    }
    cout << ans;
}
