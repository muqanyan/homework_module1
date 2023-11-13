#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char sourceFileName[100];
    char destinationFileName[100];
    off_t sourceOffset, destinationOffset;
    size_t bytesToCopy;
    char buffer[4096];

    std::cout << "Enter the name of the source file: ";
    std::cin >> sourceFileName;
    std::cout << "Enter the name of the destination file: ";
    std::cin >> destinationFileName;
    std::cout << "Enter the initial offset in the source file (in bytes): ";
    std::cin >> sourceOffset;
    std::cout << "Enter the initial offset in the destination file (in bytes): ";
    std::cin >> destinationOffset;
    std::cout << "Enter the number of bytes to copy: ";
    std::cin >> bytesToCopy;

    int sourceFile = open(sourceFileName, O_RDONLY);
    if (sourceFile == -1)
    {
        perror("Error opening source file");
        std::exit(EXIT_FAILURE);
    }

   
    if (lseek(sourceFile, sourceOffset, SEEK_SET) == -1)
    {
        perror("Error seeking in source file");
        close(sourceFile);
        std::exit(EXIT_FAILURE);
    }

    int destinationFile = open(destinationFileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (destinationFile == -1)
    {
        perror("Error opening destination file");
        close(sourceFile);
        std::exit(EXIT_FAILURE);
    }

    if (lseek(destinationFile, destinationOffset, SEEK_SET) == -1)
    {
        perror("Error seeking in destination file");
        close(sourceFile);
        close(destinationFile);
        std::exit(EXIT_FAILURE);
    }

        while (bytesToCopy > 0)
       	{
        ssize_t bytesRead = read(sourceFile, buffer, std::min(sizeof(buffer), bytesToCopy));
        if (bytesRead == -1) {
            perror("Error reading from source file");
            close(sourceFile);
            close(destinationFile);
            std::exit(EXIT_FAILURE);
        }

        if (bytesRead == 0)
       	{
            break;     
    	}

        ssize_t bytesWritten = write(destinationFile, buffer, bytesRead);
        if (bytesWritten == -1)
       	{
            perror("Error writing to destination file");
            close(sourceFile);
            close(destinationFile);
            std::exit(EXIT_FAILURE);
        }

        bytesToCopy -= bytesWritten;
    }

   
    close(sourceFile);
    close(destinationFile);

    std::cout << "Successfully copied " << bytesToCopy << " bytes from the source file to the destination file." << std::endl;

    return 0;
}

