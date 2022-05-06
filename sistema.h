#ifndef SISTEMA
#define SISTEMA

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Light{
  
  public:
    friend class LightCommand;
    
    Light() = default;
    Light(string _id) : id(_id){}

    float getLuminosidad(){return luminosidad;}
    
    string getId(){return id;}
        
    bool isOn(){return turned_on;}
    
  private:
    float luminosidad = 0.f;
    bool turned_on = 0;
    string id;
};



class LightCommand {
  private:
    unordered_map<string, Light> luces;

  
  public:
    LightCommand(){
        luces["red"] = Light("red");
        luces["orange"] = Light("orange");
        luces["green"] = Light("green");
        luces["stop"] = Light("stop");    
    };
    
    void setLightLuminosity(string idLight, float l){
      luces[idLight].luminosidad = l;
    }
  
    void turnOn(string idLight){
      luces[idLight].turned_on = 1;
    }
  
    void turnOff(string idLight){
      luces[idLight].turned_on = 0;
    }

    Light getLuz(string nombre){
        return luces[nombre];
    }
};



class Sistema{
  private:
    static Sistema* instance;
    LightCommand* command;
      
    Sistema(){
      command = new LightCommand();
    }
    
  public:
    static Sistema* getInstance(){
      if (instance == nullptr)
        instance = new Sistema();
      return instance;
    }
  
    LightCommand* getLightCommand(){ return command;}
    
};

#endif