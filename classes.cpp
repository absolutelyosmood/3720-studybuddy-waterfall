#include "classes.h"

//Session Class
void Session::sendInvitation()
{
    sessionID = rand() % 8999 + 1000;
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

//Course Class
void Course::setCode(string code)
{
    courseCode = code;
}

void Course::setName(string name)
{
    courseName = name;
}

//Student Class
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
    printf("Please input your name: ");
    getline(cin, name);
    printf("Please input your email: ");
    getline(cin, email);

}

void Student::updateProfile()
{
    Course courseHolder;
    string courseNum;
    string courseName;

    int userChoice = 3;
    printf("What would you like to update? (Please input 0 for email, "
        "1 for courses, or 2 for name)\n");

    scanf("%d", userChoice);
    switch(userChoice) {
        case 0:
            printf("Please input your new email: ");
            getline(cin, Student::email);
            break;
        case 1:
            printf("Please input the course's number: ");
            getline(cin, courseNum);
            courseHolder.setCode(courseNum);
            printf("Please input the course's name: ");
            getline(cin, courseName);
            courseHolder.setCode(courseName);
            break;
        case 2:
            printf("Please input your new name: ");
            getline(cin, Student::name);
            break;
        default:
            printf("Invalid option. Please try again.");
    }
}

void Student::addAvailability(const Availability& slot)
{
    availability.push_back(slot);
}

void Student::removeAvailability(const Availability& slot)
{
    availability.erase(find(availability.begin(), availability.end(), slot));
}

vector<Student*> Student::searchBuddies(const Course& course)
{
    vector<Student*> matches;
    //TODO: Find out how to search through full list of students
    for() {

    }

    return matches;
}

vector<Student*> Student::recieveMatchSuggestions()
{
    //Same functionality as searchBuddies???
}

void Student::scheduleSession(Session* session)
{
    session->sendInvitation();
}

void Student::confirmSession(Session* session)
{
    session->confirm();
}

void Student::declinesession(Session* session)
{
    session->decline();
}