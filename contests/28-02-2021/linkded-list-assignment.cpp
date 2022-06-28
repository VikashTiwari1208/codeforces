#include <bits/stdc++.h>
using namespace std;
#define int long long

class Student
{
public:
    string name;
    int id;
    Student *link;
    Student() {}
    Student(string n, int i)
    {
        name = n;
        id = i;
        link = NULL;
    }
};

class LinkedList
{
public:
    Student *head;

    LinkedList()
    {
        this->head = NULL;
    }
    void InsertAtBeg(Student);
    void InsertAtPos(int, Student);
    void deleteStudent(Student);
    void deleteAtLast();
    void Print();
    void update(int k);
};
Student *RevUtil(Student *temp, Student *&HeadOfReverseList)
{
    if (temp->link == NULL)
    {
        HeadOfReverseList = temp;
        return temp;
    }
    Student *LastofReverse = RevUtil(temp->link, HeadOfReverseList);
    temp->link = NULL;
    LastofReverse->link = temp;
    return temp;
}
void LinkedList::InsertAtBeg(Student t)
{
    Student *temp = new Student();
    temp->name = t.name;
    temp->id = t.id;
    temp->link = head;
    head = temp;
}
void LinkedList::InsertAtPos(int pos, Student s)
{
    int cnt = 1;
    Student *temp = head, *prev = NULL;
    while (temp)
    {
        if (cnt == pos)
        {
            Student *t = new Student(s.name, s.id);
            t->link = temp;
            if (prev)
                prev->link = t;
            else
            {
                head = t;
            }
            cout << s.name << " successfully added\n";
            return;
        }
        cnt++;
        prev = temp;
        temp = temp->link;
    }
    if (cnt == pos)
    {
        Student *t = new Student(s.name, s.id);
        if (prev)
            prev->link = t;
        else
        {
            head = t;
        }
        t->link = NULL;
        cout << s.name << " successfully added\n";
        return;
    }
    cout << "pos out of range\n";
}
void LinkedList::deleteStudent(Student s)
{
    cout << head->name << " " << endl;
    Student *temp = head;
    Student *prev = NULL;
    if (temp != NULL && temp->name == s.name)
    {
        head = temp->link;
    }
    else
    {
        while (temp != NULL && temp->name != s.name)
        {
            prev = temp;
            temp = temp->link;
        }
        if (temp == NULL)
        {
            cout << "NO STUDENT FOUND" << endl;
        }
        else
        {
            prev->link = temp->link;
        }
    }
}
void LinkedList::update(int k)
{
    Student *temp=head;
    while(temp)
    {
        temp->id=k;
        temp=temp->link;
    }
}
void LinkedList::deleteAtLast()
{
    Student *temp = head;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = NULL;
}
void LinkedList::Print()
{
    Student *temp = head;
    while (temp)
    {
        cout << temp->name << " " << temp->id << "--->";
        temp = temp->link;
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "VIKASH TIWARI 191114256 DS LAB ASSIGNMENT 6 " << endl;
    LinkedList *LL = new LinkedList(); //creating a linked list which contains studenets data like name marks ;
    Student s1("a", 12), s2("b", 67), s3("c", 89), s4("d", 22);
    //insering students at begining
    LL->InsertAtBeg(s1);
    LL->InsertAtBeg(s2);
    LL->InsertAtBeg(s3);
    LL->InsertAtBeg(s4);
    cout << "THE CURRENT LINKED LIST IS :: " << endl;
    LL->Print();
    cout << endl;
    Student s5("e", 65);
    LL->InsertAtPos(5, s5); // insering the node at the last or we can say at the particular location
    cout << "THE CURRENT LINKED LIST IS :: " << endl;
    LL->Print();
    cout << endl;
    LL->deleteStudent(s5); //deleting the student at position 5
    cout << "THE CURRENT LINKED LIST IS :: " << endl;
    LL->Print();
    cout << endl;
    LL->deleteAtLast(); //deletitng the linked list at last
    cout << "THE CURRENT LINKED LIST IS :: " << endl;
    LL->Print();
    cout<<endl;
    LL->update(5);
    LL->Print();
    return 0;
}