#include <iostream>
#include <vector>
#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int year;
    float miles;
    float cost;
public:
    Car(std::string _brand, std::string _model, int _year, float _miles, float _cost) {
        brand = _brand;
        model = _model;
        year = _year;
        miles = _miles;
        cost = _cost;
    }

    std::string GetBrand() { return brand; }
    std::string GetModel() { return model; }
    int GetYear() { return year; }
    float GetMiles() { return miles; }
    float GetCost() { return cost; }
};



class Catalog {
private:
    std::vector<Car> catalog;
    unsigned int size;
public:
    Catalog(int _size) {
        size = _size;
    };

    

    std::vector<Car> GetCatalog() { return catalog; }

    void AddToCatalog(Car& car) {
        catalog.push_back(car);
    }

    void RemoveFromCatalog(int posInCatalog) {
        catalog.erase(catalog.begin() + posInCatalog);
    }
};

void PrintCatalog(std::vector<Car> c) {
    for (int i = 0; i < c.size(); i++)
    {
        std::cout << " Car " << i << ": " << c.at(i).GetYear() << " " <<
        c.at(i).GetBrand() << " " << c.at(i).GetModel() << std::endl;
    }
}

int main() {
    Catalog c(50);
    Car toyotaCorolla("Toyota", "Corolla", 2001, 85205, 8500);
    Car chevyTahoe("Chevy", "Tahoe", 2006, 120425, 11500);
    Car jeepCompass("Jeep", "Compass", 2020, 12003, 19000);
    Car toyota4Runner("Toyota", "4Runner", 2008, 130200, 14000);

    c.AddToCatalog(toyotaCorolla);
    c.AddToCatalog(chevyTahoe);
    c.AddToCatalog(jeepCompass);
    c.AddToCatalog(toyota4Runner);

    PrintCatalog(c.GetCatalog());

    std::cout << "" << std::endl;
    
    c.RemoveFromCatalog(3);

    PrintCatalog(c.GetCatalog());

    std::cin.get();
}