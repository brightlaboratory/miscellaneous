#include <string>
#include <iostream>
using namespace std;

void generatePermutations(string before, string str);
bool isValidWord(string str);
bool isVowel(char c);

int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Please enter a valid string" << endl;
    return 0;
  }

 string word = argv[1];
 string before = "";
 generatePermutations(before, word);
 return 0;
}

void generatePermutations(string before, string str) {
  if (str.length() == 0) {
    return;
  }

  if (str.length() == 1) {
    string newStr = before + str;

    if (isValidWord(newStr)) {
      cout << newStr << endl;
    }

    return;
  }

  for (int i = 0; i < str.length(); i++) {
    string prefix = "";
    if (i > 0) {
      prefix = str.substr(0, i);
    }

    string suffix = "";
    if (i < str.length()-1) {
      suffix = str.substr(i+1, str.length()-i-1);
    }

    string substr = prefix + suffix;
    string newBefore = before + str.at(i);
    generatePermutations(newBefore, substr);
  }

}

bool isValidWord(string str) {

  // Check if three consecutive letters are consonants. If they are, return that it's not a valid word.
  // Check if three consecutive letters are vowels. If they are, return that it's not a valid word.
  bool valid = true;
  for (int i = 0; i < str.length() - 2; i++) {
    if (isVowel(str.at(i)) && isVowel(str.at(i+1)) && isVowel(str.at(i+2))) {
       return false;
    }

    if (!isVowel(str.at(i)) && !isVowel(str.at(i+1)) && !isVowel(str.at(i+2))) {
       return false;
    }
  }

  return valid;
}

bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
     return true;
  } else {
     return false;
  }

}
