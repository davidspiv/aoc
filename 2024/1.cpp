#include <limits.h>

#include <fstream>
#include <iostream>

using namespace std;

template <typename T>
void print(T output, bool carriageReturn = 1) {
  if (carriageReturn) {
    std::cout << output << std::endl;
    return;
  }

  std::cout << output << std::flush;
}

template <typename T>
bool openFile(T& fileStream, const std::string& fileName) {
  fileStream.open(fileName);
  if (!fileStream) {
    return false;
  }

  return true;
}

int main() {
  int cout = 0;
  ifstream ifstream;
  openFile(ifstream, "./2024/1.dat");

  int numArr1[1001] = {3, 4, 2, 1, 3, 3};
  int numArr2[1001] = {4, 3, 5, 3, 9, 3};

  string line;
  int lineCout = 0;
  while (ifstream >> line) {
    if (lineCout % 2) {
      numArr1[(lineCout / 2)] = stoi(line);
    } else {
      numArr2[(lineCout / 2)] = stoi(line);
    }
    lineCout++;
  }

  for (size_t j = 0; j < (sizeof(numArr1) / sizeof(numArr1[0])); j++) {
    int smallNum1 = INT_MAX;
    int smallNum2 = INT_MAX;

    for (size_t i = 0; i < (sizeof(numArr1) / sizeof(numArr1[0])); i++) {
      if (numArr1[i] >= 0 && smallNum1 > numArr1[i]) {
        smallNum1 = numArr1[i];
      }

      if (numArr2[i] >= 0 && smallNum2 > numArr2[i]) {
        smallNum2 = numArr2[i];
      }
    }

    for (size_t i = 0; i < (sizeof(numArr1) / sizeof(numArr1[0])); i++) {
      if (numArr1[i] >= 0 && numArr1[i] == smallNum1) {
        numArr1[i] = -1;
        break;
      }
    }

    for (size_t i = 0; i < (sizeof(numArr1) / sizeof(numArr1[0])); i++) {
      if (numArr2[i] >= 0 && numArr2[i] == smallNum2) {
        numArr2[i] = -1;
        break;
      }
    }
    cout += abs(smallNum1 - smallNum2);
  }
  print(cout);

  return 0;
}
