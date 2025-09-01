#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Student;

enum SessionStatus
{
    PENDING,
    CONFIRMED,
    DECLINED
};

class Course
{
    private:
        string courseName;
        string courseCode;
    public:
        void setName(string code);
        void setCode(string name);
};

class Availability
{
    private:
        string date;
        string startTime;
        string endTime;
    public:
        Availability();
        Availability(string date, string startTime, string endTime);
        void setDate(string date);
        void setStart(string startTime);
        void setEnd(string endTime);
};

class Session
{
    private:
        string sessionID;
        vector<Student*> participants;
        Course course;
        string dateTime;
        SessionStatus status;
    public:
        Session();
        Session(Course course, string dateTime, vector<Student*> students);
        void sendInvitation();
        void confirm();
        void decline();
};

class Student 
{
    private:
        string name;
        string email;
        vector<Course> courses;
        vector<Availability> availability;
        vector<Session*> scheduledSessions;
    public:
        Student();
        void createProfile();
        void updateProfile();
        void addAvailability(const Availability& slot);
        void removeAvailability(const Availability& slot);
        vector<Student*> searchBuddies(const Course& course, vector<Student> studentDir, int studentNum);
        void scheduleSession(Session* session);
        void confirmSession(Session* session);
        void declinesession(Session* session);

};