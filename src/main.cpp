#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Helper function to trim spaces from the beginning and end of a string
string trim(const string &input)
{
    size_t first = input.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = input.find_last_not_of(' ');
    return input.substr(first, last - first + 1);
}

int main()
{
    cout << unitbuf; // Ensure output is flushed immediately

    while (true)
    {
        cout << "$ ";
        string input;
        getline(cin, input);

        // Trim the input
        input = trim(input);

        // Exit condition
        if (input == "exit 0")
        {
            return 0;
        }

        // Pass the input directly to the system's command-line interface
        if (!input.empty())
        {
            int ret_code = system(input.c_str());
            if (ret_code == 127)
            {
                cerr << input << ": not found" << endl;
            }
            else if (ret_code != 0)
            {
                cerr << "Error: Command failed with code " << ret_code << endl;
            }
        }
    }

    return 0;
}