#include <functional>
#include <iostream>

int main() {
    int x = 1;

    std::function<void()> lambda1 = [=]() {
        std::cout << x << std::endl;
    };
    std::function<void()> lambda2 = [&]() {
        std::cout << x << std::endl;
    };

    x = 2;
    lambda1();    //Prints 1 since that was the value of x when it was captured and x was captured by value with [=]
    lambda2();    //Prints 2 since that's the current value of x and x was captured by reference with [&]

    std::function<void()> lambda3 = []() {}, lambda4 = []() {};    //I prefer to initialize these since calling an uninitialized lambda is undefined behavior.
                                                                 //[](){} is the empty lambda.

    {
        int y = 3;    //y will be deleted from the memory at the end of this scope
        lambda3 = [=]() {
            std::cout << y << std::endl;
        };
        lambda4 = [&]() {
            std::cout << y << std::endl;
        };
    }

    lambda3();    //Prints 3, since that's the value y had when it was captured

    lambda4();    //Causes the program to crash, since y was captured by reference and y doesn't exist anymore.
                  //This is a bit like if you had a pointer to y which now points nowhere because y has been deleted from the memory.
                  //This is why you should be careful when capturing by reference.

    return 0;
}