#include<vector>
#include <queue>

using namespace std;

struct pos
{
    int y;
    int x;
    
    pos(int _y, int _x) {y=_y; x=_x;}
};


int solution(vector<vector<int> > maps)
{  
    int n = maps[0].size();
    int m = maps.size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    vector<vector<int>> min_dist(m, vector<int>(n));
    queue<pos> q;
    vector<int> y_dir {-1, 0, 1, 0};
    vector<int> x_dir { 0, 1, 0, -1};    
    
    q.push(pos(0, 0));
    visited[0][0] = 1;
    min_dist[0][0] = 1;
    
    while (!q.empty())
    {
        pos p = q.front();
        q.pop();
        int next_y;
        int next_x;
        for (int i=0; i<4; i++)
        {
            next_y = p.y+y_dir[i];
            next_x = p.x+x_dir[i];
            if (next_y < 0 || next_x < 0 || next_y >= m || next_x >= n) continue;
            if (visited[next_y][next_x] == 1) continue;
            if (maps[next_y][next_x] == 0) continue;
            
            q.push(pos(next_y, next_x));
            visited[next_y][next_x] = 1;
            min_dist[next_y][next_x] = min_dist[p.y][p.x] + 1;
            if (next_y == m-1 && next_x == n-1) return min_dist[next_y][next_x];
        }
    }
    return -1;
}