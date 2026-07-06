#include <iostream>
#include <ctime>

using namespace std;

typedef time_t Date;

typedef enum _sex {
    male = 'm',
    female = 'f'
} Sex;

class Horse {
private:
    Sex    _sex;
    string _breed;
public:
    const char* getSpecies() const {
        return "horse";
    }
    const char getSex() const {
        return (char)_sex;
    }
    const char* getBreed() const {
        return _breed.c_str();
    }
    Horse() {}
    Horse(const char* breed, Sex sex ) {
        _breed  = breed;
        _sex  = sex;
    }
};

ostream& operator << (ostream& os, const Horse& horse) {
    os  << "Species:" << horse.getSpecies() << ", "
        << "Sex:"  << horse.getSex()  << ", "
        << "Breed:"  << horse.getBreed()  << endl;
    return os;
}


class Mating {
private:
    Horse _male;
    Horse _female;
    Date  _day;
public:
    Mating(Horse& male, Horse& female) {
        _male = male;
        _female = female;
        time(&_day);
    }
    friend ostream& operator << (ostream& os, const Mating& mating) {
        os << "DATE: "    << asctime(localtime(&mating._day))
           << "MALE: " << mating._male
           << "FEMALE: " << mating._female
           << endl;
           return os;
     };
};

int main()
{
    Horse stallion("Lipizzaner", male);
    Horse mare("Maremmano", female);
    Mating mating(stallion, mare);
    cout << mating << endl;
    return 0;
}
