#ifndef VDOVKIN_LR1_DEQUE_CPP
#define VDOVKIN_LR1_DEQUE_CPP

#include "vdovkin_LR1_deque.hpp"

void transferToListDeque(const list<Student> &studentList,
                         deque<Student> &studentDeque) {
  deque<Student> oldState = studentDeque; // Сохраняем старое состояние
  studentDeque.clear();                   // Очищаем перед переносом
  for (const auto &student : studentList) {
    if (student.age >= 18 && student.age <= 20) {
      studentDeque.push_front(student);
    } else {
      studentDeque.push_back(student);
    }
  }
  if (diffEnabled) {
    printDiff(oldState, studentDeque, "vector");
  }
}

void displayDeque(const deque<Student> &studentDeque) {
  for (const auto &student : studentDeque) {
    student.print();
  }
}

void printFirstAndLastThree(const deque<Student> &studentDeque) {
  auto tempFront = studentDeque;
  for (int i = 0; i < 3 && !tempFront.empty(); ++i) {
    Student s = tempFront.front();
    tempFront.pop_front();
    s.print();
  }
  auto tempBack = studentDeque;
  for (size_t i = 0; i < tempBack.size() - 3 && !tempBack.empty(); ++i) {
    tempBack.pop_front();
  }
  for (int i = 0; i < 3 && !tempBack.empty(); ++i) {
    Student s = tempBack.back();
    tempBack.pop_back();
    s.print();
  }
}

#endif // VDOVKIN_LR1_DEQUE_CPP
