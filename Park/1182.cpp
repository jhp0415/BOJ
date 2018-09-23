#include<iostream>
#include<string.h>

using namespace std;

int n, s;
int ans = 0;
int a[20];
bool check[20];

void go(int cnt, int index, int sum, int max)
{
    if (cnt == max)
    {
        if (sum == s)
            ans += 1;
        return;
    }

    for (int i = index; i < n; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            go(cnt + 1, i + 1, sum + a[i], max);
            check[i] = false;
        }
    }
}

void go2(int cnt, int index, int sum, int max)
{
    if (cnt == max)
    {
        if (sum == s)
            ans += 1;
        return;
    }

    //����
    go(cnt + 1, index + 1, sum + a[index], max);
    //���� ����
    go(cnt, index + 1, sum, max);
}

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        //1-n���� �κ����� ���ϱ�
        go(0, 0, 0, i);
        //go2(0, 0, 0, i);
    }

    cout << ans << endl;

    return 0;
}