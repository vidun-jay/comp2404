#include "Algorithms.h"

/****************
 * CONSTRUCTORS *
 ****************/

Algorithms::Algorithms() {}
Algorithms::~Algorithms() {}

/*********
 * OTHER *
 *********/

/**
 * @brief Add a new `Student` object to `students` vector
 *
 * @param number: student number
 * @param name: student name
 * @param gpa: student gpa
 */
void Algorithms::addStudent(const string& number, const string& name, float gpa) {
    Student student(number, name, gpa);
    students.push_back(student);
}

/**
 * @brief Add all passing students to vector
 *
 * @param smart_kids: vector of kids with passing grades
 */
void Algorithms::getPassingStudents(vector<Student>& smart_kids) {
    for (const Student& student : smart_kids) {
        if (student.getGpa() >= 6.0)
            smart_kids.push_back(student);
    }
}

/**
 * @brief Add all students in sorted order by number
 *
 * @param vector: students vector to store ordered students
 */
void Algorithms::sortByNumber(vector<Student>& vector) {
    vector = students;
    sort (vector.begin(), vector.end(), [](const Student& student1, const Student& student2) {
        return student1.getNumber() < student2.getNumber();
    });
}

/**
 * @brief Add all students in sorted order by name
 *
 * @param vector: students vector to store ordered students
 */
void Algorithms::sortByName(vector<Student>& vector) {
    vector = students;
    sort (vector.begin(), vector.end(), [](const Student& student1, const Student& student2) {
        return student1.getName() < student2.getName();
    });
}

/**
 * @brief Creates an iterator out of the students with highest GPAs
 *
 * @param studentsIterator: iterator to store students with...
 * @return true if successful;
 * @return false otherwise
 */
bool Algorithms::highestGpa(vector<Student>::iterator& studentsIterator) {
    if (students.empty()) return false;

    vector<Student>::iterator max = max_element(students.begin(), students.end(), [](const Student& student1, const Student& student2) {
        return student1.getGpa() < student2.getGpa();
    });

    studentsIterator = max;
    return true;
}

/**
 * @brief
 *
 * @param name: Looks for student with certain name
 * @param studentsIterator: iterator to search
 * @return true if successful;
 * @return false otherwise
 */
bool Algorithms::findStudent(const string& name, vector<Student>::iterator& studentsIterator) {
    vector<Student>::iterator iterator = find_if(students.begin(), students.end(), [&name](const Student& student) {
        return student.getName() == name;
    });

    if (iterator != students.end()) {
        studentsIterator = iterator;
        return true;
    } return false;
}