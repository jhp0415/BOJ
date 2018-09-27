#include<iostream>
#include<queue>

using namespace std;

int n, m;
int r, c, d;
int map[50][50];        //0 �����, 1 ��, 2 û����
int check[50][50];      //û�� ���� üũ�ϱ�
int dy[] = { -1,0,1,0 };    //��, ��, ��, ��
int dx[] = { 0,1,0,-1 };
int ans = 0;        //û���ϴ� ĭ�� ����
bool flag = false;  //����� ��������, �ƴ��� Ȯ���ϴ� �÷���

int dir(int x)      //���� ȸ�� ���� ���� �Լ�
{
    if (x == 0)     //��
        return 3;   //��
    else if (x == 1) //��
        return 0;    //��
    else if (x == 2)
        return 1;   //��
    else if (x == 3)    //��
        return 2;   //��
}

int dir2(int x)     //���� ���� ���� �Լ�
{
    if (x == 0)     //��
        return 2;   //��
    else if (x == 1) //��
        return 3;    //tj
    else if (x == 2)
        return 0;   //��
    else if (x == 3)    //��
        return 1;   //��
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
                if (check[ny][nx] == 0)     //������̸�
                {
                    check[ny][nx] = 2;      //û���ϱ�
                    ans += 1;       
                    //���� ���� ������ä�� ��ǥ �̵�
                    q.push(make_pair(ny, nx));
                    flag = true;        
                    break;
                }
            }
        }
        if(flag == false)       //����� ������ û�Ҹ� ���� ���Ѱ��
        {
            //���� ������ �������� �ڷ� �����Ѵ�.
            int direction = dir2(d);
            int ny = y + dy[direction];
            int nx = x + dx[direction];

            if (check[ny][nx] != 1)     //�����ϴ� ���� ���� �ƴϸ�
            {
                q.push(make_pair(ny, nx));  //����
            }
            else if (check[ny][nx] == 1)    //���� �����ϴ� ���� ���� ���, �����Ѵ�.
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