/*
The Interface Segregation Principle (ISP), a core principle of object-oriented 
design, states that clients should not be forced to depend on methods they do 
not use, advocating for creating multiple, smaller, specific interfaces instead 
of one large, general-purpose interface
*/

#include <iostream>
#include <string> 

// A 'Readable' interface
class Readable {
    virtual void open() = 0; 
    virtual void close() = 0; 
    virtual void read() = 0; 
    virtual void bookmark() = 0; 
}; 

// We are creating another interface called 'Searchable' 
// because the pure virtual functions may not be applicable 
// to all objects. So we are inheriting Readable and adding the 
// search function. We are sort of segregating/dividing the functions 
// among multiple interfaces. 
class Searchable : public Readable {
    virtual void search() = 0; 
}; 

// For a paperback, the search() function need not be applicable. 
// Therefore, the paperback class only inherits from or implements 
// the Readable class. 
class Paperback : public Readable {
    public: 
        void open() override {
            std::cout << "Opening the paperback\n"; 
        }

        void close() override {
            std::cout << "Closing the paperback\n"; 
        }

        void read() override {
            std::cout << "Reading the paperback\n"; 
        }

        void bookmark() override {
            std::cout << "Bookmarking the paperback\n"; 
        }

}; 

// However, for an audiobook, the search() function might be
// applicable. Therefore, Audiobook class inherits from the
// Searchable interface which has all functions in Readable plus 
// the search() functions. 
class Audiobook : public Searchable {
    public: 
        void open() override
        {
            std::cout << "Opening the audiobook\n";
        }

        void close() override
        {
            std::cout << "Closing the audiobook\n";
        }

        void read() override
        {
            std::cout << "Reading the audiobook\n";
        }

        void bookmark() override
        {
            std::cout << "Bookmarking the audiobook\n";
        }

        void search() override
        {
            std::cout << "Searching the audiobook\n";
        }
}; 

int main() {

    Audiobook ab; 
    ab.search(); 

}
