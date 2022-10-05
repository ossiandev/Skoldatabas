#include "SchoolSystem.h"


void SchoolSys::Run(bool running)
{
    while (running)
    {
        SchoolSys::Clear();
        std::cout << "School Database Main Menu.\nHere you can access all classes and all student files\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Remove Student\n";
        std::cout << "3. Remove Class\n";
        std::cout << "4. Show Students\n";
        std::cout << "5. Show Classes\n";
        std::cout << "6. Log out\n\n Please Select your business\n Input: ";
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
            SchoolSys::RemoveClass();
            break;
        case '4':
            SchoolSys::ShowStudents();
            break;
        case '5': 
            SchoolSys::ShowClasses();
            break;
        case '6':
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
        std::cout << "Student Age is " << student.age << "\n";
        std::cout << (  "1. Confirm\n");
        std::cout << (  "2. Decline\n");
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
        std::cout << ("Please enter Student class\n");
        std::cout << "Class  : ";
        std::cin >> input;
        student.SchoolClass = input;
        SchoolSys::Clear();
        //Transforming string to uppercase   
        std::transform(student.SchoolClass.begin(), student.SchoolClass.end(), student.SchoolClass.begin(), ::toupper);
        bool noClass = true;
        std::cout <<"Student Class is " <<student.SchoolClass + "\n";
        std::cout << "1. Confirm\n";
        std::cout << "2. Decline\n";
        std::cin >> input;
        if (input == "1")
        {
            students.push_back(student);
            std::cout <<( student.name + " added!");
            std::cin.ignore();
            std::cin.get();
            confirmed = true;
            //Checking if schoolclass does exit
            for (auto& i : schoolClasses)
            {
                if (student.SchoolClass == i)
                {
                    return;
                }
            }
        }
        std::cout <<( "Student class does not exist.\n");
        std::cout <<("Student class will automatically be created\n");
        schoolClasses.push_back(student.SchoolClass);
        std::cin.ignore();
        std::cin.get();
    }
}


void SchoolSys::RemoveStudent()
{
    if (students.size() == 0) { return; }
    bool searching = true;
    std::string input = "";
    while (searching)
    {
        SchoolSys::Clear();
        std::cout << "Removing Student\nPlease type their name (case sensitive) \n\nName: ";
        std::cin.ignore();
        std::getline(std::cin, input);
        SchoolSys::Clear();
        for (int i = 0; i < students.size(); i++)
        {
            if (input == students[i].name)
            {
                std::cout << "Removing " << input;
                std::cin.get();
                     //if students class doesnt have more members than themselves class will get automatically removed.
                //find schoolclass size
                int schoolClassSize = 0;
                for (int j = 0; j < schoolClasses.size(); j++)
                {
                    
                    if (schoolClasses[j] == students[i].SchoolClass)
                    {
                        for (int a = 0; a < students.size(); a++)
                        {
                            //schoolclass size found 
                            if (students[a].SchoolClass == schoolClasses[j])
                            {
                                schoolClassSize++;
                            }
                        }
                        //if there is one member within class, erase
                        if (schoolClassSize == 1)
                        {
                            schoolClasses.erase(schoolClasses.begin() + j);
                        }
                    }    
                }
                students.erase(students.begin() + i);
                searching = false;
                return;
            }
        }  
        std::cout <<( "No such Person found\n");
        std::cout <<( "1. Exit back to menu\n");
        std::cout << ( "2. Find right Person\n");
        char lastInput = 'l';
        std::cin.get(lastInput);
        //exit
        if (lastInput == '1')
        {
            searching = false;
        }
    }
}


void SchoolSys::RemoveClass()
{
    if (schoolClasses.size() == 0) { std::cout << "No classes found \n"; std::cin.ignore();std::cin.get(); return; }
    bool removing = true;
    while(removing)
    { 
    SchoolSys::Clear();
    std::cout <<("To remove a Class please type their name (case sensitive) \nNote however that removing a class will remove all students within that same class.\n");
    std::cout << "Name: ";
    std::string input = "";
    std::cin.ignore();
    std::getline(std::cin,input);
   for (int i = 0; i < schoolClasses.size(); i++)
   {
       if (schoolClasses[i] == input) 
       {
           std::cout << "Removing "<< schoolClasses[i] << " along with all students within\n";
           std::cin.get();
           //erases all students with schoolclasses[i]
           for (int j = 0; j < students.size(); j++) 
           {
               if (students[j].SchoolClass == schoolClasses[i])
               {
                   students.erase(students.begin()+j);
               }
           }
           //erases schoolclasses[i]

           schoolClasses.erase(schoolClasses.begin() + i);
           removing = false;
           return;
       }

   }
   SchoolSys::Clear();
   std::cout << "No such schoolclass found\n\n";
   std::cout << "1. Exit back to menu\n";
   std::cout << "2. Find right class\n\n";
   char lastInput = 'l';
   std::cin >> lastInput;
   //exit
   if (lastInput == '1')
   {
       removing = false;
   }
   }

   // Shelved Idea 
   /* if i ever go back to project please minimize
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
   
   */

}

//FUNCTIONS THAT ONLY PRINT 
//Clears Console
void SchoolSys::Clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}
//Shows Students
void SchoolSys::ShowStudents()
{
    SchoolSys::Clear();
    // if there are no students to show return
    if (students.size() == 0) { std::cout << ("No Students Found.\n"); std::cin.ignore(); std::cin.get(); return; }
    std::cout <<("Type Student Name to get their Information\nType a class to find who goes to what class.\n");
    //Get student name from input
    std::string input = "";
    std::cin.ignore();
    std::getline(std::cin, input);
    //Go through whole student vector
    for (int i = 0; i < students.size(); i++)
    {
        //When student is found
        if (input == students[i].name)
        {
            //Display all info
            SchoolSys::Clear();
            std::cout << ("School Student found! \n");
            std::cout << "Name: " <<students[i].name << "\n";
            std::cout << "Age: " <<students[i].age << "\n";
            std::cout << "Class" <<students[i].SchoolClass << "\n";
            std::cout << "\nPress any key to return to menu.\n";
            std::cin.ignore();
            std::cin.get();
            return;
        }
    }
    //Find Student Class Mates
    for (int i = 0; i < schoolClasses.size(); i++)
    {
        //When school class is found
        if (schoolClasses[i] == input)
        {
            //find each student with schoolclass[i]
            for (auto& student : students) 
            {
                //Print name
                if (student.SchoolClass == schoolClasses[i])
                {
                    std::cout << (student.name + "\n");
                }
            }
            std::cout << ("\nPress any key to return to menu\n");
            std::cin.ignore();
            std::cin.get();
            
        }
    }
}

void SchoolSys::ShowClasses()
{
    SchoolSys::Clear();
    // if no classes exist go back to menu
    if (schoolClasses.size() == 0) { std::cout << ("No classes available\n"); std::cin.get(); return; }
    std::cout << "Showing all classes\n";
    //Prints all Classes
    for (int i = 0; i < schoolClasses.size(); i++)
    {
        std::cout << (i + 1) << +". ";
        std::cout << (schoolClasses[i] + "\n");

    }
    std::cin.ignore();
    std::cin.get();
    return;
    
    
}


