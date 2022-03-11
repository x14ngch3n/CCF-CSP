#include <iostream>

using namespace std;

int monthsNormal[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int monthsRunyear[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isRunyear(int y)
{
    return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

int main(int argc, char const* argv[])
{
    int y, d;
    cin >> y >> d;
    int* months = isRunyear(y) ? monthsRunyear : monthsNormal;
    for (int i = 0; i < 12; i++) {
        if (d <= months[i]) {
            cout << i + 1 << endl;
            cout << d << endl;
            break;
        } else {
            d -= months[i];
        }
    }
    return 0;
}