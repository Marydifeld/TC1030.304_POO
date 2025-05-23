#ifndef FRUTERO_H
#define FRUTERO_H
#include<string> 

using namespace std;

class Frutero{
    private:
        string color; 

    public:
        Frutero();
        Frutero(string);
        string getColor();
        void setColor(string);
        virtual void ShowFruit() = 0;
        
};
#endif /*FRUTERO_H*/