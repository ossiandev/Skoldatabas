#include "SchoolSystem.h"

void SchoolSys::Run(bool running)
{
    while (running)
    {
        SchoolSys::Clear();
        std::cout << "School Database Main Menu.\nHere you can access all classes and all student files\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Remove Student\n";
        std::cout << "3. Add Class\n";
        std::cout << "4. Remove Class\n";
        std::cout << "5. Log out\n\n Please Select your business\n Input: ";
        int input = 0;
        std::cin >> input;
        switch (input)
        {
        case 1:
            SchoolSys::AddStudent();
            break;
        case 2:
            SchoolSys::RemoveStudent();
            break;
        case 3:
            SchoolSys::AddClass();
            break;
        case 4:
            SchoolSys::RemoveClass();
            break;
        case 5:
            std::cout << "Exiting Program...";
            std::cin;
            running = false; 
            break;
        default:
            break;
        }
    }
}



//Document for AddStudent() 
// Needs to check if _class exists in database
void SchoolSys::AddStudent()
{
    Student student; 
    bool confirmed = false;
    std::string input = "";
    
    //Build Student Name
    while (!confirmed)
    {
        SchoolSys::Clear();
        std::cout << "Please enter Student name\n\n";
        std::cout << "Name : ";
        
        std::getline(std::cin, input);
        student.name = input;
        SchoolSys::Clear();
        std::cout << "\nStudent name is " << student.name << "\n";
        std::cout << "1. Confirm\n";
        std::cout << "2. Decline\n";
        std::cin >> input;
        if (input == "1")
        {
            confirmed = true;
        }
    }
    confirmed = false;
    //Build student age
    while (!confirmed)
    {
        SchoolSys::Clear();
        std::cout << "Please enter Student Age\n\n";
        std::cout << "Age : ";
        int age = 0;
        try
        {
            std::cin >> age;
            student.age = age;
            SchoolSys::Clear();
            std::cout << "\nStudent Age is " << student.age << "\n";
            std::cout << "1. Confirm\n";
            std::cout << "2. Decline\n";
            std::cin >> input;
            if (input == "1")
            {
                confirmed = true;
            }

        }
        catch (int age)
        {
            std::cout << "Write in Numbers not in letters\n";
            std::cin;
        }
    }

    //Student Class
    confirmed = false;
    while (!confirmed)
    {
        SchoolSys::Clear();
        std::cout << "Please enter Student class\n\n";
        std::cout << "Class  : ";

        std::cin >> input;
        student.SchoolClass = input;
        SchoolSys::Clear();
        std::cout << "\nStudent Class is " << student.SchoolClass << "\n";
        std::cout << "1. Confirm\n";
        std::cout << "2. Decline\n";
        std::cin >> input;
        if (input == "1")
        {
            confirmed = true;
        }
    }
    students.push_back(student);

    std::cout << students[0].name << " added!";
}


void SchoolSys::RemoveStudent()
{
    
}

void SchoolSys::AddClass()
{
    SchoolSys::Clear();
    std::cout << "Add a school class \n Class Name : ";

    std::string input = "";
    std::cin >> input; 

    std::cout << "Adding schoolclass... \n";
    for (int i  =0  ; i < schoolClasses.size(); i++)
    {
        
        if (input != schoolClasses[i])
        {
            schoolClasses.push_back(input);
        }
    }

}

void SchoolSys::RemoveClass()
{

}
//FUNCTIONS THAT ONLY PRINT 
void SchoolSys::Clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}
void StartMenu()
{
    
    std::cout << "School System Adminstration App\n";
    std::cout << "Please Select one of the following \n";
    std::cout << "\n\n";
    std::cout << "1. Add Student\n\n";
    std::cout << "2. Remove Student\n\n";
    std::cout << "3. Add Class\n\n";
    std::cout << "4. Remove Class\n\n";
    std::cout << "5. Exit Program\n\n";


}

void  AddStudentMenu()
{
    

}

void  RemoveStudentMenu()
{
    

}

void  AddClassMenu()
{


}

void  RemoveClassMenu()
{
    
    
}
