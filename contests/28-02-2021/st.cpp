#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    
      
    node(int var)
    {
        data=var;
        next=NULL;
    }
};

void insertAtTail(node* &head,int var)
{
    node* n=new node(var);
    if(head==NULL)
    {
        head=n;
        return;
    }
    
    node* ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    
    ptr->next=n;
}

void insertAtpos (node* &head,int v,int p)
{
    node* ptr=head;
    node *prev=NULL;
    int cnt=1;
    while(ptr)
    {
         if (cnt ==p)
        {
            node *t = new node(v);
            t->next = ptr;
            if (prev)
                prev->next = t;
            else
            {
                head = t;
            }
            cout <<v << " successfully added\n";
            return;
        }
        cnt++;
        prev = ptr;
        ptr = ptr->next;
    }
     if (cnt == p)
    {
        node *t = new node(v);
        if (prev)
            prev->next = t;
        else
        {
            head = t;
        }
        t->next = NULL;
        cout << v << " successfully added\n";
        return;
    }
    cout << "pos out of range\n";
}

void display(node* head)
{
    node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"-->";
        ptr=ptr->next;
    }
    cout<<"END";
    cout<<endl;
}
int main()
{
     #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
    cout<<"Name:- VIKASH Tiwari\n";
    cout<<"Scholar No. 191114256\n";
    
    cout<<"\n**INSERTION AT SPECIFIC POSITION IN nextED LIST**\n\n";

    
    node* head=NULL;
    insertAtTail(head,22);
    insertAtTail(head,10);
    insertAtTail(head,31);
    insertAtTail(head,72);
    insertAtTail(head,61);
    cout<<"Original nexted list\n\n";
    display(head);
    
    cout<<"\n\n";
    
    int t,pos;
    cin>>t>>pos;
    
    cout<<"On inserting "<<t<< " at "<<pos<<"th position\n\n\n";
    
    insertAtpos(head,t,pos);
    
    display(head);
    
    return 0;
}