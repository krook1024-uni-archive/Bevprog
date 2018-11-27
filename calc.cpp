#include "std_lib_facilities.h"

class Token
{
public:
    char kind;
    double value;

    Token(char ch)
    {
        this->kind = ch;
        this->value = 0;
    }

    Token(char ch, double val)
    {
        this->kind = ch;
        this->value = val;
    }
};

class Token_stream 
{
public:
    Token_stream()
    {
        this->full = false;
        this->buffer = 0;
    }

    Token get()
    {
        if(full)
        {
            this->full = false;
            return this->buffer;
        }

        char ch;
        cin >> ch;

        
    }

    void putback(Token t)
    {
        if(full) error("Putback() into a full buffer");
        this->buffer = t;
        this->full = true;
    }
    
private:
    bool full;
    Token buffer;
};

int main()
{
    try
    {        
        while(cin)
        {
            
        }

        return 0;
    }

    catch (...)
    {
        cout << "bad things happened..." << endl;
        return -1;
    }
}