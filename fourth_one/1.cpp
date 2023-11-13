#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream input("input.txt");
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input, line))
    {
        lines.push_back(line);
    }
    
    std::cout << "Number of lines in the file: " << lines.size() << std::endl;
  
    std::ofstream output("output.txt");
    std::for_each(lines.rbegin(), lines.rend(), [&output](const std::string &line) 
		    {
        output << line << std::endl;
    });

    return 0;
}

