#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

class Book {
public:
    Book(const string& title, const string& author)
        : title(title), author(author), isBorrowed(false) {}

    virtual ~Book() {}

    virtual void display() const {
        cout << "Tytul: " << title << ", Autor: " << author << ", Status: "
            << (isBorrowed ? "Wypozyczona" : "Dostepna") << endl;
    }

    const string& getTitle() const { return title; }
    bool getStatus() const { return isBorrowed; }
    void borrow() { isBorrowed = true; }
    void returnBook() { isBorrowed = false; }

private:
    string title;
    string author;
    bool isBorrowed;
};


class TextBook : public Book {
public:
    TextBook(const string& title, const string& author, const string& subject)
        : Book(title, author), subject(subject) {}
private:
    string subject;
};

class Library {
public:
    void addBook(shared_ptr<Book> book) {
        books[book->getTitle()] = book;
    }

    void removeBook(const string& title) {
        books.erase(title);
    }

    void borrowBook(const string& title) {
        auto it = books.find(title);
        if (it != books.end() && !it->second->getStatus()) {
            it->second->borrow();
            cout << "Ksiazka " << title << " zostala wypozyczona." << endl;
        }
        else {
            cout << "Ksiazka " << title << " jest niedostepna." << endl;
        }
    }

    void returnBook(const string& title) {
        auto it = books.find(title);
        if (it != books.end() && it->second->getStatus()) {
            it->second->returnBook();
            cout << "Ksiazka " << title << " zostala zwrocona." << endl;
        }
        else {
            cout << "Ksiazka " << title << " nie byla wypozyczona." << endl;
        }
    }

    void displayStatus() const {
        for (const auto& pair : books) {
            pair.second->display();
        }
    }

private:
    unordered_map<string, shared_ptr<Book>> books;
};

int main() {
    Library library;
    int choice;

    library.addBook(make_shared<Book>("C++ Programming", "Bjarne Stroustrup"));
    library.addBook(make_shared<TextBook>("Mathematics", "John Doe", "Mathematics"));
    library.addBook(make_shared<Book>("Clean Code", "Robert C. Martin"));

    do {
        cout << "\n=== Biblioteka Szkolna ===" << endl;
        cout << "1. Dodaj ksiazke" << endl;
        cout << "2. Usun ksiazke" << endl;
        cout << "3. Wypozycz ksiazke" << endl;
        cout << "4. Zwroc ksiazke" << endl;
        cout << "5. Wyswietl stan biblioteki" << endl;
        cout << "0. Zakoncz" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string title, author, subject;
        string isTextBook;
        switch (choice) {
        case 1:
            cout << "Dodawanie ksiazki..." << endl;
            cout << "Podaj tytul: ";
            getline(cin, title);
            cout << "Podaj autora: ";
            getline(cin, author);
            cout << "Czy to jest podrecznik? (tak/nie): ";
            getline(cin, isTextBook);
            if (isTextBook == "tak") {
                cout << "Podaj przedmiot: ";
                getline(cin, subject);
                library.addBook(make_shared<TextBook>(title, author, subject));
            }
            else {
                library.addBook(make_shared<Book>(title, author));
            }
            cout << "Ksiazka zostala dodana." << endl;
            break;
        case 2:
            cout << "Usuwanie ksiazki..." << endl;
            cout << "Podaj tytul: ";
            getline(cin, title);
            library.removeBook(title);
            cout << "Ksiazka zostala usunieta." << endl;
            break;
        case 3:
            cout << "Wypozyczanie ksiazki..." << endl;
            cout << "Podaj tytul: ";
            getline(cin, title);
            library.borrowBook(title);
            break;
        case 4:
            cout << "Zwracanie ksiazki..." << endl;
            cout << "Podaj tytul: ";
            getline(cin, title);
            library.returnBook(title);
            break;
        case 5:
            cout << "Stan biblioteki:" << endl;
            library.displayStatus();
            break;
        case 0:
            cout << "Zakonczenie programu." << endl;
            break;
        default:
            cout << "Nieprawidlowa opcja, sprobuj ponownie." << endl;

        }
    } while (choice != 0);
    return 0;
}
