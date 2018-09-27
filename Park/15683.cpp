#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int a[8][8];
int check[8][8];
int ans = 987654321;
typedef struct camera{
    int cnum;
    int y;
    int x;
};
vector<camera> c;
vector<int> p;

void copy()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check[i][j] = a[i][j];
        }
    }
}

int count()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j] == 0)
                cnt += 1;
        }
    }
    return cnt;
}

void go0(int y, int x)  //북방향 체크
{
    for (int i = y; i >= 0; i--)
    {
        if (a[i][x] == 6) break;
        if (a[i][x] == 0) check[i][x] = -1;
    }
}
void go1(int y, int x)  //동방향 체크
{
    for (int i = x; i < m; i++)
    {
        if (a[y][i] == 6) break;
        if (a[y][i] == 0) check[y][i] = -1;
    }
}
void go2(int y, int x)  //남방향 체크
{
    for (int i = y; i <n; i++)
    {
        if (a[i][x] == 6) break;
        if (a[i][x] == 0) check[i][x] = -1;
    }
}
void go3(int y, int x)  //서방향 체크
{
    for (int i = x; i >= 0; i--)
    {
        if (a[y][i] == 6) break;
        if (a[y][i] == 0) check[y][i] = -1;
    }
}

void camera_check(camera ca, int dir)     //카메라 번호, 방향 번호
{
    if (ca.cnum == 1)   //카메라 번호
    {
        if (dir == 0)
        {
            go0(ca.y, ca.x);
        }
        else if (dir == 1)
        {
            go1(ca.y, ca.x);
        }
        else if (dir == 2)
        {
            go2(ca.y, ca.x);
        }
        else if (dir == 3)
        {
            go3(ca.y, ca.x);
        }
    }
    else if (ca.cnum == 2)
    {
        if (dir == 0 || dir == 2)
        {
            go0(ca.y, ca.x);
            go2(ca.y, ca.x);
        }
        else if (dir == 1 || dir == 3)
        {
            go1(ca.y, ca.x);
            go3(ca.y, ca.x);
        }
    }
    else if (ca.cnum == 3)
    {
        if (dir == 0)
        {
            go0(ca.y, ca.x);
            go1(ca.y, ca.x);
        }
        else if (dir == 1)
        {
            go1(ca.y, ca.x);
            go2(ca.y, ca.x);
        }
        else if (dir == 2)
        {
            go2(ca.y, ca.x);
            go3(ca.y, ca.x);
        }
        else if (dir == 3)
        {
            go0(ca.y, ca.x);
            go3(ca.y, ca.x);
        }
    }
    else if (ca.cnum == 4)
    {
        if (dir == 0)
        {
            go0(ca.y, ca.x);
            go1(ca.y, ca.x);
            go3(ca.y, ca.x);
        }
        else if (dir == 1)
        {
            go0(ca.y, ca.x);
            go1(ca.y, ca.x);
            go2(ca.y, ca.x);
        }
        else if (dir == 2)
        {
            go1(ca.y, ca.x);
            go2(ca.y, ca.x);
            go3(ca.y, ca.x);
        }
        else if (dir == 3)
        {
            go0(ca.y, ca.x);
            go2(ca.y, ca.x);
            go3(ca.y, ca.x);
        }
    }
    else if (ca.cnum == 5)
    {
        go0(ca.y, ca.x);
        go1(ca.y, ca.x);
        go2(ca.y, ca.x);
        go3(ca.y, ca.x);
    }
}


void dfs(int cnt, int max)
{
    if (cnt == max)
    {
        //감시 체크
        copy();
        for (int i = 0; i < max; i++)
        {
            camera_check(c[i], p[i]);
        }

        int cnt = count();
        ans = min(ans, cnt);

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        p.push_back(i);
        dfs(cnt + 1, max);
        p.pop_back();
    }
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0 && a[i][j] != 6)
            {
                c.push_back({ a[i][j], i, j});
            }
        }
    }

    dfs(0, c.size());
    cout << ans << endl;

    return 0;
}