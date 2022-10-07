#include <iostream>

void safe_printf(const char* s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw "invalid format string: missing arguments";
            }
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void safe_printf(const char* s, const T& value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                std::cout << value;
                safe_printf(s + 1, args...); // call even when *s == 0 to detect extra arguments
                return;
            }
        }
        std::cout << *s++;
    }
    throw "extra arguments provided to printf";
}
int main()
{
    try
    {
//      safe_printf("%, %\n", 1, 2); // ok
//      safe_printf("%, %\n", 1);    // ���� ���� ���� => ���� �߻�
        safe_printf("%, %\n", 1, 2, 3);// ���� ���� �ʰ� => ���� �߻�
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
    }
}