#include <iostream>
using namespace std;

class Book {
private:
    bool isIssued = false;

protected:
    int bookID;
    string title, author;

public:
    void addBook(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
    }

    void viewBookDetails() {
        cout << "\n============================\n";
        cout << "Book ID: " << bookID << "\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Available: " << (isIssued ? "No" : "Yes") << "\n";
        cout << "============================\n";
    }

    int getBookId() {
        return bookID;
    }

    void flipAvailability() {
        isIssued = !isIssued;
    }

    bool isBookIssued() {
        return isIssued;
    }
};

class IssuedBook : public Book {
private:
    string issuedTo = "Not Issued";
    int issueDate = 0;
    int dueDate = 0;
    int finePerDay = 10;

public:
    void issueBook(string name, int issueD, int dueD) {
        issuedTo = name;
        issueDate = issueD;
        dueDate = dueD;
        flipAvailability();
    }

    void returnBook(int returnDate) {
        if (returnDate > dueDate) {
            int fine = (returnDate - dueDate) * finePerDay;
            cout << "Late return! Fine: Rs. " << fine << "\n";
        } else {
            cout << "Book returned on time. No fine.\n";
        }

        issuedTo = "Not Issued";
        issueDate = 0;
        dueDate = 0;
        flipAvailability();
    }

    void getBorrowerDetails() {
        cout << "\n--- Borrower Details ---\n";
        cout << "Name: " << issuedTo << "\n";
        cout << "Issue Date: " << issueDate << "\n";
        cout << "Due Date: " << dueDate << "\n";
        cout << "Book ID: " << bookID << "\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "-------------------------\n";
    }
};

int main() {
    const int librarySize = 2;
    IssuedBook library[librarySize];
    int bookCount = 0;
    int choice;

    do {
        cout << "\n======= Library Menu =======\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. View All Books\n";
        cout << "5. View Borrower Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        cout << "============================\n";

        switch (choice) {
            case 1: {
                if (bookCount >= librarySize) {
                    cout << "Library is full! Cannot add more books.\n";
                    break;
                }
                int id;
                string title, author;

                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);

                library[bookCount].addBook(id, title, author);
                bookCount++;

                cout << "Book added successfully.\n";
                break;
            }

            case 2: {
                int id, issueDate, dueDate;
                string name;
                bool found = false;

                cout << "Enter Book ID to issue: ";
                cin >> id;
                cin.ignore();

                for (int i = 0; i < bookCount; i++) {
                    if (library[i].getBookId() == id) {
                        found = true;

                        if (library[i].isBookIssued()) {
                            cout << "Book is already issued.\n";
                        } else {
                            cout << "Enter Borrower's Name: ";
                            getline(cin, name);
                            cout << "Enter Issue Date: ";
                            cin >> issueDate;
                            cout << "Enter Due Date: ";
                            cin >> dueDate;

                            library[i].issueBook(name, issueDate, dueDate);
                            cout << "Book issued successfully.\n";
                        }
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 3: {
                int id, returnDate;
                bool found = false;

                cout << "Enter Book ID to return: ";
                cin >> id;

                for (int i = 0; i < bookCount; i++) {
                    if (library[i].getBookId() == id) {
                        found = true;

                        if (!library[i].isBookIssued()) {
                            cout << "This book is not currently issued.\n";
                        } else {
                            cout << "Enter Return Date: ";
                            cin >> returnDate;
                            library[i].returnBook(returnDate);
                        }
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 4: {
                for (int i = 0; i < bookCount; i++) {
                    library[i].viewBookDetails();
                }
                break;
            }

            case 5: {
                int id;
                bool found = false;

                cout << "Enter Book ID to view borrower: ";
                cin >> id;

                for (int i = 0; i < bookCount; i++) {
                    if (library[i].getBookId() == id) {
                        library[i].getBorrowerDetails();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 6:
                cout << "Thank you for using the Library System!\n";
                break;

            default:
                cout << "Invalid choice. Please select from 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}
