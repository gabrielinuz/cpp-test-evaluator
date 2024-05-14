:: Compilo código objeto
g++ -Wall -std=c++14 -c Car.cpp 
g++ -Wall -std=c++14 -c test_car.cpp


:: Compilo el Binario
g++ -Wall -std=c++14 Car.o test_car.o -o test_car.exe 

:: Limpio los códigos objeto
DEL .\*.o

::ejecutar:
test_car.exe