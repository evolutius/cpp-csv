
#include "csv_container.h"

#include <stdexcept>

#include "csv_row.h"

evoluti::csv_container::csv_container(const csv_row& hdr, const std::vector<csv_row>& dat) : header(hdr), data(dat) {
    if (dat.size() > 0 && hdr.size() > 0 && hdr.size() != dat[0].size())
    {
        throw std::logic_error("Number of columns in header not equal to number of columns in rows");
    }
}

bool evoluti::csv_container::has_header() const {
    return header.size() > 0;
}

csv_row evoluti::csv_container::get_header() const {
    return header;
}

std::vector<csv_row> evoluti::csv_container::get_rows() const {
    return data;
}

csv_row evoluti::csv_container::get_row_at(std::size_t i) const {
    return data[i];
}

std::vector<csv_row>::iterator evoluti::csv_container::begin() {
    return data.begin();
}

std::vector<csv_row>::const_iterator evoluti::csv_container::begin() const {
    return data.begin();
}

std::vector<csv_row>::iterator evoluti::csv_container::end() {
    return data.end();
}

std::vector<csv_row>::const_iterator evoluti::csv_container::end() const {
    return data.end();
}

std::vector<csv_row>::const_iterator evoluti::csv_container::cbegin() const {
    return data.cbegin();
}

std::vector<csv_row>::const_iterator evoluti::csv_container::cend() const {
    return data.cend();
}

void evoluti::csv_container::set_header(const csv_row& hdr) {
    header = hdr;
}

void evoluti::csv_container::set_rows(const std::vector<csv_row>& rows) {
    data = rows;
}

void evoluti::csv_container::add_row(const csv_row& row) {
    data.push_back(row);
}

void evoluti::csv_container::insert_row(std::size_t i, const csv_row& row) {
    data.insert(data.begin() + i, row);
}

void evoluti::csv_container::remove_row_at(std::size_t i) {
    data.erase(data.begin() + i);
}