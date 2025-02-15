#include <iostream>
using namespace std;

int bookCount = 0,IDs = 1;
int bookId[10000];
string bookName[10000];
string bookAuthor[10000];
bool isAvailable[10000];

void addBook() {
    // id -> auto

    string name, author;

    cout << "Enter Book Name : ";
    cin >> name;
    cout << "Enter Book Author : ";
    cin >> author;

    //       [0]      = id = 1
    bookId[bookCount] = IDs++;
    bookName[bookCount] = name;
    bookAuthor[bookCount] = author;
    isAvailable[bookCount] = true;
    bookCount++;
    cout << "Added Book Successfully!" << endl;
}

int searchBook(int id) {
    int l = 0, r = bookCount - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (bookId[mid] == id)
            return mid;
        if (bookId[mid] > id)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

void removeBook(int id) {
    int idx = searchBook(id); // idx, -1

    if (searchBook(id) == -1) {
        cout << "Book Not Found!" << endl;
        return;
    }

    for (int i = idx; i < bookCount - 1; i++) {
        bookId[i] = bookId[i + 1];
        bookName[i] = bookName[i + 1];
        bookAuthor[i] = bookAuthor[i + 1];
        isAvailable[i] = isAvailable[i + 1];
    }
    bookCount--;
    cout << "Book Removed Successfully : ";
}

void updateBook(int id) {
    int idx = searchBook(id); // 0 1 2 3 4

    if (searchBook(id) == -1) {
        cout << "Book Not Found!" << endl;
        return;
    }

    string name, author;
    cout << "Enter Book Name : ";
    cin >> name;
    cout << "Enter Book Author : ";
    cin >> author;

    bookName[idx] = name;
    bookAuthor[idx] = author;
    cout << "Book Updated Successfully : ";
}

void borrowingBook(int id) {
    int idx = searchBook(id);
    if (searchBook(id) == -1) {
        cout << "Book Not Found!" << endl;
        return;
    }

    // if true  -> false
    // if false -> message
    if (isAvailable[idx] == true) {
        isAvailable[idx] = false;
        cout << "Book Borrowed Successfully : ";
    } else {
        cout << "Book Not Available!" << endl;
    }
}

void returningBook(int id) {
    int idx = searchBook(id);
    if (searchBook(id) == -1) {
        cout << "Book Not Found!" << endl;
        return;
    }

    // if false -> true
    // if true  -> message

    if (isAvailable[idx] == false) {
        isAvailable[idx] = true;
        cout << "Book Returned Successfully : ";
    } else {
        cout << "Book is Available already!" << endl;
    }
}

void display() {
    if (bookCount == 0) {
        cout << "No Books Available!" << endl;
        return;
    }

    cout << "================\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "Book Id : " << bookId[i] << endl;
        cout << "Book Name : " << bookName[i] << endl;
        cout << "Book Author : " << bookAuthor[i] << endl;
        cout << "Available : " << isAvailable[i] << endl; // 0 1
        cout << "================\n";
    }
}

void menu() {
    cout << "================" << endl;
    cout << "Choose an option : " << endl;

    cout << "1. Add Book" << endl;
    cout << "2. Update Book" << endl;
    cout << "3. Borrowing Book" << endl;
    cout << "4. Returning Book" << endl;
    cout << "5. Display Book" << endl;
    cout << "6. Search Book" << endl;
    cout << "7. Remove Book" << endl;
    cout << "8. Exit" << endl;

    cout << "Your Choice : ";
}

void maherplusplus() {
    cout << "\nWelcome To Maher PlusPlus Library!\n\n";

    while (true) {
        int option, id, idx;
        menu();
        cin >> option;

        switch (option) {
            case 1:
                addBook();
                break;
            case 2:
                cout << "Enter Book Id To Update: ";
                cin >> id;
                updateBook(id);
                break;
            case 3:
                cout << "Enter Book Id To Borrow : ";
                cin >> id;
                borrowingBook(id);
                break;
            case 4:
                cout << "Enter Book Id To Return : ";
                cin >> id;
                returningBook(id);
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Enter Book Id To Search : ";
                cin >> id;
                idx = searchBook(id);
                if(idx == -1) {
                    cout << "Book Not Found!" << endl;
                }
                else {
                    cout << "================\n";
                    cout << "Book Id : " << bookId[idx] << endl;
                    cout << "Book Name : " << bookName[idx] << endl;
                    cout << "Book Author : " << bookAuthor[idx] << endl;
                    cout << "Available : " << isAvailable[idx] << endl;
                    cout << "================\n";
                }
                break;
            case 7:
                cout << "Enter Book Id To Remove : ";
                cin >> id;
                removeBook(id);
                break;
            case 8:
                return;
            default:
                cout << "Invalid Option, Enter an Option: ";
        }
        cout << endl;
        cout << "Press any Key To Continue : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        // system("pause");
        // system("cls");
    }
}

int main() {
    maherplusplus();
}
