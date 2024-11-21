#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Student{

private:
time_t timestamp;
string name;
string group;
int studentId;
float averageScore;

public:
void setName(string name);
void setGroup(string group);
void setStudentId(int studentId);
void setAverageScore(float averageScore);
int getAge();
bool isExcellentStudent();
string toString();
void setbirthDate(time_t timestamp);
};
