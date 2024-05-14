#include <iostream>
#include <string>
#include <memory>
#include "Car.hpp"
#include "../TestEvaluator.hpp"

using namespace std;

auto te = make_unique<TestEvaluator>();

// class Car
// {
//     private:
//         /* data */
//         int _gas;
//         bool _lightStatus;
//     public:
//         Car(/* args */)
//         {
//             // _gas = 0;
//             setGas(0);
//             // _lightStatus = false;
//             setLightStatus(false);
//         }
//         ~Car(){};

//         void setGas(int gas)
//         {
//             _gas = gas + 3;
//         }

//         int getGas()
//         {
//             return _gas;
//         }

//         void setLightStatus(bool status)
//         {
//             _lightStatus = status;
//         }

//         bool getLightStatus()
//         {
//             return _lightStatus;
//         }

//         void turnOnLights()
//         {
//             _lightStatus = true;
//         }

//         void turnOffLights()
//         {
//             _lightStatus = false;
//         }
// };

void testCarHasFuel()//Test para evaluar la presencia de combustible.
{
    //Arrange
    auto car = make_unique<Car>();

    //Act
    car->setGas(2);
    int gas = car->getGas();

    //Assert
    te->evaluate("Car Has Fuel", gas > 0);
}

void testCarHasLightsOn()
{
    //Arrange
    auto car = make_unique<Car>();

    //Act
    car->turnOnLights();

    //Assert
    te->evaluate("Car Has Lights On", car->getLightStatus());  
}

void testCarHasLightsOff()
{
    //Arrange
    auto car = make_unique<Car>();

    //Act
    car->turnOffLights();
    bool isLightOff = !car->getLightStatus();

    //Assert
    te->evaluate("Car Has Lights Off", isLightOff);  
}

int main(int argc, char const *argv[])
{

    //Imprimir el título del Caso de Pruebas
    te->title("Car tests:");
    
    testCarHasFuel();

    testCarHasLightsOn();

    testCarHasLightsOff();

    te->summary();
    
    return 0;
}
