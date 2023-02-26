#include <iostream>
#include <string>

class Employee {
public:
    Employee(const std::string& name, const std::string& id, double salary)
        : name_(name), id_(id), salary_(salary) {}

    virtual void raiseSalary(double amount) {
        salary_ += amount;
    }

    virtual void transfer(const std::string& department) {
        std::cout << name_ << " has been transferred to the " << department << " department." << std::endl;
    }

    virtual void promote() {
        std::cout << name_ << " has been promoted!" << std::endl;
    }

protected:
    std::string name_;
    std::string id_;
    double salary_;
};

class Manager : public Employee {
public:
    Manager(const std::string& name, const std::string& id, double salary, const std::string& department)
        : Employee(name, id, salary), department_(department) {}

    virtual void transfer(const std::string& department) override {
        std::cout << name_ << " has been transferred from the " << department_ << " department to the " << department << " department." << std::endl;
        department_ = department;
    }

    virtual void promote() override {
        std::cout << name_ << " has been promoted to senior manager!" << std::endl;
        salary_ *= 1.1; // 10% salary increase for promotion
    }

private:
    std::string department_;
};

class Engineer : public Employee {
public:
    Engineer(const std::string& name, const std::string& id, double salary, const std::string& specialization)
        : Employee(name, id, salary), specialization_(specialization) {}

    virtual void raiseSalary(double amount) override {
        std::cout << name_ << " has received a raise of " << amount << " dollars!" << std::endl;
        salary_ += amount;
        if (salary_ > 100000) {
            std::cout << "Warning: " << name_ << " has exceeded the maximum salary limit for engineers!" << std::endl;
        }
    }

    virtual void promote() override {
        std::cout << name_ << " has been promoted to lead engineer!" << std::endl;
        salary_ *= 1.15; // 15% salary increase for promotion
    }

private:
    std::string specialization_;
};

int main() {
    // Create some employees
    Employee* emp1 = new Manager("John", "12345", 50000.0, "Marketing");
    Employee* emp2 = new Engineer("Alice", "67890", 80000.0, "Software");

    // Use the base class functions
    emp1->raiseSalary(10000.0);
    emp1->transfer("Sales");
    emp2->raiseSalary(15000.0);
    emp2->promote();

    // Use the derived class functions
    Manager* mgr = dynamic_cast<Manager*>(emp1);
    if (mgr != nullptr) {
        mgr->promote();
    }
    Engineer* eng = dynamic_cast<Engineer*>(emp2);
    if (eng != nullptr) {
        eng->raiseSalary(20000.0);
    }

    // Delete the employees to avoid memory leaks
    delete emp1;
    delete emp2;

    return 0;
}
