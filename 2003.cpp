#include<iostream>

using namespace std;


int n;
long long m;
int a[10000];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int r = 0, l = 0;
    int sum = a[0];
    int ans = 0;
    while (r < n && l < n)
    {
        if (sum < m)
        {
            r++;
            sum += a[r];
        }
        else if(sum > m)
        {
            sum -= a[l];
            l++;
        }
        else
        {
            ans += 1;
            r++;
            sum += a[r];
        }
    }

    cout << ans << endl;

    return 0;
}