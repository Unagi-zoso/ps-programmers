using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while (1)
    {
        answer++;
        if (a == b) return answer-1;
        
        if (a % 2 == 0) a /= 2;
        else  a = (a+1)/2;
        if (b % 2 == 0) b /= 2;
        else  b = (b+1)/2;
    }

    return answer;
}