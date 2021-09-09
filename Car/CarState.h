#include "CarDataType.h"

class CarState{
    
public:
    CarState(){};
    virtual bool UpdateGear(CAR_GEAR mode){
        return true;
    } 
    virtual bool UpdateSpeed(int speed){
        return true;
    }
    virtual bool AvmOn(){
        return true;
    }
    virtual bool AvmOff(){
        return true;
    }
    virtual bool Enter(){
        return true;
    }
    virtual bool Exit(){
        return true;
    }
};