#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

unsigned long long power(int a)
{
    return a == 0 ? 1ULL : 10ULL * power(a-1);
}

int main(void)
{
    faster();
    unsigned long long net = 0;
    string note;
    while(cin >> note)
    {
        int end = note.size()-12, start = 0;
        while(end < note.size())
        {
            unsigned long long Max = 0;
            for(int i = start; i <= end; i++)
            {
                if(note[i]-48 > Max)
                {
                    Max = note[i]-48;
                    start = i+1;
                }
            }
            net += Max * power(note.size() - end - 1);
            end++;
        }
    }
    cout << net;
}
