#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

#include "shell_commands.h"

using namespace std;

int main()
{
    string input;
    vector<string> tokens;
    int exitCode;

    while (true)
    {
        cout << "myShell> ";
        getline(cin, input);

        "exit";
        if (input == "exit")
       	{
            cout << "exit" << endl;
            break;
        }
 
        istringstream iss(input);
        string token;
        tokens.clear();
        while (iss >> token)
       	{
            tokens.push_back(token);
        }
        
        if (!tokens.empty())
       	{    
            exitCode = executeCommand(tokens); 
            cout << "exit code: " << exitCode << endl;
        }
    }

    return 0;
}

