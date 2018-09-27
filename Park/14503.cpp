#include<iostream>
#include<queue>

using namespace std;

int n, m;
int r, c, d;
int map[50][50];        //0 빈공간, 1 벽, 2 청소함
int check[50][50];      //청소 여부 체크하기
int dy[] = { -1,0,1,0 };    //북, 동, 남, 서
int dx[] = { 0,1,0,-1 };
int ans = 0;        //청소하는 칸의 개수
bool flag = false;  //사방이 막혔는지, 아닌지 확인하는 플래그

int dir(int x)      //왼쪽 회전 방향 리턴 함수
{
    if (x == 0)     //북
        return 3;   //서
    else if (x == 1) //동
        return 0;    //북
    else if (x == 2)
        return 1;   //동
    else if (x == 3)    //서
        return 2;   //남
}

int dir2(int x)     //후진 방향 리턴 함수
{
    if (x == 0)     //북
        return 2;   //남
    else if (x == 1) //동
        return 3;    //tj
    else if (x == 2)
        return 0;   //북
    else if (x == 3)    //서
        return 1;   //동
}


void go()
{
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    check[r][c] = 2;
    ans += 1;

    while (!q.empty())
    {
        flag = false;
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            d = dir(d);
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (check[ny][nx] == 0)     //빈공간이면
                {
                    check[ny][nx] = 2;      //청소하기
                    ans += 1;       
                    //현재 방향 유지한채로 좌표 이동
                    q.push(make_pair(ny, nx));
                    flag = true;        
                    break;
                }
            }
        }
        if(flag == false)       //사방이 막혀서 청소를 하지 못한경우
        {
            //현재 방향을 기준으로 뒤로 후진한다.
            int direction = dir2(d);
            int ny = y + dy[direction];
            int nx = x + dx[direction];

            if (check[ny][nx] != 1)     //후진하는 곳이 벽이 아니면
            {
                q.push(make_pair(ny, nx));  //후진
            }
            else if (check[ny][nx] == 1)    //만약 후진하는 곳이 벽인 경우, 종료한다.
            {
                return;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            check[i][j] = map[i][j];
        }
    }

    go();
    cout << ans << endl;

    return 0;
}