#ifndef VDOVKIN_LR1_STACK_H
#define VDOVKIN_LR1_STACK_H

#include "vdovkin_LR1_structure_STL_def.hpp"

inline void fillStackFromVectorReverse(const vector<Student> &students,
                                       stack<Student> &stk);
inline void displayStack(const stack<Student> &stk);
inline void extractUntilId(stack<Student> &stk, int targetId);

#endif // VDOVKIN_LR1_STACK_H
