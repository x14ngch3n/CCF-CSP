#include <iostream>

using namespace std;

int ReLU(int n)
{
    return max(n, 0);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int scores[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i][0] >> scores[i][1];
    }
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        score += scores[i][0] * scores[i][1];
    }

    cout << ReLU(score) << endl;

    return 0;
}