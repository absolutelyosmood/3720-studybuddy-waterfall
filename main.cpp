#include "classes.h"
#include <iostream>

int main (){
    bool loop;
    int choice = 0;
    while(loop){
        std::cout << "Welcome to the study buddy!\n";
        std::cout << "Please choose what you want to do.\n";
        std::cout << "[1] Create Profile\n[2]Edit Availability\n[3]Manage Profile\n";
        std::cout << "[4]Search for Study Buddy\n[5]Schedule a Study Session\n[6]Check Invitations\n";
        std::cout << "[7]Exit\n";
        std::cin >> choice;
        if(choice == 0 || choice > 7){
            std::cout << "Your choice must be 1-7";
        }
        else if(choice == 1){
            Student placeholder;
            placeholder.createProfile();
        }
        else if(choice == 2){
            Student placeholder;
            int AvailabilityChoice = 0;
            bool AvailabilityLoop = true;
            std::cout << "Are you adding or removing availability? type 1 to add type 2 to remove\n";
            std::cin >> AvailabilityChoice;
            while(AvailabilityLoop)
                if(AvailabilityChoice == 1){
                    placeholder.addAvailability();
                    AvailabilityLoop = false;
                }
                else if(AvailabilityChoice == 2){
                    placeholder.removeAvailability();
                    AvailabilityLoop = false;
                }
                else{
                    std::cout << "The choice must be 1 or 2.\n";
                }
            
        }
        else if(choice == 3){
            Student placeholder;
            placeholder.updateProfile();
        }
        else if(choice == 4){
            Student placeholder;
            placeholder.searchBuddies();
        }
        else if(choice == 5){
            Student placeholder;
            bool sessionLoop;
            int sessionChoice;
            std::cout << "Are you accepting or declining this invitation? Type 1 for Schedule type 2 for Accept/Deny.\n";
            std::cin >> sessionChoice;
            while (sessionLoop){
                if(sessionChoice == 1){
                placeholder.searchBuddies();
                placeholder.scheduleSession();
                sessionLoop = false;
                }
                else if(sessionChoice == 2){
                    std::cout << "Are you accepting or declining this invitation? Type 1 for Accept type 2 for Decline.\n";
                    std::cin >> sessionChoice;
                    while (sessionLoop){
                        if(sessionChoice == 1){
                            placeholder.confirmSession();
                            sessionLoop = false;
                        }
                        else if(sessionChoice == 2){
                            placeholder.declinesession();
                            sessionLoop = false;
                        }
                        else{
                            std::cout << "The choice must be one or two.\n";
                        }
                    }
                    }
                }
                else{
                    std::cout << "The choice must be one or two.\n";
                }
            }
        else if(choice == 6){
            loop = false;
        }
    }
}