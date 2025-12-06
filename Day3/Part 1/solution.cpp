#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(void)
{
    faster();
    unsigned long long net = 0;
    string note;
    while(cin >> note)
    {
        int max1 = 0, max2 = 0, max1i, max2i;
        for(int i = 0; i < note.size(); i++)
        {
            int digit = note[i] - 48;
            if(digit > max1)
            {
                max1 = digit;
                max1i = i;
            }
        }
        if(max1i == note.size()-1)
        {
            for(int i = 0; i < note.size()-1; i++)
            {
                int digit = note[i] - 48;
                if(digit > max2)
                {
                    max2 = digit;
                    max2i = i;
                }
            }
            net += max2*10 + max1;
        }
        else
        {
            for(int i = max1i+1; i < note.size(); i++)
            {
                int digit = note[i] - 48;
                if(digit > max2)
                {
                    max2 = digit;
                    max2i = i;
                }
            }
            net += max1*10 + max2;
        }
    }
    cout << net;
}
