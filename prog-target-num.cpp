#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int& target, int sum, int height, int& answer)
{
    if (height == numbers.size())
    {
        if (sum == target) { answer++; return; }
        else { return; }
    }
    
    DFS(numbers, target, sum + numbers[height], height+1, answer);       
    DFS(numbers, target, sum - numbers[height], height+1, answer);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;
    DFS(numbers, target, sum, 0, answer);
    
    return answer;
}