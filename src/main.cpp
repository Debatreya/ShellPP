#include <iostream>
#include <string>
using namespace std;

bool checkECHO(string input){
  if(input.substr(0, 4) == "echo"){
    return true;
  }
  return false;
}

string ECHO(string input){
  string res = input.substr(5);
  return res;
}

int main() {
  // Flush after every cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;

  while (true) {
    cout << "$ ";
    string input;
    getline(cin, input);
    if (input == "exit 0") {
      return 0;
    } else if(checkECHO(input)){
      string res = ECHO(input);
      cout << res << endl;
    }else {
      cerr << input << ": command not found" << endl;
    }
  }

  return 0;
}
