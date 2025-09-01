#include "classes.h"
#include <iostream>

Course makeCourse();


int main (){
    std::vector<Student> schoolDir;
    bool loop;
    int choice = 0;
    while(loop){
        int studentNum = 0;
        std::cout << "Welcome to the study buddy!\n";
        std::cout << "Please choose what you want to do.\n";
        std::cout << "[1] Create Profile\n[2]Edit Availability\n[3]Manage Profile\n";
        std::cout << "[4]Search for Study Buddy\n[5]Schedule a Study Session\n[6]Exit\n";
        std::cin >> choice;
        if(choice == 0 || choice > 7){
            std::cout << "Your choice must be 1-7";
        }
        else if(choice == 1){
            Student placeholder;
            schoolDir.push_back(placeholder);
            schoolDir.back().createProfile();
            studentNum = schoolDir.size();
        }
        else if(choice == 2){
            Availability tempAV;
            string avHolder;
            int AvailabilityChoice = 0;
            bool AvailabilityLoop = true;
            std::cout << "Please input the date for your availability.\n";
            std::cin >> avHolder;
            tempAV.setDate(avHolder);
            std::cout << "Please input the start time for your availability in the format: HH:MM AM/PM\n";
            std::cin >> avHolder;
            tempAV.setStart(avHolder);
            std::cout << "Please input the end time for your availability in the format: HH:MM AM/PM\n";
            std::cin >> avHolder;
            tempAV.setEnd(avHolder);
            std::cout << "Are you adding or removing availability? type 1 to add type 2 to remove\n";
            std::cin >> AvailabilityChoice;
            while(AvailabilityLoop)
                if(AvailabilityChoice == 1){
                    schoolDir.at(studentNum).addAvailability(tempAV);
                    AvailabilityLoop = false;
                }
                else if(AvailabilityChoice == 2){
                    schoolDir.at(studentNum).removeAvailability(tempAV);
                    AvailabilityLoop = false;
                }
                else{
                    std::cout << "The choice must be 1 or 2.\n";
                }
            
        }
        else if(choice == 3){
            schoolDir.at(studentNum).updateProfile();
        }
        else if(choice == 4){
            Course tempCourse = makeCourse();
            std::vector<Student*> foundBuds = schoolDir.at(studentNum).searchBuddies(tempCourse, schoolDir);
        }
        else if(choice == 5){
            bool sessionLoop;
            int sessionChoice;
            string sessionIn;
            std::cout << "Please input the date for your session:\n";
            std::cin >> sessionIn;
            Session sessionFinder();
            Course tempCourse = makeCourse();
            std::vector<Student*> sessionBuddies = schoolDir.at(studentNum).searchBuddies(tempCourse, schoolDir);

            Session newSession(tempCourse, sessionIn, sessionBuddies);

            std::cout << "Are you accepting or declining this invitation? Type 1 for Schedule type 2 for Accept/Deny.\n";
            std::cin >> sessionChoice;
            while (sessionLoop){
                if(sessionChoice == 1){
                schoolDir.at(studentNum).scheduleSession(&newSession);
                sessionLoop = false;
                }
                else if(sessionChoice == 2){
                    std::cout << "Are you accepting or declining this invitation? Type 1 for Accept type 2 for Decline.\n";
                    std::cin >> sessionChoice;
                    while (sessionLoop){
                        if(sessionChoice == 1){
                            schoolDir.at(studentNum).confirmSession(&newSession);
                            sessionLoop = false;
                        }
                        else if(sessionChoice == 2){
                            schoolDir.at(studentNum).declinesession(&newSession);
                            sessionLoop = false;
                        }
                        else{
                            std::cout << "The choice must be one or two.\n";
                        }
                    }
                    }
                    else {
                        std::cout << "The choice must be one or two.\n";
                    }
                }
            }
        else if(choice == 6){
            loop = false;
        }
    }
}

Course makeCourse()
{
    Course newCourse;
    string stringHolder;
    std::cout << "Please input your course's number.\n";
    std::cin >> stringHolder;
    newCourse.setCode(stringHolder);
    std::cout << "Please input your course's name.\n";
    std::cin >> stringHolder;
    newCourse.setName(stringHolder);

    return newCourse;
}