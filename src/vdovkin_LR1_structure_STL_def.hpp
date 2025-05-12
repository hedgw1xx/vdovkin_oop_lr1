#ifndef VDOVKIN_LR1_STRUCTURE_STL_DEF_H
#define VDOVKIN_LR1_STRUCTURE_STL_DEF_H

#include <algorithm>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Глобальный флаг для включения diff
extern bool diffEnabled;

struct Student {
  string surname;
  string name;
  int id;
  int age;
  vector<int> grades;

  Student(string s = "", string n = "", int i = 0, int a = 0,
          vector<int> g = vector<int>())
      : surname(s), name(n), id(i), age(a), grades(g) {}

  void print() const {
    cout << "Фамилия: " << surname << ", Имя: " << name << ", ID: " << id
         << ", Возраст: " << age << ", Оценки: ";
    for (int grade : grades)
      cout << grade << " ";
    cout << endl;
  }

  bool operator==(const Student &other) const {
    return surname == other.surname && name == other.name && id == other.id &&
           age == other.age && grades == other.grades;
  }

  bool operator!=(const Student &other) const { return !(*this == other); }
};

// Функция для вывода различий
template <typename Container>
void printDiff(const Container &oldState, const Container &newState,
               const string &containerName) {
  cout << "Изменения в " << containerName << ":\n";
  bool hasDiff = false;

  // Сравнение элементов
  auto oldIt = oldState.begin();
  auto newIt = newState.begin();
  size_t index = 0;

  while (oldIt != oldState.end() || newIt != newState.end()) {
    if (oldIt == oldState.end()) {
      cout << "+ Добавлен студент [" << index << "]: ";
      newIt->print();
      ++newIt;
      hasDiff = true;
    } else if (newIt == newState.end()) {
      cout << "- Удален студент [" << index << "]: ";
      oldIt->print();
      ++oldIt;
      hasDiff = true;
    } else if (*oldIt != *newIt) {
      cout << "~ Изменен студент [" << index << "]:\n";
      cout << "  Было: ";
      oldIt->print();
      cout << "  Стало: ";
      newIt->print();
      ++oldIt;
      ++newIt;
      hasDiff = true;
    } else {
      ++oldIt;
      ++newIt;
    }
    ++index;
  }

  if (!hasDiff) {
    cout << "Нет изменений.\n";
  }
  cout << endl;
}

inline void clearTerminal() {
#ifdef _WIN32
  system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix)
  system("clear");
#endif
}

inline bool UserInput(string input) {
  if (input.empty())
    return false;
  try {
    int number = stoi(input);
  } catch (...) {
    return false;
  }
  return true;
}

inline bool UserInputString(string input) {
  if (input.empty())
    return false;
  return true;
}

function<void()> inline EnterNumber(int &varLink, string label) {
  return [&varLink, label]() {
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    while (!UserInput(raw_input)) {
      cout << label;
      getline(cin, raw_input);
    }
    varLink = stoi(raw_input);
  };
}

function<void()> inline EnterString(string &varLink, string label) {
  return [&varLink, label]() {
    cout << label;
    getline(cin, varLink);

    while (!UserInputString(varLink)) {
      cout << label;
      getline(cin, varLink);
    }
  };
}

// Чтение студента с клавиатуры
Student inline readStudentFromInput() {
  string input;
  EnterString(input, "Enter student data (e.g., \"John "
                     "Doe,123456,20,5,4,5,3,4\"): ")();

  stringstream ss(input);
  string fullName, surname, name;
  int id, age, grade;

  if (!getline(ss, fullName, ',')) {
    cout << "Error: Invalid student data format." << endl;
    return Student();
  }
  stringstream nameStream(fullName);
  if (!getline(nameStream, surname, ' ') || !getline(nameStream, name)) {
    cout << "Error: Invalid student name format." << endl;
    return Student();
  }

  if (!(ss >> id) || ss.get() != ',') {
    cout << "Error: Invalid student ID format." << endl;
    return Student();
  }

  if (!(ss >> age) || ss.get() != ',') {
    cout << "Error: Invalid student age format." << endl;
    return Student();
  }

  Student student(surname, name, id, age);
  while (ss >> grade) {
    if (grade < 1 || grade > 5) {
      cout << "Error: Invalid grade value." << endl;
      return Student();
    }
    student.grades.push_back(grade);
    if (ss.peek() == ',')
      ss.ignore();
  }

  if (student.grades.empty()) {
    cout << "Error: Student must have at least one grade." << endl;
    return Student();
  }

  return student;
}

// Создание списка студентов для операций
extern list<Student> studentList;
// Создание двусторонней очереди студентов для операций
extern deque<Student> studentDeque;
// Создание словаря студентов для операций
extern map<int, Student> studentMap;
// Создание множества ID студентов для операций
extern set<int> idSet;
// Создание стека студентов для операций
extern stack<Student> studentStack;

#endif // VDOVKIN_LR1_STRUCTURE_STL_DEF_H
