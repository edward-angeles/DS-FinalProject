#ifndef FINAL_PROJECT_SORTEDLINKEDLIST_H
#define FINAL_PROJECT_SORTEDLINKEDLIST_H

#include "Node.h"
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>


bool operator==(const Date& lhs, const Date& rhs);
bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);

class SortedLinkedList {
private:
    constexpr static const std::string TITLE = "title";
    constexpr static const std::string AUTHOR = "author";
    constexpr static const std::string RATING = "rating";
    constexpr static const std::string GENRE = "genre";
    constexpr static const std::string REVIEW = "reviews";
    constexpr static const std::string AVAILABILITY = "availability";
    constexpr static const std::string DATE = "date";

    Node *head;
    int length;
    std::vector<Book*> books;
    std::string key;

    std::variant<std::string, double, int, Date> GetBookKey(Book* book);
    void SortLinkedList();
    Node* CreateNode(Book* book);

public:
    SortedLinkedList(Book* books[], std::string& key, int length);



    void InsertSorted(Book* book);
    const Book* RemoveByIndex(int index);
    const Book* GetElementByIndex(int index) const;
    std::vector<Book*> GetSortedBooks() const;

};

#endif //FINAL_PROJECT_SORTEDLINKEDLIST_H
