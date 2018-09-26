#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int chicken_num = 0;      //ġŲ�� ����
int home_num = 0;           //���� ����
int dist[50][50];
int map[50][50];
int index[50][50];
bool check[50][50];
int chicken[13];
int home[100];
int choice[13];
int ans = 987654321;

void distance()     //�Ÿ� ����ϱ�
{
    int sum = 0;      //�Ÿ� �� ����
    for (int i = 0; i < home_num; i++)
    {
        //���� ������ŭ �ݺ��� ����
        int h_y = home[i] / n;      //���� ����� ���� ��ǥ
        int h_x = home[i] % n;
        int temp = 987654321;
        for (int j = 0; j < m; j++)
        {
            //���õ� ġŲ���� ������ ���� �Ÿ��� ���ϰ� �� �� �ּ� �Ÿ�.
            int c_y = choice[j] / n;
            int c_x = choice[j] % n;
            
            int ddd = ((h_y - c_y) > 0 ? (h_y - c_y) : -(h_y - c_y))
                + ((h_x - c_x) > 0 ? (h_x - c_x) : -(h_x - c_x));
            temp = min(temp, ddd);      //�� �Ѱ��� �������� �ּ� ġŲ�Ÿ� ����.
        }
        sum += temp;
    }
    ans = min(ans, sum);        //���� ����. �ּ� ������ ġŲ �Ÿ�.
}

void combination(int cnt, int id)      //ġŲ�� �����ϱ�
{
    if (id > chicken_num) return;
    if (cnt == m)
    {
        //ġŲ�� ���ÿϷ�
        distance();     //���õ� ġŲ������ �������� �Ÿ� ����ϱ�
        return;
    }

    //for (int i = id; i < chicken_num; i++)
    //{
    //    if (check[chicken[i] / n][chicken[i] % n] == false)
    //    {
    //        check[chicken[i] / n][chicken[i] % n] = true;
    //        choice[cnt] = chicken[i];       //������ ġŲ�� ����
    //        combination(cnt + 1, id + 1);
    //        check[chicken[i] / n][chicken[i] % n] = false;
    //    }
    //}

    //�����ϴ� ���
    choice[cnt] = chicken[id];
    combination(cnt + 1, id + 1);

    //�������� �ʴ� ���
    combination(cnt, id + 1);
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            index[i][j] = n * i + j;
            if (map[i][j] == 2)     //ġŲ�� ����
            {
                chicken[chicken_num++] = index[i][j];
            }
            if (map[i][j] == 1)     //�� ����
            {
                home[home_num++] = index[i][j];
            }
        }
    }

    combination(0, 0);
    cout << ans << endl;

    return 0;
}