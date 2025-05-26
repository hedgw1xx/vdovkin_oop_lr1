#ifndef VDOVKIN_LR1_SET_H
#define VDOVKIN_LR1_SET_H

#include "vdovkin_LR1_structure_STL_def.hpp"

inline void createIdSet(const vector<Student> &students, set<int> &idSet);
inline void displaySet(const set<int> &idSet);
inline bool checkUniqueAge(const vector<Student> &students);
inline bool checkAge21(const set<int> &idSet);

#endif // VDOVKIN_LR1_SET_H
