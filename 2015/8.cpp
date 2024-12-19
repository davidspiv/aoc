#include <fstream>
#include <iostream>

using namespace std;

int goodChar = 0;

string findAndDelete(string body, const string &key, int sliceLen) {
  while (body.find(key) != string::npos) {
    body = body.substr(0, body.find(key)) +
           body.substr(body.find(key) + sliceLen, string::npos);
    goodChar++;
  };
  return body;
}

void getEscapeDifferenceTotal(string fileName) {
  ifstream file(fileName);
  string line;
  int count = 0;

  while (getline(file, line)) {
    cout << "ORIGINAL LINE:" << line << endl;
    const int beginningLength = line.length();

    line = line.substr(1, line.length() - 2);
    line = findAndDelete(line, "\\\\", 2);
    line = findAndDelete(line, "\\\"", 2);
    line = findAndDelete(line, "\\x", 4);
    count += beginningLength - line.length();
    cout << "FINAL LINE:" << line << endl << endl;
  }
  cout << "final count: " << count + goodChar << endl;
}

int main() { getEscapeDifferenceTotal("./2015/8.txt"); }
