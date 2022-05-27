#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int get_dist_points(const int pnt1, const int pnt2);
int cmp_points(const int& l_pnt, const int& r_pnt, const int& goal_pnt);

unordered_map<int, pair<int, int>> nptb // numberpad_point_table 
                        {{1,{0, 3}}, {2,{1, 3}}, {3,{2, 3}}, 
                         {4,{0, 2}}, {5,{1, 2}}, {6,{2, 2}}, 
                         {7,{0, 1}}, {8,{1, 1}}, {9,{2, 1}}, 
                         {-1,{0, 0}}, {0,{1, 0}}, {-2,{2, 0}}};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l_finger = -1;
    int r_finger = -2;    
    
    for (auto num : numbers)
    {
        if (num == 3 || num == 6 || num == 9)
        {
            answer += 'R';
            r_finger = num;
        }
        else if (num == 1 || num == 4 || num == 7)
        {
            answer += 'L';
            l_finger = num;
        }
        else
        {
            if (cmp_points(l_finger, r_finger, num) == -1) // r_finger shorter than l
            {
                answer += 'R';
                r_finger = num;
            }
            else if (cmp_points(l_finger, r_finger, num) == -2) // l_finger shorter than r
            {
                answer += 'L';
                l_finger = num;
            }
            else if (cmp_points(l_finger, r_finger, num) == -3) // same case
            {
                if (hand == "right")
                {
                    answer += 'R';
                    r_finger = num;
                }
                else if (hand == "left")
                {
                    answer += 'L';
                    l_finger = num;
                }
            }
        }
    }
    return answer;
}

int get_dist_points(const int pnt1, const int pnt2)
{
    int x_dist = abs(nptb[pnt1].first - nptb[pnt2].first);
    int y_dist = abs(nptb[pnt1].second - nptb[pnt2].second);
        
    return x_dist + y_dist;
}
    
int cmp_points(const int& l_pnt, const int& r_pnt, const int& goal_pnt)
{
    int l_pnt_dist = get_dist_points(l_pnt, goal_pnt);
    int r_pnt_dist = get_dist_points(r_pnt, goal_pnt);
    if (l_pnt_dist > r_pnt_dist) return -1;
    else if (l_pnt_dist < r_pnt_dist) return -2;
    else if (l_pnt_dist == r_pnt_dist) return -3;
}