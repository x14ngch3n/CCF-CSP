#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int red, yellow, green;
    cin >> red >> yellow >> green;
    int n;
    cin >> n;
    int light, time;
    int total_time = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> light >> time;
        switch (light)
        {
        // no lights
        case 0:
        case 1:
            total_time += time;
            break;

        case 2:
            total_time += time;
            total_time += red;
            break;

        default:
            break;
        }
    }

    cout << total_time << endl;

    return 0;
}