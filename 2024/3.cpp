#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

template <typename T>
void print(T output, bool carriageReturn = 1) {
  if (carriageReturn) {
    cout << output << endl;
    return;
  }

  cout << output << flush;
}

template <typename T>
bool openFile(T& fileStream, const string& fileName) {
  fileStream.open(fileName);
  if (!fileStream) {
    return false;
  }

  return true;
}

int main() {
  ifstream ifstream;
  openFile(ifstream, "./2024/3.dat");
  string line;
  regex r("[1-9]+");
  smatch m;

  while (getline(ifstream, line)) {
    regex_search(line, m, r);
  }

  for (auto x : m) cout << x << " ";

  return 0;
}
