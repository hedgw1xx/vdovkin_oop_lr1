#ifndef VDOVKIN_LR1_MAP_H
#define VDOVKIN_LR1_MAP_H

#include "vdovkin_LR1_structure_STL_def.hpp"

inline int countVowels(const string &str);
inline void fillMapFromVector(const vector<Student> &students,
                              map<int, Student> &studentMap);
inline void displayMap(const map<int, Student> &studentMap);
inline void findStudentByKey(const map<int, Student> &studentMap, int targetId);

#endif // VDOVKIN_LR1_MAP_H
