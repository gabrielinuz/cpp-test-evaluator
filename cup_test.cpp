#include <iostream>
#include <string>
#include <memory>
#include "TestEvaluator.hpp"

using namespace std;

auto te = make_unique<TestEvaluator>();

class Cup
{
    private:
        /* data */
        int _content;
    public:
        Cup(/* args */) : _content(0) {}
        ~Cup(){}
        int getContent()
        {
            return _content;
        }
        
        void refill(int content)
        {
            _content = content;
        }

};



void cupIsNotEmpty()
{
    //Arrange
    auto cup = make_unique<Cup>();

    //Act
    cup->refill(2);

    //Assert
    te->evaluate("Cup is not empty", cup->getContent() > 0);
} 

int main(int argc, char const *argv[])
{
    /* code */
    te->title("Cup test:");

    cupIsNotEmpty();

    te->summary();
    return 0;
}
