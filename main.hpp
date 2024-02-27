#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int NUMCOURSE = 2;
struct Student
{
    int id;
    string name;
    int score[NUMCOURSE];
    double sum;
    double avg;
    struct Student *next;
};
#define struct Student Student;
// typedef struct Student Student;

Student *makeStudent(int N);
void printStudent(Student *head);
int getLength(Student *head);
Student *sortStudent(Student *head, int asc);

Student *makeStudent(int N)
{
    ifstream ifs;
    ifs.open("students.txt");
    if (!ifs) {
        cerr << "File Error\n";
        exit(0);
    }

    Student *tmp, *prev, *head;
    for (int i = 0; i < N; i++) {
        tmp = new Student;
        ifs >> tmp->id >> tmp->name >> tmp->score[0] >> tmp->score[1];
        tmp->sum = tmp->score[0] + tmp->score[1];
        tmp->avg = tmp->sum / (double)NUMCOURSE;
        tmp->next = NULL;
        if (i == 0) {
            head = tmp;
        } else {
            prev->next = tmp;
        }
        prev = tmp;
    }

    return head;
}
void printStudent(Student *head)
{
    Student *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->id << "\t";
        cout << ptr->name << "\t";
        cout << ptr->score[0] << "\t";
        cout << ptr->score[1] << "\t";
        cout << ptr->sum << "\t";
        cout << ptr->avg << "\n";
        ptr = ptr->next;
    }
    cout << endl;
}
int getLength(Student *head)
{
    Student *tmp = head;
    int cnt = 0;

    while(tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }

    return cnt;
}
Student *sortStudent(Student *head, int asc)
{
    Student *ptr, *prev, *tmp, *after;
    bool swap;

    do {
        swap = false;
        ptr = head;
        prev = NULL;

        while (ptr != NULL && ptr->next != NULL) {
            if (ptr->sum > ptr->next->sum) {
                after = ptr->next;
                ptr->next = after->next;
                after->next = ptr;

                if (prev != NULL) {
                    prev->next = after;
                }
                tmp = after;
                if (prev == NULL)
                    head = tmp;
                swap = true;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    } while (swap);

    return head;
}
