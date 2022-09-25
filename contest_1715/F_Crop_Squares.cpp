#include<bits/stdc++.h>
using namespace std;
// struct for event request ;
struct EventRequest{
char Eventtype;
int retryCount;
 EventRequest()
 {
  this->Eventtype='*';
    this->retryCount=-1;
 }
 EventRequest(char a,int b)
 {
    this->Eventtype=a;
    this->retryCount=b;
 }
};
// struct for eventstatus
struct EventStatus{
 char EventType;
 char StatusType;
 int RetryCount;
 EventStatus()
 {
    this->EventType='*';
    this->StatusType='*';
    this->RetryCount=-1;
 }
 EventStatus(char a,char b,int c)
 {
    this->EventType=a;
    this->StatusType=b;
    this->RetryCount=c;
 }
};
// class for event here i have combined two ttype of events in a single event
class event{
    public:
  EventStatus es;
  EventRequest er;
  event(EventRequest er,EventStatus es)
  {
   this->er=er;
   this->es=es;
  }
};

// this is our sample application
class Application
{
  queue<event>q;
  EventStatus last;
  public:
  Application()
  {
    last=EventStatus();
  }
  void push(EventRequest er,EventStatus es)
  {
    q.push(event(er,es));
  }
  void pop()
  {
    while(q.empty()==false)
    {
      auto x=q.front();
      q.pop();
      if(x.er.Eventtype=='*'&&x.er.retryCount==-1)
      {
        last=x.es;
        cout<<"EventStatus: S,";
        cout<<x.es.StatusType<<","<<x.es.RetryCount<<endl;
         if((x.es.EventType=='C'||x.es.EventType=='T')&&x.es.RetryCount<2)
         {
            x.es.RetryCount+=1;
            q.push(x);
         }
      }
     else if((x.es.EventType=='*'&&x.es.EventType=='*'&&x.es.RetryCount==-1))
      {
         
        if(last.StatusType=='C'||last.StatusType=='T')
        {
            cout<<"EventRequest: R"<<","<<x.es.RetryCount<<endl;
        }
        else
        {
             x.er.retryCount++;
            q.push(x);
        }
      }
    }
  }

};
int main()
{
 EventRequest default_er=EventRequest();
 EventStatus default_es=EventStatus();
 EventStatus es1('S','P',0);
 Application app=Application();
 app.push(default_er,es1);
 EventRequest er1('R',0);
 app.push(er1,default_es);
 EventStatus es2('S','M',0);
 app.push(default_er,es2);
 app.pop();

return 0;
}
/* time complexity of queue push operation is O(1) */
/* time complexity of queue pop is O(n) where n is the push operation */
/* Space Complexity is O(n) if n is the number of push operation */