#include <iostream>

using namespace std;

struct Student {
    int id;
    Student *post, *next;
    Student(int id, Student* post, Student* next)
    {
        this->id = id;
        this->post = post;
    }
};

Student* findStudent(Student* stu, int n)
{
    while (stu != nullptr) {
        if (stu->id == n) {
            return stu;
        }
        stu = stu->next;
    }
    return nullptr;
}

void moveForwardNStep(Student* stu, int n)
{
    Student* dstStu = stu;
    while (n-- > 0) {
        dstStu = dstStu->next;
    }
    // remove stu
    stu->post->next = stu->next;
    stu->next->post = stu->post;
    if (dstStu->next == nullptr) {
        // append stu
        dstStu->next = stu;
        stu->post = dstStu;
        stu->next = nullptr;
    } else {
        // insert stu after dstStu
        stu->next = dstStu->next;
        dstStu->next->post = stu;
        dstStu->next = stu;
        stu->post = dstStu;
    }
}

void moveBackwardNStep(Student* stu, int n)
{
    Student* dstStu = stu;
    while (n-- > 0) {
        dstStu = dstStu->post;
    }
    // remove stu
    if (stu->next == nullptr) {
        stu->post->next = nullptr;
    } else {
        stu->post->next = stu->next;
        stu->next->post = stu->post;
    }
    // insert stu before dstStu
    stu->post = dstStu->post;
    dstStu->post->next = stu;
    dstStu->post = stu;
    stu->next = dstStu;
}

int main(int argc, char const* argv[])
{
    int n, m;
    cin >> n >> m;
    // initialize link list
    Student* head = new Student(0, nullptr, nullptr);
    Student* pre_stu = head;
    for (int i = 1; i <= n; i++) {
        Student* stu = new Student(i, pre_stu, nullptr);
        pre_stu->next = stu;
        pre_stu = stu;
    }
    // handle operations
    int operations[2];
    for (int i = 0; i < m; i++) {
        cin >> operations[0] >> operations[1];
        Student* stu = findStudent(head, operations[0]);
        if (operations[1] > 0) {
            moveForwardNStep(stu, operations[1]);
        } else if (operations[1] < 0) {
            moveBackwardNStep(stu, -operations[1]);
        }
    }

    while (head->next != nullptr) {
        cout << head->next->id << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}