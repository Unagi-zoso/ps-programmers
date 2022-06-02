#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    int a, b;
    make_heap(scoville.begin(), scoville.end(), greater<int>());

    while (scoville.front() < k && scoville.size() > 1)
    {
        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        a = scoville.back();
        scoville.pop_back();
    
        cout << endl;
        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        b = scoville.back();
        scoville.pop_back();
        
        scoville.emplace_back(2 * b + a);
        answer++;
    }
    if (scoville.size() == 1 && scoville.front() < k) return -1;
    return answer;
}