#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    int quantity;

public:
    Book(int id, string t, string a, int q) {
        bookID = id;
        title = t;
        author = a;
        quantity = q;
    }

    int getID() const {
        return bookID;
    }

    void display() const {
        cout << "ID: " << bookID 
             << " | Title: " << title 
             << " | Author: " << author 
             << " | Quantity: " << quantity << endl;
    }

    void update(string t, string a, int q) {
        title = t;
        author = a;
        quantity = q;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id, qty;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Quantity: ";
        cin >> qty;

        books.push_back(Book(id, title, author, qty));
        cout << "Book added successfully!\n";
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }

        cout << "\n=== Book List ===\n";
        for (const auto& book : books) {
            book.display();
        }
    }

    void searchBook() const {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        bool found = false;
        for (const auto& book : books) {
            if (book.getID() == id) {
                book.display();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Book not found.\n";
    }

    void updateBook() {
        int id;
        cout << "Enter Book ID to update: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getID() == id) {
                string title, author;
                int qty;
                cin.ignore();
                cout << "Enter New Title: ";
                getline(cin, title);
                cout << "Enter New Author: ";
                getline(cin, author);
                cout << "Enter New Quantity: ";
                cin >> qty;
                book.update(title, author, qty);
                cout << "Book updated successfully!\n";
                return;
            }
        }

        cout << "Book not found.\n";
    }

    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getID() == id) {
                books.erase(it);
                cout << "Book deleted successfully!\n";
                return;
            }
        }

        cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: lib.updateBook(); break;
            case 5: lib.deleteBook(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
