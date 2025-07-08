//
//  main.cpp
//  dp_abstract_factory
//
//  Created by CodeBreaker on 02/07/25.
//
/*
 So create button and text box for differnt tyepes of OS's
 */
#include <iostream>
#include <string>
using namespace std;

class Button{
public:
    virtual ~Button(){cout<<"Button Deleted\n";};
    virtual void drawButton()=0;
};

class Box{
public:
    virtual ~Box(){cout<<"Box Deleted\n";};
    virtual void drawBox()=0;
};

class WinButton : public Button{
public:
    void drawButton() override{
        cout<<"Drawing Windows button\n";
    }
};

class WinTextBox : public Box{
public:
    void drawBox() override{
        cout<<"Drawing windows text box\n";
    }
};

class MacButton : public Button{
public:
    void drawButton() override{
        cout<<"Drawing Mac button\n";
    }
};

class MacTextBox : public Box{
public:
    void drawBox() override{
        cout<<"Drawing Mac text box\n";
    }
};

class UIFactory{
public:
    virtual ~UIFactory(){};
    virtual Box* CreateBox()=0;
    virtual Button* CreateButton()=0;
};

class WindowsFactory : public UIFactory{
public:
    Box * CreateBox() override{
        return new WinTextBox();
    }
    Button * CreateButton() override{
        return new WinButton();
    }
};

class MacFactory : public UIFactory{
public:
    Box * CreateBox() override{
        return new MacTextBox();
    }
    Button * CreateButton() override{
        return new MacButton();
    }
};

void RenderUI(UIFactory &uiFactory){
    Box *box = uiFactory.CreateBox();
    box->drawBox();
    
    Button *button = uiFactory.CreateButton();
    button->drawButton();
    
    delete box;
    delete button;
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Abstracct factory \n";
    WindowsFactory wf;
    RenderUI(wf);
    cout<<"--------------------\n";
    MacFactory mf;
    RenderUI(mf);
    cout<<"--------------------\n";
    return 0;
}
