#include <iostream>

class Data {
public:
    Data &add_year(int);
    Data &add_month(int);
    Data &add_day(int);

private:
    int d, m, y;
    static Data default_date;

};
