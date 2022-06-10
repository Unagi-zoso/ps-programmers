#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> vec;

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
        if (num%i == 0)
            return false;
    return true;
}

void comb(string s, int pos, string cur_s)
{
    if (pos == s.size()) 
    {
        if (cur_s[0] == 0 || stoi(cur_s) == 0 || stoi(cur_s) == 1) return;
        vec.emplace_back(stoi(cur_s));
        return;
    }
    comb(s, pos+1, cur_s+s[pos]);
    comb(s, pos+1, cur_s);
}

int solution(string numbers) {
    int answer = 0;
    if (numbers == "0") return 0;
    
    // take vector all subset
    sort(numbers.begin(), numbers.end());
    do
    {
        comb(numbers, 0, "");
    }
    while (next_permutation(numbers.begin(), numbers.end()));

    // remove overlap
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (auto num : vec)
        if (isPrime(num) == true) answer++;
    
    return answer;
}