#ifndef VDOVKIN_LR1_DEQUE_H
#define VDOVKIN_LR1_DEQUE_H

#include "vdovkin_LR1_structure_STL_def.hpp"

inline void transferToListDeque(const list<Student> &studentList,
                                deque<Student> &studentDeque);
inline void displayDeque(const deque<Student> &studentDeque);
inline void printFirstAndLastThree(const deque<Student> &studentDeque);

#endif // VDOVKIN_LR1_DEQUE_H
