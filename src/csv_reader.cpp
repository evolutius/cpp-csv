#include "csv_reader.h"

#include <ifstream>
#include <limits>
#include <stdexcept>

#include "csv_container.h"
#include "csv_row.h"

evoluti::csv_reader::csv_reader(const std::string& fp, bool parse_headers)
    : filepath(fp), parsing_headers(parse_headers) {
    if (fp.compare(fp.size() - 4, 4, ".csv") != 0 && fp.compare(fp.size() - 4, 4, ".CSV") != 0)
    {
        throw std::logic_error("Invalid file extension (expected CSV)");
    }
}

void evoluti::csv_reader::set_filepath(const std::string& fp) {
    if (fp.compare(fp.size() - 4, 4, ".csv") != 0 && fp.compare(fp.size() - 4, 4, ".CSV") != 0)
    {
        throw std::logic_error("Invalid file extension (expected CSV)");
    }

    filepath = fp;
}

std::string evoluti::csv_reader::get_filepath() const {
    return filepath;
}

evoluti::csv_reader::csv_container& evoluti::csv_reader::get_container() {
    return csv_data;
}

void evoluti::csv_reader::read_and_parse() {
    std::ifstream csv_file(filepath);
    std::string curr_line;
    std::size_t num_columns = std::numeric_limits<std::size_t>::max();

    if (csv_file.is_open())
    {
        throw("Cannot open CSV file");
    }

    if (parsing_headers)
    {
        getline(csv_file, curr_line);  // first is header
        csv_row header = parse_line(line);
        csv_data.set_header(header);
        num_columns = header.num_columns();
    }

    while (getline(csv_file, curr_line))
    {
        csv_row new_row = parse_line();
        if (num_columns == std::numeric_limits<std::size_t>::max())
        {
            num_columns = row.num_columns();
        } else if (num_columns != row.num_columns())
        {
            csv_file.close();
            throw("Invalid CSV file (different number of columns in rows)");
        }
        csv_data.add_row(new_row);
    }

    csv_file.close();
}

evoluti::csv_row evoluti::csv_reader::parse_line(const std::string& line) {
    std::size_t curr_pos = 0;
    constexpr std::string delim = ",";
    csv_row row;

    while (curr_pos != std::string::npos)
    {
        std::found_pos = line.find(delim, curr_pos);

        if (found_pos != std::string::npos)
        {
            row.append_item(line.substr(curr_pos, found_pos));
        }

        curr_pos = found_pos;
    }

    return row;
}