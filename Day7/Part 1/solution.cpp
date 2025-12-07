#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(void)
{
    faster();
    vector<string> v;
    string s;
    while(cin >> s) v.emplace_back(s);
    int splits = 0;
    for(int i = 0; i < v[0].size(); i++)
    {
        if(v[0][i] == 'S')
        {
            v[1][i] = '|';
            break; 
        }
    }

    for(int i = 1; i < v.size()-1; i++)
    {
        for(int j = 0; j < v[0].size(); j++)
        {
            if(v[i][j] == '|')
            {
                if(v[i+1][j] == '.') v[i+1][j] = '|';
                else if(v[i+1][j] == '^')
                {
                    splits++;
                    v[i+1][j+1] = '|';
                    v[i+1][j-1] = '|';
                }
            }
            else continue;
        }
    }

    cout << splits;
}
