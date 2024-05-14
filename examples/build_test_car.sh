#!/bin/bash
## Compilo código objeto
g++ -Wall -std=c++14 -c ./Car.cpp 
g++ -Wall -std=c++14 -c test_car.cpp


# ## Compilo el Binario
g++ -Wall -std=c++14 Car.o test_car.o -o test_car.bin 

## Limpio los códigos objeto
rm ./*.o

# ## Permisos de Ejecución para el binario
chmod +x test_car.bin

#ejecutar:
./test_car.bin