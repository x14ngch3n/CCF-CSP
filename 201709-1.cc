#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int extra = 0;
    for (int i = 0; i <= (n / 30); i++)
    {
        for (int j = 0; j <= (n / 50); j++)
        {
            if (3 * i + 5 * j <= (n / 10))
            {
                extra = max(i + 2 * j, extra);
            }
        }
    }
    int ans = extra + (n / 10);
    cout << ans << endl;
    return 0;
}