#include <vector>
#include <algorithm>

using namespace std;

int visited[100][100]; 
vector<vector<int>> pic;

int DFS(int x,int y,int color,int m,int n){
    int count=1;
    visited[x][y]=1;
    if(x!=0 && pic[x-1][y]==color && visited[x-1][y]!=1) count+=DFS(x-1,y,color,m,n);
    if(y!=0 && pic[x][y-1]==color && visited[x][y-1]!=1) count+=DFS(x,y-1,color,m,n);
    if(x!=m-1 && pic[x+1][y]==color && visited[x+1][y]!=1) count+=DFS(x+1,y,color,m,n);
    if(y!=n-1 && pic[x][y+1]==color && visited[x][y+1]!=1) count+=DFS(x,y+1,color,m,n);
    return count;

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);    
    pic = move(picture);
    vector<int> count_list;
    for (int i=0; i < m; i++)
    {
        for (int j=0; j< n; j++)
        {
            visited[i][j] = 0;
        }
    }
    
    for (int i=0; i < m; i++)
    {
        for (int j=0; j < n; j++)
        {
            if (pic[i][j] != 0 && visited[i][j] == 0)
            {
                count_list.push_back(DFS(i, j, pic[i][j], m, n));
            }
        }
    }
    
    answer[0] = count_list.size();
    answer[1] = *max_element(count_list.begin(), count_list.end());
    return answer;
}