#include "vdovkin_LR1_deque.cpp"
#include "vdovkin_LR1_list.cpp"
#include "vdovkin_LR1_map.cpp"
#include "vdovkin_LR1_set.cpp"
#include "vdovkin_LR1_stack.cpp"
#include "vdovkin_LR1_structure_STL_def.hpp"
#include "vdovkin_LR1_vector.cpp"

bool diffEnabled = false;

// Глобальный вектор студентов для синхронизации данных
vector<Student> students;

void printHelp() {
  cout << "Usage: ./program [OPTIONS]\n"
       << "Options:\n"
       << "  -d          Enable diff output for container changes\n"
       << "  -h, --help  Display this help message and exit\n"
       << "© 2025 Evgeniy Vdovkin\n";
}

int main(int argc, char *argv[]) {
  // Обработка аргументов командной строки
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-d") == 0) {
      diffEnabled = true;
    } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      printHelp();
      return 0;
    } else {
      cerr << "Unknown option: " << argv[i] << "\n";
      printHelp();
      return 1;
    }
  }
  // Структура для пункта меню
  struct MenuItem {
    string title;
    function<void()> action;
  };

  list<Student> studentList;
  deque<Student> studentDeque;
  map<int, Student> studentMap;
  set<int> idSet;
  stack<Student> studentStack;

  // Создание меню с использованием map
  map<int, MenuItem> menu = {
      {1,
       {"Create <vector> Student",
        []() {
          students.clear();
          loadStudentsFromFile(students, "students.txt");
          cout << "<vector> created from file." << endl;
        }}},
      {2, {"Show <vector> Student", []() { displayVector(students); }}},
      {3,
       {"Add entries to <vector> Student",
        []() {
          Student newStudent = readStudentFromInput();
          addStudentToVector(students, newStudent);
          cout << "Student added to <vector>." << endl;
        }}},
      {4,
       {"Sort students by third grade",
        []() { sortStudentsByThirdGrade(students); }}},
      {5,
       {"Create and show <list> Student",
        [&]() {
          studentList.clear();
          copyVectorToList(students, studentList);
          cout << "<list> created and displayed:" << endl;
          displayList(studentList);
        }}},
      {6,
       {"Delete students from <list> with ID multiple of 11",
        [&]() {
          cout << "Students with ID multiple of 11 removed from <list>:"
               << endl;
          removeStudentsWithIdMultipleOf11(studentList);
          // Обновляем вектор
          students.clear();
          students.assign(studentList.begin(), studentList.end());
        }}},
      {7,
       {"Add student to the middle of <list> ",
        [&]() {
          Student newStudent = readStudentFromInput();
          cout << "Student added to middle of <list>:" << endl;
          insertStudentInMiddle(studentList, newStudent);
          // Обновляем вектор
          students.clear();
          students.assign(studentList.begin(), studentList.end());
        }}},
      {8,
       {"Create and show <deque> Student",
        [&]() {
          studentDeque.clear();
          transferToListDeque(studentList, studentDeque);
          cout << "<deque> created and displayed:" << endl;
          displayDeque(studentDeque);
        }}},
      {9,
       {"Show first and last 3 students in <deque>",
        [&]() {
          cout << "First and last three students in <deque>:" << endl;
          printFirstAndLastThree(studentDeque);
        }}},
      {10,
       {"Create and show <map> Student",
        [&]() {
          studentMap.clear();
          fillMapFromVector(students, studentMap);
          cout << "<map> created and displayed:" << endl;
          displayMap(studentMap);
        }}},
      {11,
       {"Find student in <map> by ID",
        [&]() {
          int targetId;
          EnterNumber(targetId, "Enter student ID to find: ")();
          findStudentById(studentMap, targetId);
        }}},
      {12,
       {"Create and show <set> of IDs",
        [&]() {
          idSet.clear();
          createIdSet(students, idSet);
          cout << "<set> of IDs created and displayed:" << endl;
          displaySet(idSet);
        }}},
      {13,
       {"Check unique IDs and age 21",
        []() {
          if (checkUniqueId(students)) {
            cout << "All IDs are unique." << endl;
          } else {
            cout << "There are duplicate IDs." << endl;
          }
          if (checkAge21(students)) {
            cout << "There is a student with age 21." << endl;
          } else {
            cout << "No student with age 21." << endl;
          }
        }}},
      {14,
       {"Create and show <stack> Student",
        [&]() {
          studentStack = stack<Student>(); // Очищаем стек
          fillStackFromVectorReverse(students, studentStack);
          cout << "<stack> created and displayed:" << endl;
          displayStack(studentStack);
        }}},
      {15,
       {"Extract from <stack> until specific ID",
        [&]() {
          int targetId;
          EnterNumber(targetId, "Enter student ID to find: ")();
          cout << "Extracting until ID " << targetId << ":" << endl;
          extractUntilId(studentStack, targetId);
        }}},
  };

  int choice = 0;

  // Основной цикл программы
  while (true) {

    // Вывод меню
    cout << "Menu:" << endl;
    for (const auto &item : menu) {
      cout << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Exit" << endl;

    EnterNumber(choice, "Enter your choice: ")();

    if (choice == 0) {
      cout << "© 2025 Eugene Vdovkin" << endl;
      break;
    }

    cout << endl;

    if (menu.find(choice) != menu.end()) {
      clearTerminal();
      menu[choice].action();
    } else {
      clearTerminal();
      cout << "Invalid choice" << endl;
    }

    cout << endl << endl;
  }

  return 0;
}
