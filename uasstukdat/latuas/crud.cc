#include <iostream>
#include <mysql/mysql.h>
#include <sstream>
#include <string>

using namespace std;

const char* hostname = "127.0.0.1"; 
const char* user = "root";
const char* pass = "123";
const char* dbname = "crud_cpp";
unsigned int port = 31235; 
const char* unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL* connect_db() {
    MYSQL* conn = mysql_init(0);
    if (conn) {
        conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
        if (conn) {
            cout << "Connected to the database successfully." << endl;
        } else {
            cerr << "Connection failed: " << mysql_error(conn) << endl;
        }
    } else {
        cerr << "mysql_init failed" << endl;
    }
    return conn;
}

void add_book(const string& title, const string& author, int year) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "INSERT INTO perpustakaan (title, author, year) VALUES ('" << title << "', '" << author << "', " << year << ")";
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Book successfully added." << endl;
        }
        mysql_close(conn);
    }
}

void view_books() {
    MYSQL* conn = connect_db();
    if (conn) {
        if (mysql_query(conn, "SELECT * FROM perpustakaan")) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            cout << "ID: " << row[0] << ", Title: " << row[1] << ", Author: " << row[2] << ", Year: " << row[3] << endl;
        }

        mysql_free_result(res);
        mysql_close(conn);
    }
}

void update_book(int book_id, const string& title, const string& author, int year) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "UPDATE perpustakaan SET title = '" << title << "', author = '" << author << "', year = " << year << " WHERE id = " << book_id;
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "UPDATE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Book successfully updated." << endl;
        }
        mysql_close(conn);
    }
}

void delete_book(int book_id) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "DELETE FROM perpustakaan WHERE id = " << book_id;
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "DELETE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Book successfully deleted." << endl;
        }
        mysql_close(conn);
    }
}

void purchase_book(int book_id) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "UPDATE perpustakaan SET is_purchased = TRUE WHERE id = " << book_id;
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "UPDATE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Book successfully purchased." << endl;
        }
        mysql_close(conn);
    }
}

bool admin_login() {
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;
    
    // Simple hardcoded login for demonstration
    if (username == "admin" && password == "admin123") {
        return true;
    }
    return false;
}

void admin_menu() {
    int choice;
    while (true) {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Update Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string title, author;
            int year;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            add_book(title, author, year);
        } else if (choice == 2) {
            view_books();
        } else if (choice == 3) {
            int book_id;
            string title, author;
            int year;
            cout << "Enter book ID to update: ";
            cin >> book_id;
            cin.ignore();
            cout << "Enter new title: ";
            getline(cin, title);
            cout << "Enter new author: ";
            getline(cin, author);
            cout << "Enter new year: ";
            cin >> year;
            update_book(book_id, title, author, year);
        } else if (choice == 4) {
            int book_id;
            cout << "Enter book ID to delete: ";
            cin >> book_id;
            delete_book(book_id);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void user_menu() {
    int choice;
    while (true) {
        cout << "\nUser Menu:\n";
        cout << "1. View All Books\n";
        cout << "2. Purchase Book\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            view_books();
        } else if (choice == 2) {
            int book_id;
            cout << "Enter book ID to purchase: ";
            cin >> book_id;
            purchase_book(book_id);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    int userType;
    while (true) {
        cout << "\nWelcome:\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> userType;

        if (userType == 1) {
            if (admin_login()) {
                admin_menu();
            } else {
                cout << "Invalid admin credentials." << endl;
            }
        } else if (userType == 2) {
            user_menu();
        } else if (userType == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
