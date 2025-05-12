#ifndef VDOVKIN_LR1_SET_CPP
#define VDOVKIN_LR1_SET_CPP

#include "vdovkin_LR1_set.hpp"

void createIdSet(const vector<Student> &students, set<int> &idSet) {
  for (const auto &student : students) {
    idSet.insert(student.id);
  }
}

void displaySet(const set<int> &idSet) {
  for (int id : idSet) {
    cout << id << " ";
  }
  cout << endl;
}

bool checkUniqueId(const vector<Student> &students) {
  set<int> idSet;
  for (const auto &student : students) {
    if (!idSet.insert(student.id).second) {
      return false;
    }
  }
  return true;
}

bool checkAge21(const vector<Student> &students) {
  for (const auto &student : students) {
    if (student.age == 21) {
      return true;
    }
  }
  return false;
}

#endif // VDOVKIN_LR1_SET_CPP
