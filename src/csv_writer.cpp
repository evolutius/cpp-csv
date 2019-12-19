#include "csv_writer.h"

#include <fstream>

#include "csv_container.h"
#include "csv_row.h"

evoluti::csv_writer::csv_writer(const std::string& fp, const csv_container& container)
    : filepath(fp), csv_data(container) {
}

void evoluti::csv_writer::set_filepath(const std::string& fp) {
    filepath = fp;
}

void evoluti::csv_writer::set_container(const csv_container& container) {
    csv_data = container;
}

std::string evoluti::csv_writer::get_filepath() const {
    return filepath;
}

void evoluti::csv_writer::save() {
    std::ofstream csv_file(filepath);
    std::string curr_line;

    if (!csv_file.is_open())
    {
        throw("Cannot open/create CSV file");
    }

    if (csv_data.has_header())
    {
        curr_line = build_line(csv_data.get_header());
        csv_file << curr_line << std::endl;
    }

    for (auto& row : csv_data)
    {
        curr_line = build_line(row);
        csv_file << curr_line << std::endl;
    }

    csv_file.close();
}

std::string evoluti::csv_writer::build_line(const evoluti::csv_row& row) const {
    std::string line;

    for (auto& field : row.get_items())
    {
        line += field + ",";
    }

    line.pop_back();  // remove additional "," at the end

    return line;
}