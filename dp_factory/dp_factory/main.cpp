//
//  main.cpp
//  dp_factory
//
//  Created by CodeBreaker on 30/06/25.
//
/*
 Here is your code with added comments explaining what each part does and what it achieves:

 ### What this code achieves:
 1. **Encapsulation of Document Creation**: The `DocumentFactory` class encapsulates the logic for creating different types of documents, adhering to the Factory Design Pattern.
 2. **Polymorphism**: The `Document` base class allows handling different document types (`PDFDoc`, `WordDoc`, `TextDoc`) through a common interface.
 3. **Memory Management**: The `DocumentProcessor` class ensures proper cleanup of dynamically allocated memory to avoid memory leaks.
 4. **Extensibility**: New document types can be added easily by extending the `Document` class and updating the factory logic.
 */
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

class DocumentFactory{
public:
    Document *createDocument(const string &type){
        if(type.compare("pdf")==0){
            return new PDFDoc();
        } else if(type.compare("word")==0){
            return new WordDoc();
        } else if(type.compare("text")==0){
            return new TextDoc();
        }
        return nullptr;
    }
};
class DocumentProcessor{
private:
    Document *documnet;
public:
    DocumentProcessor():documnet(nullptr){}
    ~DocumentProcessor(){
        delete documnet;
    }
    void openDoc(string type){
        DocumentFactory factory;
        if(documnet){
            cout<<"Previous doc cleaned !!\n";
            delete documnet;
        }
        documnet = factory.createDocument(type);
        if(documnet){
            documnet->open();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Document processor understanding factor design pattern!\n";
    DocumentProcessor docProcess;
    cout<<"----------------------\n";
    docProcess.openDoc("pdf");
    cout<<"----------------------\n";
    docProcess.openDoc("text");
    cout<<"----------------------\n";
    docProcess.openDoc("word");
    cout<<"----------------------\n";
    return 0;
}
