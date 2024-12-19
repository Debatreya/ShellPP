#include <iostream>
#include <string>
using namespace std;

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
    } else {
      cerr << input << ": command not found" << endl;
    }
  }

  return 0;
}
