#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
            << " is " << v1 + v2 << std::endl;

    std::cout << "Hello, World" << std::endl;

    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
            << " is " << v1 * v2 << std::endl;

    std::cout << "Enter two Numbers:";
    std::cout << std::endl;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;

    unsigned u1 = 42, u2 = 10;

    std::cout << u2 - u1 << std::endl;
    char c1[] = "WTFk";
    int i = *(int *)(&c1 + 1);
    return 0;
}
