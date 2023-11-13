#include <iostream>
#include <cstdlib>
#include <cstdio>

void print_usage_and_exit()
{
    std::cerr << "Usage: ./mycat <filename>\n";
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        print_usage_and_exit();
    }

    const char *filename = argv[1];

    FILE *file = fopen(filename, "rb");
    if (!file) {
        std::cerr << "Error opening file\n";
        exit(EXIT_FAILURE);
    }

    char buffer[4096];

    std::cout << "Content of " << filename << ":\n";

    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        fwrite(buffer, 1, bytesRead, stdout);
    }

    if (ferror(file))
    {
        std::cerr << "Error reading file\n";
        exit(EXIT_FAILURE);
    }

    fclose(file);

    return EXIT_SUCCESS;
}

