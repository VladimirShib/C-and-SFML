// FizzBuzz but with switch operator

#include <iostream>

int main()
{
    for (int num = 1; num <= 30; num++)
    {
        switch (num % 15)
        {
        case 0:
            std::cout << "FizzBuzz\n";
            break;
        case 5:
        case 10:
            std::cout << "Buzz\n";
            break;
        case 3:
        case 6:
        case 9:
        case 12:
            std::cout << "Fizz\n";
            break;
        default:
            std::cout << num << "\n";
        }
    }
}