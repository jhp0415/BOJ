#include<iostream>
#include<stdio.h>
#include<deque>

using namespace std;

int n, m;
int a[555][555];
int dist[555][555];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
            dist[i][j] = -1;
        }
    }

    //덱 사용하기. 벽을 부쉈으면 back에 삽입, 안부쉈으면 front에 삽입.
    deque<pair<int, int> > dq;
    dist[0][0] = 0;
    dq.push_back(make_pair(0, 0));

    while (!dq.empty())
    {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();

        for (int k = 0; k < 4; k++)
        {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (dist[ny][nx] == -1)
                {
                    if (a[ny][nx] == 0)
                    {
                        //빈공간으로 이동. 앞에 추가한다.
                        dist[ny][nx] = dist[y][x];
                        dq.push_front(make_pair(ny, nx));
                    }
                    else
                    {
                        //벽을 깬 경우. 맨뒤에 삽입한다. 최소 벽깨기가 목표이기 때문에
                        dist[ny][nx] = dist[y][x] + 1;
                        dq.push_back(make_pair(ny, nx));
                    }
                    
                }
            }
        }
    }

    cout << dist[n-1][m-1] << endl;
    return 0;
}

