#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <utility>

using namespace std;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;
    vector<pair<int, int>> tops;
    
    // tops initialize
    for (int pos = 0; pos < board.size(); pos++)
    {
        for (int height = 0; height < board.size(); height++)
        {
            if (board[height][pos] != 0)
            {
                tops.push_back({board[height][pos], (board.size()-1)-height});
                break;
            }
            if (height == board.size()-1 && board[height][pos] == 0) tops.push_back({0, 0});
        }
    }

    stk.push(-1);
    for (auto move : moves)
    {
        if (tops[move-1].first != 0)
        {
            if (stk.top() == tops[move-1].first)
            {
                stk.pop();
                answer+=2;
            }
            else stk.push(tops[move-1].first);

            if ((tops[move-1].second) > 0)
            {
                tops[move-1] = {board[(board.size())-tops[move-1].second][move-1], tops[move-1].second-1};
            }
            else tops[move-1] = {0, 0};
        }
    }

    return answer;
}