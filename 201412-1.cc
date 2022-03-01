#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<int, int> reader;
    map<int, int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        it = reader.find(tmp);
        if (it != reader.end())
        {
            cout << ++(it->second) << " ";
        }
        else
        {
            reader.insert(pair<int, int>(tmp, 1));
            cout << 1 << " ";
        }
    }
    return 0;
}
