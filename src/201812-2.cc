#include <iostream>

using namespace std;

int red, yellow, green;
int lights[3];
// the light sequence: red, green, yellow
void lightConvert(long long &light, long long &time, long long totaltime)
{
    totaltime += lights[light - 1];
    totaltime -= time;
    totaltime %= (red + yellow + green);
    if (light == 0)
    {
    }
    else if (totaltime <= red)
    {
        light = 1;
        time = red - totaltime;
    }
    else if (totaltime <= red + green)
    {
        light = 3;
        time = red + green - totaltime;
    }
    else if (totaltime <= red + green + yellow)
    {
        light = 2;
        time = red + green + yellow - totaltime;
    }
}

int main(int argc, char const *argv[])
{
    cin >> red >> yellow >> green;
    lights[0] = red;
    lights[1] = red + green + yellow;
    lights[2] = red + green;
    long long n;
    cin >> n;
    long long light, time;
    long long total_time = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> light >> time;
        lightConvert(light, time, total_time);
        switch (light)
        {
        // no lights and red light
        case 0:
        case 1:
            total_time += time;
            break;
        // yellow light
        case 2:
            total_time += time;
            total_time += red;
            break;
        // green light
        default:
            break;
        }
    }

    cout << total_time << endl;
    return 0;
}