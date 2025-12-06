#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int digitCount(unsigned long long a)
{
    unsigned long long num = a;
    int ans = 0;
    while(num > 0)
    {
        num /= 10;
        ans++;
    }
    return ans;
}

int power(int a)
{
    return a == 0 ? 1 : 10 * power(a-1);
}

int main(void)
{
    faster();
    unsigned long long start, end, sum = 0;
    char ch;
    do
    {
        cin >> start >> ch >> end;
        if(digitCount(start) % 2 != 0 && digitCount(end) == digitCount(start)) 
        {
            continue;
        }
        unsigned long long num = start;
        while(num <= end)
        {
            int digits = digitCount(num);
            if(digits % 2 != 0)
            {
                num = pow(10, digits);
            }
            else
            {

                unsigned long long left = num / power(digits/2);
                unsigned long long right = num - left*(power(digits/2));
                if(left == right)
                {
                    sum += num; 
                }
            }
            num++;
        }

    } while (cin >> ch);
    
    cout << sum;

}
