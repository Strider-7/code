#include <bits/stdc++.h>

using namespace std;
#define MAX 501

// wrong probably
int getId(int M[MAX][MAX], int n)
{
    int c = 0;
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);
    while (s.size() > 1)
    {
        c++;

        int x = s.top();

        s.pop();

        int y = s.top();

        cout << x << " " << y << endl;

        s.pop();

        if (x != y)
        {
            if (M[x][y] == 0)
                s.push(x);
            else
                s.push(y);
            if (M[y][x] == 0)
                s.push(y);
            else
                s.push(x);
        }
        else
            s.push(x);
    }

    // cout << c << endl;

    return s.top();
}

int main()
{
    int M[MAX][MAX]{};
    M[0][1] = 1;
    M[1][0] = 1;
    cout << getId(M, 2) << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }

    return 0;
}