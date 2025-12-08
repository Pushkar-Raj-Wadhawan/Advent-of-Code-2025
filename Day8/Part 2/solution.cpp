#include<bits/stdc++.h>
using namespace std;
using number = long long;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

number findDistance(vector<number> &p1, vector<number> &p2)
{
    number d = pow(p1[0]-p2[0], 2ULL) + pow(p1[1]-p2[1], 2ULL) + pow(p1[2]-p2[2], 2ULL);
    return d;
}

bool presence(map<number, number> &mp)
{
    number product = 1;
    for(int i = 0; i < 1000; i++)
    {
        product *= mp[i];
        if(product == 0) return false;
    }
    return true;
}

int main(void)
{
    faster();
    vector<vector<number>> distances;
    vector<vector<number>> points;
    map<number, number> mp;
    number x1, x2;
    for(int i = 0; i < 1000; i++)
    {
        points.emplace_back(3);
        char ch;
        cin >> points[i][0];
        cin >> ch;
        cin >> points[i][1];
        cin >> ch;
        cin >> points[i][2];
    }

    for(int i = 0; i < points.size(); i++)
    {
        for(int j = i+1; j < points.size(); j++)
        {
            distances.push_back({findDistance(points[i], points[j]), i, j});
        }
    }

    sort(distances.begin(), distances.end());
    
    vector<vector<number>> circuits;

    for(int i = 0; ; i++)
    {
        if(mp[distances[i][1]] == 0 && mp[distances[i][2]] == 0)
        {
            circuits.push_back({distances[i][2], distances[i][1]});
            mp[distances[i][2]] = 1;
            mp[distances[i][1]] = 1;
        }
        else if(mp[distances[i][1]] == 1 && mp[distances[i][2]] == 0)
        {
            for(int j = 0; j < circuits.size(); j++)
            {
                for(int k = 0; k < circuits[j].size(); k++)
                {
                    if(circuits[j][k] == distances[i][1])
                    {
                        circuits[j].emplace_back(distances[i][2]);
                        mp[distances[i][2]] = 1;
                    }
                }
            }
        }
        else if(mp[distances[i][2]] == 1 && mp[distances[i][1]] == 0)
        {
            for(int j = 0; j < circuits.size(); j++)
            {
                for(int k = 0; k < circuits[j].size(); k++)
                {
                    if(circuits[j][k] == distances[i][2])
                    {
                        circuits[j].emplace_back(distances[i][1]);
                        mp[distances[i][1]] = 1;
                    }
                }
            }
        }
        else
        {
            int i1 = -1, i2 = -1;
            for(int j = 0; j < circuits.size(); j++)
            {
                for(int k = 0; k < circuits[j].size(); k++)
                {
                    if(circuits[j][k] == distances[i][1]) i1 = j;
                    if(circuits[j][k] == distances[i][2]) i2 = j;
                }
                if(i1 != -1 && i2 != -1) break;
            }
            if(i1 != i2)
            {
                circuits[i1].insert(circuits[i1].end(), circuits[i2].begin(), circuits[i2].end());
                circuits.erase(circuits.begin() + i2);
            }
        }
        if(circuits.size() == 1 && presence(mp))
        {
            x1 = points[distances[i][1]][0];
            x2 = points[distances[i][2]][0];
            cout << "pair : " << i << "\n";
            break;
        }
    }

    sort(circuits.begin(), circuits.end(),
     [](const vector<number>& a, const vector<number>& b) {
         return a.size() > b.size();
     });

    cout << x1*x2;
}
