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

    vector<string> numbers;
    vector<number> size;

    for(int i = 0; i < list.size(); i++)
    {
        numbers.emplace_back(to_string(list[i]));
    }

    for(int i = 0; i < n; i++)
    {
        number maxDigit = 0;
        for(int j = i; j < m*n; j += n)
        {
            maxDigit = max(maxDigit, (number)numbers[j].size());
        }
        size.emplace_back(maxDigit);
    }
    // for(int i = 0; i < n; i++)
    // {
    //     cout << size[i] << " ,";
    // }
    cout << n << " " << m;
}
