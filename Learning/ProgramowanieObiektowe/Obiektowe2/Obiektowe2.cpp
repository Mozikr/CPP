#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {

    }

    int GetAge()
    {
        return m_age;
    }

protected:
    int m_age;
};
class Student : public Person
{
public:

    Student(int age, int indexNumber)
    {
        m_age = age;
        m_indexNumber = indexNumber;
    }



    int GetIndexNumber()
    {
        return m_indexNumber;
    }



protected:
    int m_indexNumber;
};



int main()
{
    //Student* student = new Student(20, 9001);
    /*Deklaruje wskaźnik student typu Student* .
    Dynamicznie alokuje pamięć dla obiektu Student na stercie.
    Inicjalizuje obiekt Student za pomocą konstruktora z argumentami(20, 2121).
    Przypisuje adres nowo utworzonego obiektu Student do wskaźnika student.*/

   // cout << "Age: " << student->GetAge() << endl << "Index number: " << student->GetIndexNumber();


}

