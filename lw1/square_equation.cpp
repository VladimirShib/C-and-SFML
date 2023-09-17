#include <cstdio>
#include <cmath>

int main()
{
    std::puts("Please, enter a, b and c for `ax^2+bx+c=0`:");

    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);
    //std::printf("%f %f %f", a, b, c);

    float D = b * b - 4 * a * c;
    //std::printf("%f", D);
    if (D < 0)
    {
        std::printf("No solutions");
    }
    else if (D == 0)
    {
        float x1 = (-b / (2 * a));
        std::printf("Solution: x = %f\n", x1);
    }
    else
    {
        float x1 = (-b - std::sqrt(D)) / (2 * a);
        float x2 = (-b + std::sqrt(D)) / (2 * a);
        std::printf("Solution: x1 = %f, x2 = %f\n", x1, x2);
    }
}