#include "sistema.h"


Sistema *Sistema::instance = 0;

int main(){
    Sistema* example = Sistema::getInstance();

    LightCommand* t1 = example->getLightCommand();
    
    t1->turnOn("red");
    t1->setLightLuminosity("red", 50);
    
    Light light = t1->getLuz("red");
    cout << light.isOn() << ": " << light.getLuminosidad();
}