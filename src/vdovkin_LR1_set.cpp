#ifndef VDOVKIN_LR1_SET_CPP
#define VDOVKIN_LR1_SET_CPP

#include "vdovkin_LR1_set.hpp"
#include "vdovkin_LR1_structure_STL_def.hpp"

void createIdSet(const vector<Student> &students, set<int> &idSet) {
  for (const auto &student : students) {
    idSet.insert(student.age);
  }
}

void displaySet(const set<int> &idSet) {
  for (int id : idSet) {
    cout << id << " ";
  }
  cout << endl;
}

bool checkUniqueAge(const vector<Student> &students) {
  set<int> idSet;
  if (idSet.size() == students.size()) {
    return false;
  }
  return true;
}

bool checkAge21(const set<int> &idSet) {
  if (idSet.count(21) > 0) {
    return true;
  }
  return false;
}

#endif // VDOVKIN_LR1_SET_CPP
