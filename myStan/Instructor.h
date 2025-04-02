#pragma once
#include "User.h"
#include "Course.h"

class Instructor :
    public User
{
public:
    Instructor(int id, string name,string password);
    json toJSON() ;
    void assignGrade(int studentID, int grade);
    void postAnnouncement(string announcement);
    void uploadMaterial();
};

