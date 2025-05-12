#ifndef VDOVKIN_LR1_VECTOR_H
#define VDOVKIN_LR1_VECTOR_H

#include "vdovkin_LR1_structure_STL_def.hpp"

inline void loadStudentsFromFile(vector<Student> &students,
                                 const string &filename);
inline void displayVector(const vector<Student> &students);
inline void addStudentToVector(vector<Student> &students,
                               const Student &newStudent);
inline void sortStudentsByThirdGrade(vector<Student> &students);

#endif // VDOVKIN_LR1_VECTOR_H
