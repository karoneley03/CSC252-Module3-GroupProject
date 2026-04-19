#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    string phone;
    string email;

public:
    Person(string n, string p, string e)
    {
        name = n;
        phone = p;
        email = e;
    }

    virtual string toString() const
    {
        return "Person named " + name +
            " has phone number " + phone +
            " and can be reached at " + email;
    }

    virtual ~Person() {}
};

class Student : public Person
{
private:
    string year;

public:
    Student(string n, string p, string e, string y)
        : Person(n, p, e), year(y) {
    }

    string toString() const override
    {
        return Person::toString() + " is in the " + year + " year";
    }
};

class Employee : public Person
{
protected:
    double salary;

public:
    Employee(string n, string p, string e, double s)
        : Person(n, p, e), salary(s) {
    }

    string toString() const override
    {
        return Person::toString() +
            " earns " + std::to_string(salary) + " annually";
    }
};

class Faculty : public Employee
{
private:
    string title;

public:
    Faculty(string n, string p, string e, double s, string t)
        : Employee(n, p, e, s), title(t) {
    }

    string toString() const override
    {
        return Employee::toString() + " is a/an " + title;
    }
};

class Staff : public Employee
{
private:
    string role;

public:
    Staff(string n, string p, string e, double s, string r)
        : Employee(n, p, e, s), role(r) {
    }

    string toString() const override
    {
        return Employee::toString() + " handles " + role;
    }
};

int main()
{
    vector<Person*> people;

    people.push_back(new Person("Susan", "800-555-1212", "susan@quirkymail.com"));
    people.push_back(new Student("Jerry", "123-456-7890", "jerjer@nat.edu", "sophomore"));
    people.push_back(new Employee("Larry", "333-444-5555", "larry@threestooges.org", 123456));
    people.push_back(new Faculty("Linda", "987-654-3210", "lindalou@whoknew.edu", 150000, "adjunct professor"));
    people.push_back(new Staff("Jane", "567-123-6565", "jane@whizkid.com", 100000, "registration"));

    cout << "People List:\n\n";

    for (auto p : people)
    {
        cout << p->toString() << endl;
    }

    for (auto p : people)
        delete p;

    return 0;
}