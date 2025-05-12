#ifndef VDOVKIN_LR1_SET_H
#define VDOVKIN_LR1_SET_H

#include "vdovkin_LR1_structure_STL_def.hpp"

inline void createIdSet(const vector<Student> &students, set<int> &idSet);
inline void displaySet(const set<int> &idSet);
inline bool checkUniqueId(const vector<Student> &students);
inline bool checkAge21(const vector<Student> &students);

#endif // VDOVKIN_LR1_SET_H
