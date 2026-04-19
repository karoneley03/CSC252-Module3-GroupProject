#include <iostream>
#include <vector>
using namespace std;

// Base class
class Appointment
{
protected:
    string description;
    int year, month, day;

public:
    Appointment(string desc, int y, int m, int d)
    {
        description = desc;
        year = y;
        month = m;
        day = d;
    }

    virtual bool occurs_on(int y, int m, int d) = 0;

    string getDescription() const
    {
        return description;
    }

    virtual ~Appointment() {}
};

// Day class
class Day : public Appointment
{
public:
    Day(string desc, int y, int m, int d)
        : Appointment(desc, y, m, d) {
    }

    bool occurs_on(int y, int m, int d) override
    {
        return (y == year && m == month && d == day);
    }
};

// Monthly class
class Monthly : public Appointment
{
public:
    Monthly(string desc, int y, int m, int d)
        : Appointment(desc, y, m, d) {
    }

    bool occurs_on(int y, int m, int d) override
    {
        return (y == year && d == day); // follow assignment rule
    }
};

int main()
{
    vector<Appointment*> appts;

    appts.push_back(new Day("Dentist", 2026, 4, 20));
    appts.push_back(new Monthly("Pay bills", 2026, 4, 15));
    appts.push_back(new Day("Meeting", 2026, 4, 20));
    appts.push_back(new Monthly("Gym membership", 2026, 4, 10));

    int y, m, d;
    cout << "Enter date (year month day): ";
    cin >> y >> m >> d;

    cout << "\nAppointments on that date:\n";

    for (auto a : appts)
    {
        if (a->occurs_on(y, m, d))
        {
            cout << a->getDescription() << endl;
        }
    }

    // cleanup
    for (auto a : appts)
        delete a;

    return 0;
}