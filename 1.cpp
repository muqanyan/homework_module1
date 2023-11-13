#include <iostream>
#include <cstdlib>
#include <algorithm>

int main(int argc, char *argv[]) 
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <a> <b> <c>\n";
        return 1;
    }

    int a = std::atoi(argv[1]);
    int b = std::atoi(argv[2]);
    int c = std::atoi(argv[3]);

    int min, max;
  
    min = std::min({a, b, c});
    max = std::max({a, b, c});

    std::cout << "min-" << min << ", max-" << max << std::endl;

    return 0;
}

