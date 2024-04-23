#include <iostream>
#include <set>
#include <string>

using namespace std;

class Сysteine {
private:
    string name;
    int atomicNumber;
    string symbol;

public:
    Сysteine(string name, int number, string symbol) : name(name), atomicNumber(number), symbol(symbol) {}

    string GetName() const {
        return name;
    }

    int GetAtomicNumber() const {
        return atomicNumber;
    }

    string GetSymbol() const { 
        return symbol;
    }

    // Сравнение элементов для сортировки по имени
    bool operator<(const Сysteine& newElem) const {
        return name < newElem.name;
    }
};

int main() {
    // Создаем множество химических элементов цистеина C3H7NO2S
    set<Сysteine> chemicalSet;

    chemicalSet.insert(Сysteine("Carbon", 6, "C"));
    chemicalSet.insert(Сysteine("Hydrogen", 1, "H"));
    chemicalSet.insert(Сysteine("Oxygen", 8, "O"));
    chemicalSet.insert(Сysteine("Nitrogen", 7, "N"));
    chemicalSet.insert(Сysteine("Sulfur", 16, "S"));

    // Добавляем элемент с неуникальным состоянием
    cout << "Try to add a duplicate element...\n\n";
    if (chemicalSet.insert(Сysteine("Carbon", 6, "C")).second) {
        cout << "Successfully added a unique element!\n";
        cout << "======================================\n\n";
    }
    else {
        cout << "Failed to add a duplicate element.\n";
        cout << "======================================\n\n";
    }

    cout << "Chemical elements composing Cysteine:\n\n";
    for (const Сysteine& element : chemicalSet) {
        cout << element.GetName() << " (Symbol: " << element.GetSymbol() << ", Atomic Number: " << element.GetAtomicNumber() << ")\n\n";
    }

    cout << "Chemical formula of Cysteine: C3H7NO2S" << "\n\n";

}

