#ifndef VDOVKIN_LR1_STACK_CPP
#define VDOVKIN_LR1_STACK_CPP

#include "vdovkin_LR1_stack.hpp"

void fillStackFromVectorReverse(const vector<Student> &students,
                                stack<Student> &stk) {
  for (auto it = students.rbegin(); it != students.rend(); ++it) {
    stk.push(*it);
  }
}

void displayStack(const stack<Student> &stk) {
  auto temp = stk;
  while (!temp.empty()) {
    temp.top().print();
    temp.pop();
  }
}

void extractUntilId(stack<Student> &stk, int targetId) {
  while (!stk.empty()) {
    Student s = stk.top();
    stk.pop();
    s.print();
    if (s.id == targetId) {
      break;
    }
  }
}

#endif // VDOVKIN_LR1_STACK_CPP
