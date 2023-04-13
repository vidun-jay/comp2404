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
    for (const auto& student : students) {
        if (student.getGpa() >= 6.0)
            smart_kids.push_back(student);
    }
}

/**
 * @brief Compares two students by name
 *
 * @param a: student a
 * @param b: student b
 * @return true if a < b;
 * @return false otherwise
 */
bool compareName(const Student& a, const Student& b) { return a.getName() < b.getName(); }

/**
 * @brief Compares two students by number
 *
 * @param a: student a
 * @param b: student b
 * @return true if a < b;
 * @return false otherwise
 */
bool compareNumber(const Student& a, const Student& b) { return a.getNumber() < b.getNumber(); }

/**
 * @brief Sort students by name
 *
 * @param v: students vector to store ordered students
 */
void Algorithms::sortByName(vector<Student>& v) {
    for (const Student& student : students)
        v.push_back(student);

    sort(v.begin(), v.end(), compareName);
}

/**
 * @brief Add all students in sorted order by number
 *
 * @param vector: students vector to store ordered students
 */
void Algorithms::sortByNumber(vector<Student>& v) {
    for (const Student& student : students)
        v.push_back(student);

    sort(v.begin(), v.end(), compareNumber);
}

/**
 * @brief Creates an iterator out of the students with highest GPAs
 *
 * @param studentsIterator: iterator to store students with...
 * @return true if successful;
 * @return false otherwise
 */
bool Algorithms::highestGpa(vector<Student>::iterator& stuIt) {
    if (students.empty()) return false;
    stuIt = students.begin();
    float max = stuIt->getGpa();

    for (auto i = students.begin() + 1; i != students.end(); ++i) {
        float curr = i->getGpa();
        if (curr > max) {
            max = curr;
            stuIt = i;
        }
    } return true;
}

/**
 * @brief Find student
 *
 * @param name: Looks for student with certain name
 * @param studentsIterator: iterator to search
 * @return true if successful;
 * @return false otherwise
 */
bool Algorithms::findStudent(const string& name, vector<Student>::iterator& stuIt) {
    for (auto i = students.begin(); i != students.end(); ++i) {
        if (i->getName() == name) {
            stuIt = i;
            return true;
        }
    } return false;
}