#include <iostream>
#include <string>
#include <memory>
#include "TestEvaluator.hpp"

using namespace std;

//Función macro para realizar una simple aserción (ASSERT) y mostrar el resultado
#define ASSERT(test_expr) te->evaluate(#test_expr, test_expr)

int main() 
{
    auto te = make_unique<TestEvaluator>();

    //Imprimir el título del Caso de Pruebas
    te->title("Math operation tests:");

    // Realizar pruebas unitarias
    te->evaluate("2 + 2 == 4", 2 + 2 == 4);
    ASSERT(3 * 7 == 21);
    ASSERT(3 * 7 == 24);// Esta prueba fallará
    ASSERT(5 - 2 == 4); // Esta prueba fallará

    // Imprimir resumen de pruebas
    te->summary();

    return 0;
}
