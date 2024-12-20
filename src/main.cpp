#include <iostream>
#include <string>
using namespace std;

// TODO: DONT need this Right now
// // Declare an array of strings having valid commands (GLOBAL)
// string commands[] = {"echo", "type", "exit"};

// Helper Functions
// TRIM removes spaces from the beginning and end of the string
string trim(string input)
{
  // Remove spaces from the beginning
  while (input[0] == ' ')
  {
    input = input.substr(1);
  }
  // Remove spaces from the end
  while (input[input.size() - 1] == ' ')
  {
    input = input.substr(0, input.size() - 1);
  }
  return input;
}

// Bool functions to check Validity of the command
// checkECHO checks if the command is echo
bool checkECHO(string input)
{
  // Check if the input starts with "echo"
  if (input.substr(0, 4) == "echo")
  {
    return true;
  }
  return false;
}
// checkTYPE checks if the command is type
bool checkTYPE(string input)
{
  // Check if the input starts with "type"
  if (input.substr(0, 4) == "type")
  {
    return true;
  }
  return false;
}

// Extract and Execute the command
// ECHO extracts the string after "echo" and returns it
string ECHO(string input)
{
  string res = input.substr(5); // Remove "echo" from the input
  // Trim spaces from the beginning and end of the string
  res = trim(res);
  return res;
}
// TYPE extracts the string after "type" and returns it
void TYPE(string input)
{
  // Pass the whole input to the system command
  system(input.c_str());
}

int main()
{
  // Flush after every cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;
  // Main loop to take input and execute commands (REPL) // Read-Eval-Print-Loop
  while (true)
  {
    cout << "$ ";
    string input;
    getline(cin, input);
    // Trim spaces from the beginning and end of the string
    input = trim(input);
    // Check and Execute the commands
    if (input == "exit 0")
    {
      return 0;
    }
    else if (checkECHO(input))
    {
      string res = ECHO(input);
      cout << res << endl;
    }
    else if (checkTYPE(input))
    {
      TYPE(input);
    }
    else
    {
      cerr << input << ": command not found" << endl;
    }
  }

  return 0;
}