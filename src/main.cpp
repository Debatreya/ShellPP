#include <iostream>
#include <string>
using namespace std;

int main() {
  // Flush after every cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;

  cout << "$ ";

  string input;
  getline(cin, input);
  if(false) {
    cout << "Goodbye!" << endl;
    return 0;
  }else{
    cerr << input << ": command not found" << endl;
  }
}
