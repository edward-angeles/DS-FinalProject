#ifndef FINAL_PROJECT_SORTEDLINKEDLIST_H
#define FINAL_PROJECT_SORTEDLINKEDLIST_H

#include "Node.h"
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
#include <stdexcept>


bool operator==(const Date& lhs, const Date& rhs);
bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);


class SortedLinkedList {
private:
    constexpr static const auto TITLE = "title";
    constexpr static const auto AUTHOR = "author";
    constexpr static const auto RATING = "rating";
    constexpr static const auto GENRE = "genre";
    constexpr static const auto REVIEW = "reviews";
    constexpr static const auto AVAILABILITY = "availability";
    constexpr static const auto DATE = "date";

    Node *head;
    int length;
    std::vector<Book*> books;
    std::string key;

    std::variant<std::string, double, int, Date> GetBookKey(Book* book);
    void SortLinkedList();
    Node* CreateNode(Book* book);

public:
    SortedLinkedList(Book* books[], char* key, int length);
    ~SortedLinkedList();

    void InsertSorted(Book* book);
    const Book* RemoveByIndex(int index);
    const Book* GetElementByIndex(int index) const;
    std::vector<Book*> GetSortedBooks() const;

};

#endif //FINAL_PROJECT_SORTEDLINKEDLIST_H
