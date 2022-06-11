// DFS 효율성 실패.

#include <vector>
#include <algorithm>

#define XPOS first
#define YPOS second

using namespace std;

int x_dir[4] = { 1,-1, 0, 0 };
int y_dir[4] = { 0, 0, 1, -1 };

vector<int> vec_shrt_path;

void dfs(vector<vector<int>> m, pair<int, int> pos, vector<vector<int>> visited, int cur_leng)
{
    if (pos.XPOS == 4 && pos.YPOS == 4) vec_shrt_path.emplace_back(++cur_leng);
    if (pos.XPOS >= 0 && pos.YPOS >= 0 && pos.XPOS < 5 && pos.YPOS < 5 && visited[pos.XPOS][pos.YPOS] == 0 && m[pos.XPOS][pos.YPOS] == 1)
    {
        int cur = ++cur_leng;
        visited[pos.XPOS][pos.YPOS] = 1;
        dfs(m, make_pair(pos.XPOS + x_dir[0], pos.YPOS + y_dir[0]), visited, cur);
        dfs(m, make_pair(pos.XPOS + x_dir[1], pos.YPOS + y_dir[1]), visited, cur);
        dfs(m, make_pair(pos.XPOS + x_dir[2], pos.YPOS + y_dir[2]), visited, cur);
        dfs(m, make_pair(pos.XPOS + x_dir[3], pos.YPOS + y_dir[3]), visited, cur);
    }
    vec_shrt_path.emplace_back(-1);
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), 0));
    pair<int, int> dir = make_pair(0, 0);
    dfs(maps, dir, visited, 0);

    sort(vec_shrt_path.begin(), vec_shrt_path.end());
    if (vec_shrt_path.back() == -1) return -1;

    vec_shrt_path.erase(remove_if(vec_shrt_path.begin(), vec_shrt_path.end(), [](int i) -> bool
        {return i == -1; }), vec_shrt_path.end());
    answer = vec_shrt_path.front();

    return answer;
}