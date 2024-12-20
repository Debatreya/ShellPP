#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;

// Helper Functions
// TRIM removes spaces from the beginning and end of the string
string trim(string input)
{
  // Remove spaces from the beginning
  while (!input.empty() && input[0] == ' ')
  {
    input = input.substr(1);
  }
  // Remove spaces from the end
  while (!input.empty() && input[input.size() - 1] == ' ')
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
// checkCD checks if the command is cd
bool checkCD(string input)
{
  if (input.substr(0, 2) == "cd")
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
// TYPE passes the whole input to the system command
void TYPE(string input)
{
  string command = input.substr(5); // Extract the argument after "type"
  command = trim(command);

  if (command == "echo" || command == "exit" || command == "type")
  {
    if (command == "exit")
      cout << "exit is a special shell builtin" << endl;
    else
      cout << command << " is a shell builtin" << endl;
  }
  else
  {
    int ret_code = system(input.c_str());
    if (ret_code == 127)
    {
      cerr << command << ": not found" << endl;
    }
  }
}

// RUN_EXTERNAL executes external programs with arguments
void RUN_EXTERNAL(const string &input)
{
  // Extract the command name (first word of the input)
  size_t space_pos = input.find(' ');
  string command = (space_pos == string::npos) ? input : input.substr(0, space_pos);

  // Redirect shell error messages to /dev/null
  string command_with_redirect = input + " 2>/dev/null";
  int ret_code = system(command_with_redirect.c_str());
  if (ret_code == 127)
  {
    cerr << command << ": not found" << endl;
  }
  else if (ret_code != 0)
  {
    // Is is my custom error message
    cerr << command << ": not found" << endl;
  }
}

// CD changes the current working directory
void CD(const string &input)
{
  string path = trim(input.substr(3)); // Extract the argument after "cd"
  if (chdir(path.c_str()) != 0)
  {
    cerr << "cd: " << path << ": No such file or directory" << endl;
  }
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
    else if (checkCD(input))
    {
      CD(input);
    }
    else
    {
      RUN_EXTERNAL(input);
    }
  }

  return 0;
}
