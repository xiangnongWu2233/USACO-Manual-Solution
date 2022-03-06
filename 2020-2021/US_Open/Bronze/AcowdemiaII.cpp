#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
map<string, map<string, string> > answer;
string name[101];
string order[101][101];
int main()
{
    int K, n, i, j, k, l;
    cin >> K >> n;
    for (i = 1; i <= n; i++)
        cin >> name[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            answer[name[i]][name[j]] = '?';
    

    for (i = 1; i <= K; i++)
        for (j = 1; j <= n; j++)
            cin >> order[i][j];
    for (i = 1; i <= K; i++)
        for (j = 1; j <= n - 1; j++)
            if(order[i][j]>order[i][j+1])
                for(k=1;k<=j;k++)
                    for(l=j+1;l<=n;l++)
                    {
                        answer[order[i][k]][order[i][l]]='0';
                        answer[order[i][l]][order[i][k]]='1';
                    }
    for(i=1;i<=n;i++)
        answer[name[i]][name[i]]='B';
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << answer[name[i]][name[j]];
        cout << endl;
    }
    return 0;
}