#include "classes.h"

void Session::sendInvitation()
{
    status = PENDING;
}

void Session::confirm()
{
    status = CONFIRMED;
}

void Session::decline()
{
    status = DECLINED;
}

void Course::setCode(string code)
{
    courseCode = code;
}

void Course::setName(string name)
{
    courseName = name;
}

Student::Student()
{
    Course courseHolder;
    courseHolder.setCode("3720");
    courseHolder.setName("Software Engineering");
    courses.push_back(courseHolder);
    courseHolder.setCode("3220");
    courseHolder.setName("Intro to OS");
    courses.push_back(courseHolder);
}

void Student::createProfile()
{
    
}

void Student::updateProfile()
{

}

void Student::addAvailability(const Availability& slot)
{

}

void Student::removeAvailability(const Availability& slot)
{

}

vector<Student*> Student::searchBuddies(const Course& course)
{

}

vector<Student*> Student::recieveMatchSuggestions()
{

}

void Student::scheduleSession(Session* session)
{

}

void Student::confirmSession(Session* session)
{

}

void Student::declinesession(Session* session)
{
    
}