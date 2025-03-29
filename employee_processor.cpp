#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>
#include <tinyxml2.h>

using json = nlohmann::json;
using namespace tinyxml2;
using namespace std;

struct Employee {
    string name;
    int id;
    string department;
    double salary;
};

vector<Employee> employees;

void parseJson(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening JSON file" << endl;
        return;
    }
    json j;
    file >> j;
    for (const auto& emp : j["employees"]) {
        employees.push_back({emp["name"], emp["id"], emp["department"], emp["salary"]});
    }
}

void parseXml(const string& filename) {
    XMLDocument doc;
    if (doc.LoadFile(filename.c_str()) != XML_SUCCESS) {
        cerr << "Error opening XML file" << endl;
        return;
    }
    XMLElement* root = doc.FirstChildElement("employees");
    for (XMLElement* elem = root->FirstChildElement("employee"); elem; elem = elem->NextSiblingElement("employee")) {
        Employee emp;
        emp.name = elem->FirstChildElement("name")->GetText();
        emp.id = stoi(elem->FirstChildElement("id")->GetText());
        emp.department = elem->FirstChildElement("department")->GetText();
        emp.salary = stod(elem->FirstChildElement("salary")->GetText());
        employees.push_back(emp);
    }
}

double calculateAverageSalary() {
    double total = 0;
    for (const auto& emp : employees) {
        total += emp.salary;
    }
    return employees.empty() ? 0 : total / employees.size();
}

Employee findHighestPaid() {
    return *max_element(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.salary < b.salary;
    });
}

void sortEmployees() {
    sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.id < b.id;
    });
}

void displayResults() {
    cout << "Average Salary: " << calculateAverageSalary() << endl;
    Employee highest = findHighestPaid();
    cout << "Highest Paid Employee: " << highest.name << ", Salary: " << highest.salary << endl;
    cout << "Sorted Employee List by ID:" << endl;
    for (const auto& emp : employees) {
        cout << emp.id << " - " << emp.name << " - " << emp.department << " - " << emp.salary << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <file_type> <file_path>" << endl;
        return 1;
    }
    string fileType = argv[1];
    string filePath = argv[2];
    if (fileType == "json") {
        parseJson(filePath);
    } else if (fileType == "xml") {
        parseXml(filePath);
    } else {
        cerr << "Unsupported file type" << endl;
        return 1;
    }
    sortEmployees();
    displayResults();
    return 0;
}
