//
//  main.cpp
//  dp_factory_method
//
//  Created by CodeBreaker on 01/07/25.
//

#include <iostream>
#include <string>
using namespace std;

class Document {
public:
    virtual ~Document(){ cout<<"Document Destructor..\n";}
    virtual void open() = 0;
};

class PDFDoc : public Document {
public:
    ~PDFDoc(){cout<<"pdf Destructor\n";}
    void open() override{
        cout<<"Pdf document opened\n";
    }
};

class WordDoc : public Document {
public:
    ~WordDoc(){cout<<"WordDoc Destructor\n";}
    void open() override{
        cout<<"Word document opened\n";
    }
};

class TextDoc : public Document {
public:
    ~TextDoc(){cout<<"TextDoc Destructor\n";}
    void open() override{
        cout<<"Text document opened\n";
    }
};

//Abstract method
class DocProcessor{
public:
    virtual ~DocProcessor(){
        cout<<"Docprocessor destroyed\n";
    }
    virtual Document *createDocument()=0;
    virtual void processDoc(){
        Document *doc = createDocument();
        if(doc){
            doc->open();
            delete doc;
        }
    }
};

class pdfFactory : public DocProcessor{
    Document * createDocument() override{
        return new PDFDoc();
    }
};

class wordFactory : public DocProcessor{
    Document * createDocument() override{
        return new WordDoc();
    }
};

class textFactory : public DocProcessor{
    Document * createDocument() override{
        return new TextDoc();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understading factory method pattern!\n";
    pdfFactory pdf;
    pdf.processDoc();
    cout<<"---------------------\n";
    textFactory text;
    text.processDoc();
    cout<<"----------------------\n";
    wordFactory word;
    word.processDoc();
    cout<<"---------------------\n";
    
    return 0;
}
