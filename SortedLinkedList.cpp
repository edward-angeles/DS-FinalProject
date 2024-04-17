#include "SortedLinkedList.h"

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetDay() < rhs.GetDay();
}

bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

bool operator<=(const Date& lhs, const Date& rhs) {
    return lhs < rhs || lhs == rhs;
}




SortedLinkedList::SortedLinkedList(Book* books[], std::string& key, int length): key(key), length(length) {
    head = nullptr;
    for (auto i = 0; i < length; i++) {
        this->books.push_back(books[i]);
    }
    SortLinkedList();
}


std::variant<std::string, double, int, Date> SortedLinkedList::GetBookKey(Book* book) {
    if (key == TITLE) {
        return book->GetTitle();
    }
    else if (key == AUTHOR) {
        return book->GetAuthor();
    }
    else if (key == RATING) {
        return book->GetRating();
    }
    else if (key == REVIEW) {
        return book->GetTotalReviews();
    }
    else if (key == GENRE) {
        return book->GetGenre();
    }
    else if (key == DATE) {
        return book->GetPublicationDate();
    }
    else if (key == AVAILABILITY) {
        return book->GetAvailability();
    } else {
        return nullptr;
    }
}


void SortedLinkedList::SortLinkedList() {
    for (auto book: books) {
        InsertSorted(book);
    }
}


Node* SortedLinkedList::CreateNode(Book* book) {
    auto node = new Node(book, nullptr);
    return node;
}


void SortedLinkedList::InsertSorted(Book* book) {
    auto node = CreateNode(book);
    auto current = head;
    if (head == nullptr) {
        head = node;
        return;
    }

    if (head->next == nullptr) {
        auto current_key = GetBookKey(current->val);
        auto node_key = GetBookKey(node->val);
        if (current_key <= node_key) {
            head->next = node;
            return;
        }
        node->next = head;
        head = node;
        return;
        }

    while (current->next) {
        auto current_key = GetBookKey(current->val);
        auto current_next_key = GetBookKey(current->next->val);
        auto node_key = GetBookKey(node->val);
        if (current_key <= node_key &&node_key<current_next_key) {
            node->next = current->next;
            current->next = node;
            return;
        }
    }
    current->next = node;
    return;
}

const Book* SortedLinkedList::RemoveByIndex(int index) {
    auto* current = head;
    int current_index = 1;
    if (index == current_index) {
        auto tmp = head;
        delete head;
        head = tmp->next;
        return tmp->val;
    }
    if (index == length) {
        while (current_index != length-1) {
            current = current->next;
            current_index++;
        }
        auto tmp = current->next;
        delete current->next;
        current->next = nullptr;
        return tmp->val;
    }
    while (current) {
        if (current_index+1 == index) {
            auto tmp = current->next;
            delete current->next;
            current->next = tmp->next;
            return tmp->val;
        }
    }
}

const Book* SortedLinkedList::GetElementByIndex(int index) const {
    auto* current = head;
    int current_index = 1;
    while (current) {
        if (current_index == index) {
            return current->val;
        }
        current = current->next;
        current_index++;
    }
    return nullptr;
}

std::vector<Book*> SortedLinkedList::GetSortedBooks() const {
    std::vector<Book*> books;
    for (auto current = head; current != nullptr; current = current->next) {
        books.push_back(current->val);
    }
    return books;
};