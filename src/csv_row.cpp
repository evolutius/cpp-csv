#include "csv_row.h"

evoluti::csv_row::csv_row(const std::vector<std::string>& items) : items(items) {
}

std::vector<std::string> evoluti::csv_row::get_items() const {
    return items;
}

std::string evoluti::csv_row::get_item_at(std::size_t i) const {
    return items[i];
}

std::string evoluti::csv_row::get_first_item(std::size_t i) const {
    return items.front();
}

std::string evoluti::csv_row::get_last_item(std::size_t i) const {
    return items.back();
}

std::size_t evoluti::csv_row::num_columns() const {
    return items.size();
}

std::vector<std::string>::iterator evoluti::csv_row::begin() {
    return items.begin();
}

std::vector<std::string>::const_iterator evoluti::csv_row::begin() const {
    return items.begin();
}

std::vector<std::string>::const_iterator evoluti::csv_row::cbegin() const {
    return items.cbegin();
}

std::vector<std::string>::iterator evoluti::csv_row::end() {
    return items.end();
}

std::vector<std::string>::const_iterator evoluti::csv_row::end() const {
    return items.end();
}

std::vector<std::string>::const_iterator evoluti::csv_row::cend() const {
    return items.cend();
}

void evoluti::csv_row::set_items(const std::vector<std::string>& its) {
    items = its;
}

void evoluti::csv_row::append_item(const std::string& item) {
    items.push_back(item);
}

void evoluti::csv_row::prepend_item(const std::string& item) {
    items.insert(items.begin(), item);
}

void evoluti::csv_row::remove_at(std::size_t i) {
    items.erase(items.begin() + i);
}

void evoluti::csv_row::add_at(std::size_t i, const std::string& item) {
    items.insert(items.begin() + i, item);
}
