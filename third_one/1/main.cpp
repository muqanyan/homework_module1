#include "ComplexNum.hpp"
#include <vector>
#include <algorithm>

int main()
{
    std::vector<ComplexNumber> complexNumbers = 
    {
        ComplexNumber(3.0, 4.0),
        ComplexNumber(1.0, -2.0),
        ComplexNumber(-2.0, 5.0),
    };
    
    std::sort(complexNumbers.begin(), complexNumbers.end(), [](const ComplexNumber& a, const ComplexNumber& b)
		    {
        return sqrt(a * a) < sqrt(b * b);
    });

    for (const auto& num : complexNumbers)
    {
        std::cout << num << std::endl;
    }

    return 0;
}

