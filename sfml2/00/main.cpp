/*
Игра Fizz-Buzz
Когда американские дети изучают числа, они играют в игру Fizz-Buzz:
- ведущий считает от 1 до 100
- когда называют число, кратное 3, дети должны сказать “Fizz”
- если названо число, кратное 5, дети должны сказать “Buzz”
- если число кратно и 3, и 5, надо сказать “FizzBuzz”
- иначе надо назвать число
Напишем программу, которая играет в FizzBuzz сама с собой!
*/

#include <iostream>

int main()
{
    for (int num = 1; num <= 30; num += 1)
    {
        if ((num % 3 == 0) && (num % 5 == 0))
        {
            std::cout << "FizzBuzz\n";
        }
        else if (num % 3 == 0)
        {
            std::cout << "Fizz\n";
        }
        else if (num % 5 == 0)
        {
            std::cout << "Buzz\n";
        }
        else
        {
            std::cout << num << std::endl;
        }
    }
}