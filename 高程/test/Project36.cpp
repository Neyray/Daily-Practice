#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 日期类
class Date {
private:
    int year, month, day;
public:
    Date(int y = 2024, int m = 1, int d = 1)
        : year(y), month(m), day(d) {
    }

    void display() const {
        cout << year << "-" << month << "-" << day;
    }

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    friend ostream& operator<<(ostream& os, const Date& d) {
        os << d.year << "-" << d.month << "-" << d.day;
        return os;
    }
};

// 抽象基类：图书
class Book {
protected:
    string isbn;
    string title;
    string author;
    double price;
    bool available;

public:
    Book(string i, string t, string a, double p)
        : isbn(i), title(t), author(a), price(p), available(true) {
    }

    virtual ~Book() {}

    // 纯虚函数
    virtual void display() const = 0;
    virtual double calculateLateFee(int daysLate) const = 0;
    virtual string getType() const = 0;

    // 普通成员函数
    void borrow() { available = false; }
    void returnBook() { available = true; }

    bool isAvailable() const { return available; }
    string getISBN() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }
};

// 派生类：普通图书
class RegularBook : public Book {
public:
    RegularBook(string i, string t, string a, double p)
        : Book(i, t, a, p) {
    }

    void display() const override {
        cout << "[Regular Book]" << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Status: " << (available ? "Available" : "Borrowed") << endl;
    }

    double calculateLateFee(int daysLate) const override {
        return daysLate * 0.5;  // $0.5 per day
    }

    string getType() const override {
        return "Regular";
    }
};

// 派生类：参考书
class ReferenceBook : public Book {
public:
    ReferenceBook(string i, string t, string a, double p)
        : Book(i, t, a, p) {
    }

    void display() const override {
        cout << "[Reference Book]" << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Status: " << (available ? "Available" : "In Use") << endl;
    }

    double calculateLateFee(int daysLate) const override {
        return daysLate * 1.0;  // $1.0 per day (higher)
    }

    string getType() const override {
        return "Reference";
    }
};

// 借阅记录
struct BorrowRecord {
    string isbn;
    string borrower;
    Date borrowDate;
    Date dueDate;
    bool returned;

    BorrowRecord(string i, string b, Date bd, Date dd)
        : isbn(i), borrower(b), borrowDate(bd), dueDate(dd), returned(false) {
    }

    void display() const {
        cout << "ISBN: " << isbn << endl;
        cout << "Borrower: " << borrower << endl;
        cout << "Borrow Date: " << borrowDate << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Status: " << (returned ? "Returned" : "Not Returned") << endl;
    }
};

// 图书馆类
class Library {
private:
    vector<Book*> books;
    vector<BorrowRecord> records;

public:
    ~Library() {
        for (auto book : books) {
            delete book;
        }
    }

    // 添加图书
    void addBook(Book* book) {
        books.push_back(book);
        cout << "Book added successfully!" << endl;
    }

    // 查找图书
    Book* findBook(const string& isbn) {
        for (auto book : books) {
            if (book->getISBN() == isbn) {
                return book;
            }
        }
        return nullptr;
    }

    // 借书
    bool borrowBook(const string& isbn, const string& borrower) {
        Book* book = findBook(isbn);
        if (!book) {
            cout << "Book not found!" << endl;
            return false;
        }

        if (!book->isAvailable()) {
            cout << "Book is not available!" << endl;
            return false;
        }

        book->borrow();
        Date today(2024, 1, 15);
        Date due(2024, 2, 15);
        records.push_back(BorrowRecord(isbn, borrower, today, due));

        cout << "Book borrowed successfully!" << endl;
        return true;
    }

    // 还书
    bool returnBook(const string& isbn) {
        Book* book = findBook(isbn);
        if (!book) {
            cout << "Book not found!" << endl;
            return false;
        }

        book->returnBook();

        // 更新记录
        for (auto& record : records) {
            if (record.isbn == isbn && !record.returned) {
                record.returned = true;
                break;
            }
        }

        cout << "Book returned successfully!" << endl;
        return true;
    }

    // 显示所有图书
    void displayAllBooks() const {
        cout << "\n=== All Books ===" << endl;
        for (size_t i = 0; i < books.size(); i++) {
            cout << "\nBook " << (i + 1) << ":" << endl;
            books[i]->display();
            cout << "-------------------" << endl;
        }
    }

    // 显示可借图书
    void displayAvailableBooks() const {
        cout << "\n=== Available Books ===" << endl;
        int count = 0;
        for (auto book : books) {
            if (book->isAvailable()) {
                book->display();
                cout << "-------------------" << endl;
                count++;
            }
        }
        if (count == 0) {
            cout << "No available books." << endl;
        }
    }

    // 按作者查找
    void searchByAuthor(const string& author) const {
        cout << "\n=== Books by " << author << " ===" << endl;
        int count = 0;
        for (auto book : books) {
            if (book->getAuthor() == author) {
                book->display();
                cout << "-------------------" << endl;
                count++;
            }
        }
        if (count == 0) {
            cout << "No books found by this author." << endl;
        }
    }

    // 显示借阅记录
    void displayBorrowRecords() const {
        cout << "\n=== Borrow Records ===" << endl;
        for (size_t i = 0; i < records.size(); i++) {
            cout << "\nRecord " << (i + 1) << ":" << endl;
            records[i].display();
            cout << "-------------------" << endl;
        }
    }

    // 统计信息
    void showStatistics() const {
        int totalBooks = books.size();
        int availableBooks = 0;
        int regularBooks = 0;
        int referenceBooks = 0;

        for (auto book : books) {
            if (book->isAvailable()) availableBooks++;
            if (book->getType() == "Regular") regularBooks++;
            else if (book->getType() == "Reference") referenceBooks++;
        }

        cout << "\n=== Library Statistics ===" << endl;
        cout << "Total Books: " << totalBooks << endl;
        cout << "Available: " << availableBooks << endl;
        cout << "Borrowed: " << (totalBooks - availableBooks) << endl;
        cout << "Regular Books: " << regularBooks << endl;
        cout << "Reference Books: " << referenceBooks << endl;
        cout << "Total Records: " << records.size() << endl;
    }
};

int main() {
    Library library;

    // 添加图书
    cout << "=== Adding Books ===" << endl;
    library.addBook(new RegularBook("001", "C++ Primer", "Stanley Lippman", 59.99));
    library.addBook(new RegularBook("002", "Effective C++", "Scott Meyers", 49.99));
    library.addBook(new ReferenceBook("003", "C++ Reference Manual", "Bjarne Stroustrup", 89.99));
    library.addBook(new RegularBook("004", "The C++ Programming Language", "Bjarne Stroustrup", 79.99));

    // 显示所有图书
    library.displayAllBooks();

    // 借书
    cout << "\n=== Borrowing Books ===" << endl;
    library.borrowBook("001", "Alice");
    library.borrowBook("003", "Bob");

    // 显示可借图书
    library.displayAvailableBooks();

    // 按作者查找
    library.searchByAuthor("Bjarne Stroustrup");

    // 还书
    cout << "\n=== Returning Books ===" << endl;
    library.returnBook("001");

    // 显示借阅记录
    library.displayBorrowRecords();

    // 统计信息
    library.showStatistics();

    return 0;
}