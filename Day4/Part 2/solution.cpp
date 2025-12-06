#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(void)
{
    faster();
    vector<string> grid;
    string s;
    while(cin >> s) grid.push_back(s);
    int len = grid[0].size(), net = 0;
    bool removed = true;
    while(removed)
    {
        int ans = 0, i = 0;
        vector<pair<int, int>> v;
        while(i < grid.size())
        {
            int j = 0;
            while(j < len)
            {
                if(grid[i][j] != '@')
                {
                    j++;
                    continue;
                }
                int count = 0;
    
                // (1,2)
                if(i != 0 && grid[i-1][j] == '@') count++;
                
                // (1,1) (2,1) (3,1)
                if(j != 0)
                {
                    if(i != 0 && grid[i-1][j-1] == '@') count++;
                    if(grid[i][j-1] == '@') count++;
                    if(i != grid.size() - 1 && grid[i+1][j-1] == '@') count++;
                }
                
                // (1,3) (2,3) (3,3)
                if(j != len-1)
                {
                    if(i != 0 && grid[i-1][j+1] == '@') count++;
                    if(grid[i][j+1] == '@') count++;
                    if(i != grid.size() - 1 && grid[i+1][j+1] == '@') count++;
                }
                
                // (2,3)
                if(i != grid.size()-1 && grid[i+1][j] == '@') count++;
                
                if(count < 4)
                {
                    ans++;
                    v.emplace_back(i, j);
                }
                j++;
            }
            i++;
        }
        if(ans == 0) removed = false;
        else
        {
            net += ans;
            for(int k = 0; k < v.size(); k++)
            {
                grid[v[k].first][v[k].second] = '.';
            }
        }
    }

    cout << net;
    
}
