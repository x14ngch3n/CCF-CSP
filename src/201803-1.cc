#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int ins, last = 1, score = 0;
    int exit_flag = 0;
    while (cin >> ins)
    {
        switch (ins)
        {
        case 0:
            exit_flag = 1;
            break;

        case 1:
            last = 1;
            score += last;
            break;

        case 2:
            last = (last == 1) ? 2 : last + 2;
            score += last;
            break;

        default:
            break;
        }
        if (exit_flag)
        {
            break;
        }
    }

    cout << score << endl;

    return 0;
}