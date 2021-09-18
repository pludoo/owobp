#include <iostream>
#include <vector>

class Resident {
private:
    std::string fullName;
    int daysStaying;
public:
    Resident(std::string _fullName, int _daysStaying) {
        fullName = _fullName;
        daysStaying = _daysStaying;
    }

    std::string GetName() { return fullName; }
    int GetDaysStaying() { return daysStaying; }
};



class Hotel {
private:
    std::vector<Resident*> residentList;
    std::string company;
    int currentResidents;
    const int maxResidents = 500;
public:
    Hotel(std::string _company, int _currentResidents = 0) {
        company = _company;
        currentResidents = _currentResidents;
    }

    std::string GetCompany() { return company; }
    int GetCurrentResidents() { return currentResidents; }
    int GetMaxResidents() { return maxResidents; }

    void SetCompany(std::string _company) { company = _company; }
    void SetCurrentResidents(int _newCurrentResidents) { currentResidents = _newCurrentResidents; }
    void AddToCurrentResidents(std::string _name, int daysStaying) { currentResidents ++; residentList.push_back(new Resident(_name, daysStaying)); }
    void RemoveFromCurrentResidents(int index) { currentResidents--; residentList.erase(residentList.begin() + index); }

    void PrintResidents() {
        for (int i = 0; i < residentList.size(); i++)
        {
            std::cout << "Resident " << i << ": " << residentList.at(i)->GetName() << " Days Staying: " << residentList.at(i)->GetDaysStaying() << std::endl;
        }
        
    }
};

int main() {
    Hotel h("4 Seasons");
    h.AddToCurrentResidents("Jayden Smith", 2);
    h.AddToCurrentResidents("Example Name", 4);

    h.PrintResidents();

    h.RemoveFromCurrentResidents(0);

    h.PrintResidents();

    std::cin.get();
}