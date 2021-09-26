#include "../etc/utils.h"


// product


class Adventurer{
    virtual string getType()=0;
};


class Warrior: public Adventurer{
public:
    string getType(){
        return "Warrior";
    }
};

class Archer:public Adventurer{
public:
    string getType(){
        return "Archer";
    }
};



int main(){
    

    return 0;
}