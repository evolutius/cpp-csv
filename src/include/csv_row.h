#ifndef _E_CSV_ROW_H_
#define _E_CSV_ROW_H_

#include <string>
#include <vector>

namespace evoluti {
class csv_row {
public:
    csv_row() = default;
    csv_row(const std::vector<std::string>& items);

    /* Const getters */
    std::vector<std::string> get_items() const;
    std::string get_item_at(std::size_t i) const;
    std::string get_first_item(std::size_t i) const;
    std::string get_last_item(std::size_t i) const;
    std::size_t num_columns() const;

    /* Iterators */
    std::vector<std::string>::iterator begin();
    std::vector<std::string>::const_iterator begin() const;
    std::vector<std::string>::const_iterator cbegin() const;
    std::vector<std::string>::iterator end();
    std::vector<std::string>::const_iterator end() const;
    std::vector<std::string>::const_iterator cend() const;

    /* Modifiers */
    void set_items(const std::vector<std::string>& its);

    void append_item(const std::string& item);
    void prepend_item(const std::string& item);
    void remove_at(std::size_t i);
    void add_at(std::size_t i, const std::string& item);

private:
    std::vector<std::string> items;
};
}  // namespace evoluti

#endif /* _E_CSV_ROW_H_ */