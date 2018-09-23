#include<iostream>

using namespace std;

int n;
int a[100000];
long long m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int r = 0, l = 0;
    int sum = a[0];
    int ans = 987654321;
    int length = 0;
    while (r>=l && r < n)
    {
        if (sum < m)
        {
            r++;
            sum += a[r];
        }
        else if (sum > m)
        {
            length = r - l + 1;
            if (length < ans)
                ans = length;

            sum -= a[l];
            l++;
            
        }
        else
        {
            length = r - l + 1;
            if (length < ans)
                ans = length;
            r++;
            sum += a[r];
        }
    }
    if (ans > n)
        ans = 0;

    cout << ans << endl;

    return 0;
}