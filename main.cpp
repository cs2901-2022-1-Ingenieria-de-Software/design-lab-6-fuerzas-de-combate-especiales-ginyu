#include "sistema.h"


Sistema *Sistema::instance = 0;

int main(){
    Sistema* example = Sistema::getInstance();

    LightCommand* t1 = example->getLightCommand();
    
    t1->turnOn("red");
    
    Light light = t1->getLuz("red");
    cout << light.isOn();
}