//
//  main.cpp
//  dp_decorator
//
//  Created by CodeBreaker on 04/07/25.
//

#include <iostream>
using namespace std;

//Component Interface
class INotifier{
public:
    virtual ~INotifier(){cout<<"Notfier interface delated..\n";}
    virtual void send(const string &msg)=0;
};

//Concrete Component
class Notifier : public INotifier{
    void send(const string &msg) override{
        cout<<"Message sent..."<<msg<<endl;
    }
};

//Decorator Base Class
class BaseDecorater : public INotifier{
//    INotifier *notifier;
    unique_ptr<INotifier> notifier;
public:
    ~BaseDecorater(){
        cout<<"Base decorater deleted \n";
//        delete notifier;
    }
//    BaseDecorater(INotifier *notif):notifier(notif){}
    BaseDecorater(unique_ptr<INotifier> notif) : notifier(std::move(notif)){}
    void send(const string &msg)override{
        notifier->send(msg);
    }
};


//Dcoraters
class SMSDecorater : public BaseDecorater{
public:
//    SMSDecorater(INotifier *notif): BaseDecorater(notif){};
    SMSDecorater(unique_ptr<INotifier> notif) : BaseDecorater(std::move(notif)){}
    void send(const string &msg)override{
        BaseDecorater::send(msg);
        cout<<"Sent vie SMS:"<<msg<<endl;
    }
};

class SlackDecorater : public BaseDecorater{
public:
//    SlackDecorater(INotifier *notif):BaseDecorater(notif){}
    SlackDecorater(unique_ptr<INotifier> notif) : BaseDecorater(std::move(notif)){}
    void send(const string &msg)override{
        BaseDecorater::send(msg);
        cout<<"Sent vie Slack:"<<msg<<endl;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding Decorater design pattern!\n";
    
    string alert = "Server is down!";
    unique_ptr<INotifier> notifier = make_unique<Notifier>();
    notifier->send(alert);
    cout<<"----------------------\n";
    //INotifier *smsNotifier = new SMSDecorater(new Notifier());//
    unique_ptr<INotifier> smsNotifier = make_unique<SMSDecorater>(std::move(notifier));
    smsNotifier->send(alert);
    cout<<"----------------------\n";
//    INotifier *fullNotifier = new SlackDecorater(new SMSDecorater(new Notifier()));
    unique_ptr<INotifier> fullNotifier = make_unique<SlackDecorater>(std::move(smsNotifier));
    fullNotifier->send(alert);
    
    cout<<"----------------------\n";
    
//    delete notifier;
//    delete smsNotifier;
//    delete fullNotifier;
//    
    return 0;
}
