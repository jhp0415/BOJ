#include<iostream>

using namespace std;

int d[1000001];
int n;


int go(int x)       //����Լ�
{
    if (x == 1) return 0;       //1�̸� �ٷ� 0 ����
    if (d[x] > 0) return d[x];  //�̹� ���� ���� ������ �ٷ� ����

    d[x] = go(x - 1) + 1;
    if (x % 2 == 0)
    {
        int temp = go(x / 2) + 1;
        if (d[x] > temp) d[x] = temp;
    }
    if (x % 3 == 0)
    {
        int temp = go(x / 3) + 1;
        if (d[x] > temp) d[x] = temp;
    }
    return d[x];
}

int go2(int x)      //for�� Ǯ��
{
    d[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0 && d[i] > d[i / 2] + 1)
        {
            d[i] = d[i / 2] + 1;
        }
        if (i % 3 == 0 && d[i] > d[i / 3] + 1)
        {
            d[i] = d[i / 3] + 1;
        }
    }
    return d[x];
}

int main()
{
    cin >> n;

    cout << go2(n) << endl;;



    return 0;
}