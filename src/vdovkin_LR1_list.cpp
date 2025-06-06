#ifndef VDOVKIN_LR1_LIST_CPP
#define VDOVKIN_LR1_LIST_CPP

#include "vdovkin_LR1_list.hpp"

void copyVectorToList(const vector<Student> &students,
                      list<Student> &studentList) {
  studentList.assign(students.begin(), students.end());
}

void displayList(const list<Student> &studentList) {
  for (const auto &student : studentList) {
    student.print();
  }
}

void removeStudentsWithIdMultipleOf11(list<Student> &studentList) {
  list<Student> oldState = studentList; // Сохраняем старое состояние
  studentList.remove_if([](const Student &s) { return s.id % 11 == 0; });
  if (diffEnabled) {
    printDiff(oldState, studentList, "list");
  }
}

void insertStudentInMiddle(list<Student> &studentList,
                           const Student &newStudent) {
  list<Student> oldState = studentList; // Сохраняем старое состояние
  if (studentList.empty()) {
    studentList.push_back(newStudent);
  } else {
    auto it = studentList.begin();
    advance(it, studentList.size() / 2);
    studentList.insert(it, newStudent);
  }
  if (diffEnabled) {
    printDiff(oldState, studentList, "vector");
  }
}

#endif // VDOVKIN_LR1_LIST_CPP
