#include<iostream>
#include<vector>

using namespace std;

int n, l;
int a[100][100];

vector<pair<int, int> > v;
int ans = 0;

void gogo()
{
    //���� ����
    bool flag = true;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1].first == v[i].first)
        {

        }
        else if (v[i - 1].first - v[i].first > 0)   //ū -> ��
        {
            //�������� L�� �ִ���
            if (v[i].second >= l)
            {
                //L�� ������ ���� ����
                v[i].second -= l;
            }
            else
            {
                //������ ����
                flag = false;
            }
        }
        else if (v[i - 1].first - v[i].first < 0)   //�� -> ū
        {
            //���粨�� L�� �ִ���
            if (v[i - 1].second >= l)
            {
                //������ ���� ����
                v[i - 1].second -= l;
            }
            else
            {
                //������ ����
                flag = false;
            }
        }
        else
        {
            //���� ���̰� 1���� Ŭ ��, ����
            flag = false;
        }
    }
    if (flag == true)
    {
        ans += 1;
    }
}

void go()      //����
{
    for (int i = 0; i < n; i++)
    {
        //�� �྿
        int tmp = a[i][0];
        int tmp_num = 1;
        for (int j = 1; j < n; j++)
        {
            if (tmp == a[i][j])
            {   //���� ���ڶ� ���� ���̸�, ���� ����
                tmp_num += 1;
            }
            else
            {   //�ٸ����̸�, �������� ������ ����
                v.push_back(make_pair(tmp, tmp_num));
                tmp = a[i][j];      //�� �ʱ�ȭ
                tmp_num = 1;
            }
        }
        v.push_back(make_pair(tmp, tmp_num));
        
        gogo();     //�� ���ο� ���� ����

        v.clear();
    }

    //����
    for (int i = 0; i < n; i++)
    {
        //�� �྿
        int tmp = a[0][i];
        int tmp_num = 1;
        for (int j = 1; j < n; j++)
        {
            if (tmp == a[j][i])
            {   //���� ���ڶ� ���� ���̸�, ���� ����
                tmp_num += 1;
            }
            else
            {   //�ٸ����̸�, �������� ������ ����
                v.push_back(make_pair(tmp, tmp_num));
                tmp = a[j][i];      //�� �ʱ�ȭ
                tmp_num = 1;
            }
        }
        v.push_back(make_pair(tmp, tmp_num));

        gogo();     //�� ���ο� ���� ����

        v.clear();
    }
}


int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    go();

    cout << ans << endl;

    return 0;
}