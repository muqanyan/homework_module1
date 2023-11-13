#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int executeCommand(const vector<string>& tokens)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        cerr << "Error creating child process" << endl;
        return -1;
    }
    else if (pid == 0)
    {
        vector<char*> args(tokens.size() + 1);
        for (size_t i = 0; i < tokens.size(); ++i)
        {
            args[i] = const_cast<char*>(tokens[i].c_str());
        }
        args[tokens.size()] = nullptr;

        execvp(args[0], args.data());

        cerr << "Error executing command: " << tokens[0] << endl;
        exit(EXIT_FAILURE);
    } else {

        int status;
        waitpid(pid, &status, 0);


        return WIFEXITED(status) ? WEXITSTATUS(status) : -1;
    }
}


