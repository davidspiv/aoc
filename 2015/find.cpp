#include <iostream>
#include <string>

using namespace std;

const string test = "111112\\\"2111112\\\"21111";

string findAndDelete(string body, const string &key) {
  while (body.find(key) != string::npos) {
    body = body.substr(0, body.find(key)) +
           body.substr(body.find(key) + key.length(), string::npos);
  };
  return body;
}

int main() {
  cout << "before: " << test << endl;
  const string after = findAndDelete(test, "\\\"");
  cout << "after: " << after << endl;

  string line = "adsfkshdf";

  while (line[0] == ' ') {
    cout << "WHITESPACE" << endl;
    line = line.substr(1, string::npos);
  }

  while (line[line.length() - 1] == ' ') {
    cout << "WHITESPACE" << endl;
    line = line.substr(0, line.length() - 1);
  }
}
