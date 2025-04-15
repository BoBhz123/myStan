#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

class Course {
public:
    int course_id;
    string course_name;
    int instructor_id;
    int capacity;
    vector<int> student_ids;
    vector<int> grades;
    vector<string> announcements;
    vector<string> homeworks;

    Course(int id, string name, int insid, int capacity);
    json toJSON();
    static Course fromJSON(const json& j);

    static json loadCourses();
    static void saveCourses(const json& courses);
    void addStudent(int student_id);
    void removeStudent(int student_id);
    void updateDetails(string newName, int newInstructorID, int newCapacity);
    void getStatistics();
    void postAnnouncement(string announcement);
    void addHomework(string homework);
};

#endif // COURSE_H
