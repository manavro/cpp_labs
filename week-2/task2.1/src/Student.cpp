#include "Student.hpp"

void Student::setName(string name) {
                this->name = name;
        }

void Student::setGroup(string group) {
                this->group = group;
        }

void Student::setStudentId(int studentId) {
                this->studentId = studentId;
        }

void Student::setAverageScore(float averageScore) {
                this->averageScore = averageScore;
        }

string Student::toString() {
                string g;
                g.append("Student name: ");
                g.append(name);
                g.append("\n"); 
                g.append("Student group: ");
                g.append(group);
                g.append("\n");
                g.append("Student Id: ");
                g.append(to_string(studentId));
                g.append("\n");
                g.append("Student Average Score: ");
                g.append(to_string(averageScore));
                g.append("\n");
                g.append("Student Birth Date: ");
                g.append(ctime(&timestamp));
                return g;
        }

void Student::setbirthDate(time_t timestamp) {
      	 this->timestamp = timestamp;
        }

 int Student::getAge() {
        struct tm* now = localtime(&timestamp);
        return 2024 - 1900 - now->tm_year;
        }

 bool Student::isExcellentStudent() {
      	 if (averageScore > 4.8) {
	return 0;
        return true;
 }}
