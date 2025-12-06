#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(void)
{
    faster();
    unsigned long long start, end, sum = 0;
    char ch;
    do
    {
        cin >> start >> ch >> end;

        unsigned long long num = start;
        while(num <= end)
        {
            string snum = to_string(num);
            for(int i = 1; i <= snum.size()/2; i++)
            {
                if(snum.size()%i != 0) continue;
                string basis = snum.substr(0, i);
                int j = i;
                bool invalid = true;
                while(j < snum.size())
                {

                    string test = snum.substr(j, i);
                    if(test != basis)
                    {
                        invalid = false;
                        break;
                    }
                    j += i;
                }   
                if(invalid)
                {
                    sum += num;
                    break;
                }       
            }
            num++;
        }

    } while (cin >> ch);
    
    cout << sum;

}
