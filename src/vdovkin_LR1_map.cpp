#ifndef VDOVKIN_LR1_MAP_CPP
#define VDOVKIN_LR1_MAP_CPP

#include "vdovkin_LR1_map.hpp"

int countVowels(const string &str) {
  string lowerStr = str;
  transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
  int count = 0;
  for (char c : lowerStr) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      count++;
  }
  return count;
}

void fillMapFromVector(const vector<Student> &students,
                       map<int, Student> &studentMap) {
  for (const auto &student : students) {
    int key = countVowels(student.name);
    studentMap.insert({key, student});
  }
}

void displayMap(const map<int, Student> &studentMap) {
  for (const auto &pair : studentMap) {
    cout << "Key: " << pair.first << " - ";
    pair.second.print();
  }
}

void findStudentByKey(const map<int, Student> &studentMap, int targetKey) {
  auto it = studentMap.find(targetKey);
  if (it != studentMap.end()) {
    it->second.print();
  } else {
    cout << "Student with key " << targetKey << " not found." << endl;
  }
}

#endif // VDOVKIN_LR1_MAP_CPP
