#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int chicken_num = 0;      //치킨집 개수
int home_num = 0;           //집의 개수
int dist[50][50];
int map[50][50];
int index[50][50];
bool check[50][50];
int chicken[13];
int home[100];
int choice[13];
int ans = 987654321;

void distance()     //거리 계산하기
{
    int sum = 0;      //거리 값 저장
    for (int i = 0; i < home_num; i++)
    {
        //집의 개수만큼 반복문 실행
        int h_y = home[i] / n;      //현재 계산할 집의 좌표
        int h_x = home[i] % n;
        int temp = 987654321;
        for (int j = 0; j < m; j++)
        {
            //선택된 치킨집들 각각에 대해 거리를 구하고 그 중 최소 거리.
            int c_y = choice[j] / n;
            int c_x = choice[j] % n;
            
            int ddd = ((h_y - c_y) > 0 ? (h_y - c_y) : -(h_y - c_y))
                + ((h_x - c_x) > 0 ? (h_x - c_x) : -(h_x - c_x));
            temp = min(temp, ddd);      //집 한개를 기준으로 최소 치킨거리 저장.
        }
        sum += temp;
    }
    ans = min(ans, sum);        //정답 저장. 최소 도시의 치킨 거리.
}

void combination(int cnt, int id)      //치킨집 선택하기
{
    if (id > chicken_num) return;
    if (cnt == m)
    {
        //치킨집 선택완료
        distance();     //선택된 치킨집으로 기준으로 거리 계산하기
        return;
    }

    //for (int i = id; i < chicken_num; i++)
    //{
    //    if (check[chicken[i] / n][chicken[i] % n] == false)
    //    {
    //        check[chicken[i] / n][chicken[i] % n] = true;
    //        choice[cnt] = chicken[i];       //선택한 치킨집 저장
    //        combination(cnt + 1, id + 1);
    //        check[chicken[i] / n][chicken[i] % n] = false;
    //    }
    //}

    //선택하는 경우
    choice[cnt] = chicken[id];
    combination(cnt + 1, id + 1);

    //선택하지 않는 경우
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
            if (map[i][j] == 2)     //치킨집 저장
            {
                chicken[chicken_num++] = index[i][j];
            }
            if (map[i][j] == 1)     //집 저장
            {
                home[home_num++] = index[i][j];
            }
        }
    }

    combination(0, 0);
    cout << ans << endl;

    return 0;
}