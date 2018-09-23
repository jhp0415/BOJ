#include<iostream>
#include<vector>

using namespace std;

int n;
bool check[4000001];
vector<int> v;
int ans = 0;

void issosu(int x)
{
    for (int i = 2; i <= x; i++)
    {
        if (check[i] == false)
        {
            v.push_back(i);
            for (int j = i * 2; j <= x; j += i)
            {
                check[j] = true;
            }
        }
    }
}



int main()
{
    cin >> n;

    issosu(n);

    int r = 0, l = 0;
    int sum = v.empty() ? 0 : v[0];
    int ans = 0;

    while (l<=r && r<v.size())
    {
        if (sum <= n)
        {
            if (sum == n)
            {
                ans += 1;
            }
            r++;
            if (r < v.size())
            {
                sum += v[r];
            }
        }
        else
        {
            sum -= v[l];
            l++;
        }
    }


    cout << ans << endl;

    return 0;
}