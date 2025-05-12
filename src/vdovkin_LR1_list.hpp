#ifndef VDOVKIN_LR1_LIST_H
#define VDOVKIN_LR1_LIST_H

#include "vdovkin_LR1_structure_STL_def.hpp"

inline void copyVectorToList(const vector<Student> &students,
                             list<Student> &studentList);
inline void displayList(const list<Student> &studentList);
inline void removeStudentsWithIdMultipleOf11(list<Student> &studentList);
inline void insertStudentInMiddle(list<Student> &studentList,
                                  const Student &newStudent);

#endif // VDOVKIN_LR1_LIST_H
