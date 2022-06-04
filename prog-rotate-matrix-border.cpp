#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void circul(vector<int> q, int r, int c, vector<vector<int>>& vec, vector<int> &answer)
{
    vector<int> changed_num;
    int x1 = q[1]-1, y1 = q[0]-1, x2 = q[3]-1, y2 = q[2]-1;
    
    vector<int> angle {vec[y1][x2], vec[y2][x2], 
                      vec[y2][x1], vec[y1][x1]};  

    for (int above = x2-1; above >= x1; above--)
    {
        changed_num.emplace_back(vec[y1][above+1]);
        vec[y1][above+1] = vec[y1][above];
    }
    for (int right = y2-1; right >= y1; right--)
    {
        changed_num.emplace_back(vec[right+1][x2]);
        vec[right+1][x2] = vec[right][x2];
    }
    for (int beneath = x1+1; beneath <= x2; beneath++)
    {
        changed_num.emplace_back(vec[y2][beneath-1]);
        vec[y2][beneath-1] = vec[y2][beneath];
    }
    for (int left = y1+1; left <= y2; left++)
    {
        changed_num.emplace_back(vec[left-1][x1]);
        vec[left-1][x1] = vec[left][x1];
    }
    vec[y1+1][x2] = angle[0];
    vec[y2][x2-1] = angle[1];
    vec[y2-1][x1] = angle[2];
    vec[y1][x1+1] = angle[3];
      
    answer.emplace_back(*min_element(changed_num.begin(), changed_num.end()));
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> vec(rows);
    
    for (int num = 1, r = 0; num <= rows*columns; num++)
    {
        
        if (vec[r].size() == columns) r++;
        vec[r].emplace_back(num);        
    }
    
    for (auto q : queries)
    {
        circul(q, rows, columns, vec, answer);   
    }
    
    return answer;
}