#include <iostream>
#include <queue>

using namespace std;

// a looped one-way link list
struct Kid
{
    int id;
    Kid *next;
    Kid(int id, Kid *next)
    {
        this->id = id;
        this->next = next;
    }
};

bool isOut(int n, int k)
{
    return (n % k == 0) || (n % 10 == k);
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    // if (k == 1)
    // {
    //     cout << n << endl;
    //     return 0;
    // }
    // Kid *head = new Kid(1, nullptr);
    // Kid *preKid = head;
    // for (int i = 2; i <= n; i++)
    // {
    //     Kid *kid = new Kid(i, nullptr);
    //     preKid->next = kid;
    //     preKid = kid;
    // }
    // preKid->next = head;

    // int cnt = 2, ans;
    // Kid *kid = head;
    // while (n > 1)
    // {
    //     if (isOut(cnt, k))
    //     {
    //         ans = kid->id;
    //         kid->next = kid->next->next;
    //         n--;
    //         cnt++;
    //     }
    //     cnt++;
    //     kid = kid->next;
    // }
    // cout << ans << endl;

    // using STL: queue
    int cnt = 1;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (q.size() > 1)
    {
        int num = q.front();
        q.pop();
        if (!isOut(cnt, k))
        {
            q.push(num);
        }
        cnt++;
    }

    cout << q.front() << endl;

    return 0;
}