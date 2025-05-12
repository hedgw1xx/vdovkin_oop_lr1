#ifndef VDOVKIN_LR1_VECTOR_CPP
#define VDOVKIN_LR1_VECTOR_CPP

#include "vdovkin_LR1_vector.hpp"

void loadStudentsFromFile(vector<Student> &students, const string &filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Unable to open file." << endl;
    return;
  }
  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    string fullName, surname, name;
    int id, age, grade;

    getline(ss, fullName, ',');
    stringstream nameStream(fullName);
    getline(nameStream, surname, ' ');
    getline(nameStream, name);

    ss >> id;
    ss.ignore();
    ss >> age;
    ss.ignore();

    Student student(surname, name, id, age);
    while (ss >> grade) {
      student.grades.push_back(grade);
      if (ss.peek() == ',')
        ss.ignore();
    }
    students.push_back(student);
  }
  file.close();
}

void displayVector(const vector<Student> &students) {
  for (const auto &student : students) {
    student.print();
  }
}

void addStudentToVector(vector<Student> &students, const Student &newStudent) {
  vector<Student> oldState = students; // Сохраняем старое состояние
  students.push_back(newStudent);
  if (diffEnabled) {
    printDiff(oldState, students, "vector");
  }
}

void sortStudentsByThirdGrade(vector<Student> &students) {
  vector<Student> oldState = students; // Сохраняем старое состояние
  sort(students.begin(), students.end(),
       [](const Student &a, const Student &b) {
         if (a.grades.size() >= 3 && b.grades.size() >= 3) {
           return a.grades[2] < b.grades[2];
         }
         return false;
       });
  if (diffEnabled) {
    printDiff(oldState, students, "vector");
  } else {
    cout << "Vector sorted by third grade:" << endl;
    displayVector(students);
  }
}

#endif // VDOVKIN_LR1_VECTOR_CPP
