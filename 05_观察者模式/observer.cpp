#include<iostream>
#include<list>
#include<string>
class ISubject;
class IObserver
{
public:
    IObserver(){}
    virtual void update(ISubject *s)=0;
    virtual ~IObserver(){}
};

class Observer1 : public IObserver
{
public:
    Observer1(){}
    virtual void update(ISubject *s)
    {
        std::cout<<"this is Observer 1"<<std::endl;
    }
    virtual ~Observer1(){}
};

class Observer2 : public IObserver
{
public:
    Observer2(){}
    virtual void update(ISubject *s)
    {
        std::cout<<"this is Observer 2"<<std::endl;
    }
    virtual ~Observer2(){}
};

class ISubject
{
public:
        ISubject(){}
        virtual ~ISubject(){}
        virtual void attach(IObserver *ob)=0;//注册
        virtual void dettach(IObserver *ob)=0;//注销
        virtual void changeState(std::string str)
        {
            m_str=str;
            Notify();
        }

protected:
    virtual void Notify()=0;//通知
    std::list<IObserver *> observerList;
    std::string m_str;
};

class Subject1 : public ISubject
{
public:
    Subject1(){}
    virtual ~Subject1(){}
    virtual void attach(IObserver *ob)
    {
        observerList.push_back(ob);
    }
    virtual void dettach(IObserver *ob)
    {
        observerList.remove(ob);
    }
protected:
    virtual void Notify()
    {
        for(auto iter=observerList.begin();iter!=observerList.end();iter++)
            {
                std::cout<<m_str<<" ";
                (*iter)->update(this);
            }
    }
};


int main()
{
    Subject1 *S=new Subject1();
    Observer1 *p1=new Observer1();
    Observer2 *p2=new Observer2();
    S->attach(p1);
    S->attach(p2);
    S->changeState("hello world");
    S->changeState("hello china");

    return 0;
}