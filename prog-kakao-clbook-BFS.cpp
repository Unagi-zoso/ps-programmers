#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);    
    queue<pair<int, int>> q;
    int visited[100][100] = {0, }; 
    
    for (int i=0; i < m; i++)
    {
        for (int j=0; j < n; j++)
        {
            if (picture[i][j] != 0 && visited[i][j] == 0)
            {
                visited[i][j] = 1;
                int cur_val = picture[i][j];
                number_of_area++;
                int one_area_size = 1;                
                q.push({i,j});
                while(!q.empty())
                {
                    pair<int, int> cur = q.front();
                    for (int dir=0; dir < 4; dir++)
                    {
                        int next_x = cur.X+dx[dir];
                        int next_y = cur.Y+dy[dir];
                        if (next_x >= m || next_y >= n || next_x < 0 || next_y < 0) continue;
                        if (picture[next_x][next_y] != cur_val || visited[next_x][next_y] != 0) continue;
                                            
                        visited[next_x][next_y] = 1;
                        q.push({next_x, next_y});
                        one_area_size++;
                    }
                    
                    q.pop();
                }
                max_size_of_one_area = max(one_area_size, max_size_of_one_area);
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}