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
  int numArr1[1001];
  int numArr2[1001];
  size_t arrSize = sizeof(numArr1) / sizeof(numArr1[0]);
  int similarityScore = 0;

  ifstream ifstream;
  openFile(ifstream, "./2024/1.dat");
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

  for (size_t i = 0; i < arrSize; i++) {
    int elementCout = 0;

    for (size_t j = 0; j < arrSize; j++) {
      if (numArr1[i] == numArr2[j]) {
        elementCout++;
      }
    }
    similarityScore += numArr1[i] * elementCout;
  }

  print(similarityScore);

  return 0;
}
