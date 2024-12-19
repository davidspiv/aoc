#include <fstream>
#include <iostream>
#include <string>

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
  int safeReports = 0;

  ifstream ifstream;
  openFile(ifstream, "./2024/2.dat");
  string line;

  while (getline(ifstream, line)) {
    int report[10];
    size_t levelCout = 0;
    string level = "";

    for (size_t i = 0; i < line.length(); i++) {
      if (line[i] != ' ') {
        level += line[i];
      } else {
        report[levelCout] = stoi(level);
        levelCout++;
        level = "";
      }
    }

    report[levelCout] = stoi(level);
    levelCout++;

    // for (size_t i = 0; i < levelCout; i++) {
    //   print(report[i]);
    // }

    bool checkOne = 1;
    bool checkTwo = 1;

    for (size_t i = 1; i < levelCout; i++) {
      int difference = report[i] - report[i - 1];

      if (-difference < 1 || -difference > 3) {
        checkOne = 0;
      }

      if (difference < 1 || difference > 3) {
        checkTwo = 0;
      }

      if (!checkOne && !checkTwo) {
        break;
      }
    }

    safeReports += checkOne || checkTwo;
  }
  print(safeReports);
  // print("RESULT: " + to_string(safeReports == 502));

  return 0;
}
