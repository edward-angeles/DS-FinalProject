#include "Book.h"
#include "SortedLinkedList.h"
#include <iostream>

int main() {
    auto book1 = new Book("ttitle1", "author1", "genre1", 1, 1, 2000, 10, 100, 8.5);
    auto book2 = new Book("itle2", "author2", "genre2", 2, 2, 2010, 40, 100, 8.5);
    auto book3 = new Book("atitle3", "author3", "genre3", 2, 2, 2001, 30, 100, 8.5);
    auto book4 = new Book("atitle4", "author4", "genre4", 2, 2, 2001, 20, 100, 8.5);
    Book* array[] = {book1, book2, book3, book4};
    std::string key = "availability";

    std::cout<<"First\n";

    auto sortedBooksObj = SortedLinkedList(array, key, 4);

    std::cout<<"First\n";
    auto sortedBooks = sortedBooksObj.GetSortedBooks();
    for (auto book: sortedBooks) {
        std::cout << book->GetTitle() << " " << book->GetAuthor() << " " << book->GetGenre() << " " << book->GetPublicationDate().GetYear() << " " << book->GetTotalReviews() << " " << book->GetRating() << " " << book->GetAvailability();
        std::cout << "\n";
    }
    std::cout << std::endl;

    std::cout << sortedBooksObj.GetElementByIndex(2)->GetTitle() << std::endl;
    sortedBooks = sortedBooksObj.GetSortedBooks();
    for (auto book: sortedBooks) {
        std::cout << book->GetTitle() << " " << book->GetAuthor() << " " << book->GetGenre() << " " << book->GetPublicationDate().GetYear() << " " << book->GetTotalReviews() << " " << book->GetRating() << " " << book->GetAvailability();
        std::cout << "\n";
    }
    std::cout << std::endl;

    std::cout << sortedBooksObj.RemoveByIndex(1)->GetTitle() << std::endl;
    sortedBooks = sortedBooksObj.GetSortedBooks();
    for (auto book: sortedBooks) {
        std::cout << book->GetTitle() << " " << book->GetAuthor() << " " << book->GetGenre() << " " << book->GetPublicationDate().GetYear() << " " << book->GetTotalReviews() << " " << book->GetRating() << " " << book->GetAvailability();
        std::cout << "\n";
    }
    std::cout << std::endl;

    return 0;
}