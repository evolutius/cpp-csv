#ifndef _E_CSV_CONTAINER_H_
#define _E_CSV_CONTAINER_H_

#include <string>
#include <vector>

#include "csv_row.h"

namespace evoluti {
class csv_container {
public:
    csv_container() = default;
    csv_container(const csv_row& hdr, const std::vector<csv_row>& dat);

    /* Const getters */
    bool has_header() const;
    csv_row get_header() const;
    std::vector<csv_row> get_rows() const;
    csv_row get_row_at(std::size_t i) const;

    /* Iterators */
    std::vector<csv_row>::iterator begin();
    std::vector<csv_row>::const_iterator begin() const;
    std::vector<csv_row>::iterator end();
    std::vector<csv_row>::const_iterator end() const;
    std::vector<csv_row>::const_iterator cbegin() const;
    std::vector<csv_row>::const_iterator cend() const;

    /* Modifiers */
    void set_header(const csv_row& hdr);
    void set_rows(const std::vector<csv_row>& rows);
    void add_row(const csv_row& row);
    void insert_row(std::size_t i, const csv_row& row);
    void remove_row_at(std::size_t i);

private:
    csv_row header;  // optional
    std::vector<csv_row> data;
};
}  // namespace evoluti

#endif /* _E_CSV_CONTAINER_H */