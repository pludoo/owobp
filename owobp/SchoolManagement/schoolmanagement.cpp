#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

/*

MESSY CODE BUT....

i don't care :), cause...

I'M TIRED!

*/

class Student {
private:
    std::string name;
    float gpa;
    int birthYear;
public:
    Student(std::string _name, int _gpa, int _birthYear) {
        name = _name;
        gpa = _gpa;
        birthYear = _birthYear;
    }

    std::string get_name() { return name; }
    int get_gpa() { return gpa; }
    int get_birth_year() { return birthYear; }

    void update_name(std::string _name) { name = _name; }
    void update_gpa(int _gpa) { gpa = _gpa; }
    void update_birth_year(int _birth_year) { birthYear = _birth_year; }
};

class School {
private:
    std::vector<Student*> students;
    std::string district;
    std::string name;
    int studentCount;
public:
    School(std::string _district, std::string _name, int _studentCount)  {
        district = _district;
        name = _name;
        studentCount = _studentCount;
    }

    void CreateStudent(std::string _name, float _gpa, int _birthYear) {
        students.push_back(new Student(_name, _gpa, _birthYear));
        std::cout << "Student " << _name << " created!\n";
        studentCount++;
    }

    void RemoveStudent(int index) {
        std::cout << "Removing index " << index << ", '" << students.at(index)->get_name() << "' from database, please wait.\n";

        try { students.erase(students.begin() + index); std::cout << "Removal successful.\n"; }
        catch(const std::exception& e) { std::cerr << "Could not remove requested student: " << e.what() << std::endl; }

    }

    void PrintInfo() {
        for (int i = 0; i < students.size(); i++)
        {
            std::cout << i << ": " << students.at(i)->get_name() << " (" << students.at(i)->get_birth_year() << ") | GPA: " << std::setprecision(2) << std::fixed << students.at(i)->get_gpa() << std::endl;
        }

        std::cout << "Done displaying students!\n";
    }

    void UpdateStudentCount() { studentCount = students.size(); }
};




int main() {

    School school("Douglas County", "Ponderosa", 10);

    std::cout << "PRERUN";
    std::cout << std::endl;
    std::cout << std::endl;
    
    school.CreateStudent("Jayden Hudlez", 3.9, 2005);
    school.CreateStudent("John Doe", 2.9, 2004);
    school.CreateStudent("Alyssa Johnson", 3.7, 2003);
    school.CreateStudent("Avery Miller", 3.7, 2005);
    school.CreateStudent("Layla Smith", 3.9, 2006);

    school.CreateStudent("Major Balls", 2.9, 2006);
    school.CreateStudent("Jared Valorant", 2.3, 2005);
    school.CreateStudent("Jack Blue", 3.8, 2003);
    school.CreateStudent("Alex Potato", 3.3, 2005);
    school.CreateStudent("Braxton Jank", 3.1, 2003);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Welcome to the Ponderosa Student Management System!\n";

    std::cout << "Would you like to create or remove a student? (c/r)\n";
    char inp;
    std::cin >> inp;


    std::string studentName;
    float gpa;
    int birthYear;
    switch (inp) {
        case 'c': 
            std::cout << "Creating a new Student!" << std::endl;

            std::cout << std::endl;

            std::cout << "Student's Name?\n";
            std::cin.ignore(1,'\n');
            std::getline(std::cin, studentName); 
            std::cout << "Starting GPA?\n"; 
            std::cin >> gpa;
            std::cout << "Birth Year?\n";
            std::cin >> birthYear;

            try { school.CreateStudent(studentName, gpa, birthYear); }
            catch(const std::exception& e) { std::cerr << "Failed to create student: " << e.what() << std::endl; }
            
            break;

        case 'r':
            int sIndex;
            std::cout << "Removing a registered student\n";
            std::cout << std::endl;
            std::cout << "Enter student index number\n";
            std::cin >> sIndex;
            
            try { school.RemoveStudent(sIndex); }
            catch(const std::exception& e) { std::cerr << "Failed to remove student: " << e.what() << std::endl; }

            break;
            
    }

    std::getchar();
}