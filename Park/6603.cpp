#include<iostream>
#include<string.h>

using namespace std;


int k;
int a[13];
bool check[50];
int ans[13];

void go(int cnt, int index)
{
    if (cnt == 6)
    {
        //출력
        for (int i = 0; i < 6; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    if (index >= k)
        return;
    //선택하는 경우
    ans[cnt] = a[index];
    go(cnt + 1, index + 1);

    //선택하지 않는 경우
    go(cnt, index + 1);
}

void combination(int num, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

    for (int i = num; i < k; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            ans[cnt] = a[i];
            combination(i + 1, cnt + 1);
            check[i] = false;
        }
    }
}

int main()
{
    while (1)
    {
        memset(ans, 0, sizeof(ans));
        memset(a, 0, sizeof(a));
        memset(check, false, sizeof(check));
        cin >> k;
        if (k == 0)
            break;

        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }

        //둘 중 택1
        go(0, 0);
        //combination(0, 0);

        cout << endl;
    }

    return 0;
}
