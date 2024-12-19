#include <fstream>
#include <iostream>

#include "../helpers/io.h"

using namespace std;

int main() {
  ifstream ifstream;
  int sum = 0;

  if (!openFile(ifstream, "./2023/1.dat")) {
    cout << "Input File did not open. Program terminating!!!" << endl;
    return 1;
  }

  string line;
  while (ifstream >> line) {
    string result = "";
    // if (line == "" || line == "\n") break;
    for (size_t i = 0; i < line.length(); i++) {
      if (isdigit(line[i])) {
        result += line[i];
      }
    }

    sum += stoi(result.substr(0, 1) + result.back());
  }
  ifstream.close();
  cout << "sum: " << sum << endl;
  return 0;
}
