#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(void)
{
    faster();
    vector<string> grid;
    string s;
    while(cin >> s) grid.push_back(s);
    int len = grid[0].size();
    int ans = 0, i = 0;
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
            }
            j++;
        }
        i++;
    }

    cout << ans;
    
}
