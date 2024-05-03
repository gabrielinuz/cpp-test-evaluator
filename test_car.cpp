#include <iostream>
#include <string>
#include <memory>
#include "TestEvaluator.hpp"

using namespace std;

auto te = make_unique<TestEvaluator>();

class Car
{
    private:
        /* data */
        int _gas;
    public:
        Car(/* args */)
        {
            _gas = 0;
        }
        ~Car(){};
        void setGas(int gas)
        {
            _gas = gas;
        }

        int getGas()
        {
            return _gas;
        }
};

void testCarHasFuel()//Test para evaluar la presencia de combustible.
{
    //Arrange
    auto car = make_unique<Car>();

    //Act
    car->setGas(2);
    int gas = car->getGas();

    //Assert
    te->evaluate("Test Car Has Fuel", gas > 0);
}

int main(int argc, char const *argv[])
{

    //Imprimir el título del Caso de Pruebas
    te->title("Car tests:");
    testCarHasFuel();

    te->summary();
    
    return 0;
}
