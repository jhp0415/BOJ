#include<iostream>
#include<vector>

using namespace std;

int n, l;
int a[100][100];

vector<pair<int, int> > v;
int ans = 0;

void gogo()
{
    //경사로 놓기
    bool flag = true;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1].first == v[i].first)
        {

        }
        else if (v[i - 1].first - v[i].first > 0)   //큰 -> 작
        {
            //다음꺼가 L개 있는지
            if (v[i].second >= l)
            {
                //L개 있으면 경사로 놓기
                v[i].second -= l;
            }
            else
            {
                //없으면 실패
                flag = false;
            }
        }
        else if (v[i - 1].first - v[i].first < 0)   //작 -> 큰
        {
            //현재꺼가 L개 있는지
            if (v[i - 1].second >= l)
            {
                //있으면 경사로 놓기
                v[i - 1].second -= l;
            }
            else
            {
                //없으면 실패
                flag = false;
            }
        }
        else
        {
            //높이 차이가 1보다 클 때, 실패
            flag = false;
        }
    }
    if (flag == true)
    {
        ans += 1;
    }
}

void go()      //가로
{
    for (int i = 0; i < n; i++)
    {
        //한 행씩
        int tmp = a[i][0];
        int tmp_num = 1;
        for (int j = 1; j < n; j++)
        {
            if (tmp == a[i][j])
            {   //이전 숫자랑 같은 값이면, 개수 증가
                tmp_num += 1;
            }
            else
            {   //다른값이면, 이제까지 개수를 저장
                v.push_back(make_pair(tmp, tmp_num));
                tmp = a[i][j];      //값 초기화
                tmp_num = 1;
            }
        }
        v.push_back(make_pair(tmp, tmp_num));
        
        gogo();     //한 라인에 경사로 놓기

        v.clear();
    }

    //세로
    for (int i = 0; i < n; i++)
    {
        //한 행씩
        int tmp = a[0][i];
        int tmp_num = 1;
        for (int j = 1; j < n; j++)
        {
            if (tmp == a[j][i])
            {   //이전 숫자랑 같은 값이면, 개수 증가
                tmp_num += 1;
            }
            else
            {   //다른값이면, 이제까지 개수를 저장
                v.push_back(make_pair(tmp, tmp_num));
                tmp = a[j][i];      //값 초기화
                tmp_num = 1;
            }
        }
        v.push_back(make_pair(tmp, tmp_num));

        gogo();     //한 라인에 경사로 놓기

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