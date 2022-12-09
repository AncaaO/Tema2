//
// Created by Anca on 11/27/2022.
//
#include "../headers/Library.h"

void Library::add_book(const Book& book){
    books.push_back(book);
}

std::vector<Book> Library::filter_by_genre(Genre genre) const {
    std::vector<Book> new_books;
    auto genre_match_fn = [genre](auto book) {
        return book.getGenre() == genre;
    };
    copy_if(begin(books), end(books), std::back_inserter(new_books), genre_match_fn);
    return new_books;
}

void Library::remove_book(const std::string& title){
    auto it = find(title);
    if(it != books.end()) books.erase(it);
    else std::cout << "Book not found!\n";
}

std::ostream& operator<<(std::ostream& os, const Library& library) {
    os << "Library - " << "Name: " << library.name  << "\n";
    for(const auto& book : library.books)
        os << "Book - " << book << "\n";
    return os;
}

Library::Library(const std::string& name_, const std::vector<Book>& books_) : name{name_}, books{books_} {}