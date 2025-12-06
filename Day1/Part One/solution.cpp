#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(void)
{
    faster();
    int current = 50, password = 0;
    char dirn;
    int rotn;
    while(cin >> dirn >> rotn)
    {
        rotn %= 100;
        if(dirn == 'R')
        {
            current = (current+rotn)%100;
        }
        else
        {
            current = (current >= rotn ? current - rotn : 100 - (rotn - current));
        }
        if(current == 0) password++;
    }
    cout << password;
}
