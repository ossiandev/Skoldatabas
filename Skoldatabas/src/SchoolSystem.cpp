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
        char input ='0';
       
        std::cin >> input;





        switch (input)
        {
        case '1':
            SchoolSys::AddStudent();
            break;
        case '2':
            SchoolSys::RemoveStudent();
            break;
        case '3':
            SchoolSys::AddClass();
            break;
        case '4':
            SchoolSys::RemoveClass();
            break;
        case '5':
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
// Needs to check if _class exists in database or add student class to database
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
        std::cin.ignore();
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
    //student age with try catch incase with letters
    while (!confirmed)
    {
        SchoolSys::Clear();
        std::cout << "Please enter Student Age\n\n";
        std::cout << "Age : ";
        int age = 0;
        
     
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
        //Transforming string to uppercase   
        std::transform(student.SchoolClass.begin(), student.SchoolClass.end(), student.SchoolClass.begin(), ::toupper);

        std::cout << "\nStudent Class is " << student.SchoolClass << "\n";
        std::cout << "1. Confirm\n";
        std::cout << "2. Decline\n";
        std::cin >> input;
        if (input == "1")
        {
            std::cout << "Checking if Student is within class.\n";
            for (auto & i :schoolClasses)
            {
                
                if (student.SchoolClass != i)
                {
                    std::cout << "Student class does not exist. \n";
                    std::cout << "Student class will automatically be created to remove please visit remove page. \n";
                    schoolClasses.push_back(student.SchoolClass);
                    std::cin;

                }
            }
            confirmed = true;

        }

        
    }
    students.push_back(student);

    std::cout << students[0].name << " added!";
}


void SchoolSys::RemoveStudent()
{
    bool searching = true;
    std::string input = "";
    while (searching)
    {
        SchoolSys::Clear();

        std::getline(std::cin, input);

        
        

        
       
    }

}

void SchoolSys::AddClass()
{
    SchoolSys::Clear();
    std::cout << "Add a school class \n Class Name : ";

    std::string input = "";
    std::cin >> input; 

    std::cout << "Adding schoolclass... \n";
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
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
    SchoolSys::Clear();
    if (schoolClasses.size() == 0) { return; }


    //How many classes should be displayed per page
    int pageSize = 5;

    //Which page user is on
    int page = 0;
    char input = '0';

    std::cout << "List of all existing classes:\n\n";
    //for what page you are on
   
   for (int i = page; i < schoolClasses.size(); i++)
    {
        //print pageSize amount of classes
        std::cout << (i + 1) << ": " << schoolClasses[i] << "\n";
        if (i == pageSize) 
        {
            if (page != 0)  std::cout << "\n d. Next Page"; 
            
            else  std::cout << "\n d. Next Page";  std::cout << "\n a. Previous Page"; 
        }
        
    }
   
   


}
//FUNCTIONS THAT ONLY PRINT 
void SchoolSys::Clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}
