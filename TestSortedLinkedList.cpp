#include "Book.h"
#include "SortedLinkedList.h"
#include <iostream>

int main() {
    auto book1 = new Book("title1", "author1", "genre1", 1, 1, 2000, 10, 100, 8.5);
    auto book2 = new Book("title2", "author2", "genre2", 2, 2, 2000, 20, 100, 8.5);
    auto book3 = new Book("title3", "author3", "genre3", 2, 2, 2000, 20, 100, 8.5);

    Book* array[] = {book1, book2, book3};
    std::string key = "title";
    auto sortedBooksObj = SortedLinkedList(array, key, 3);
    auto sortedBooks = sortedBooksObj.GetSortedBooks();
    for (auto book: sortedBooks) {
        std::cout << book->GetTitle() << " " << book->GetAuthor() << " " << book->GetGenre() << " " << book->GetPublicationDate().GetYear() << " " << book->GetTotalReviews() << " " << book->GetRating();
    }
    return 0;
}