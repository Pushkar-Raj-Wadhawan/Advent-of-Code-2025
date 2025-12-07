#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(void)
{
    faster();
    vector<string> v;
    string s;
    while(cin >> s) v.emplace_back(s);
    map<pair<unsigned long long, unsigned long long>, unsigned long long> mp;
    unsigned long long timelines = 2;

    for(unsigned long long i = 0; i < v[0].size(); i++)
    {
        if(v[2][i] == '^')
        mp[{2, i}] = 1;
    }

    for(unsigned long long i = 3; i < v.size()-1; i++)
    {
        for(unsigned long long j = 0; j < v[0].size(); j++)
        {
            if(v[i][j] == '^')
            {
                for(unsigned long long k = i-1; k >= 2; k--)
                {
                    if(v[k][j-1] == '^')
                    {
                        mp[{i, j}] += mp[{k, j-1}]; 
                    }
                    else if(v[k][j] == '^')
                    {
                        break;
                    }
                }
                for(unsigned long long k = i-1; k >= 2; k--)
                {
                    if(v[k][j+1] == '^')
                    {
                        mp[{i, j}] += mp[{k, j+1}];
                    }
                    else if(v[k][j] == '^')
                    {
                        break;
                    }
                }
                timelines += mp[{i, j}];
            }
        }
    }

    cout << timelines;
}
