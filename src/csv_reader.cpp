#include "csv_reader.h"

#include <ifstream>
#include <limits>
#include <stdexcept>

#include "csv_container.h"
#include "csv_row.h"

evoluti::csv_reader::csv_reader(const std::string& fp) : filepath(fp) {
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

    while (getline(csv_file, curr_line))
    {
        if (curr_line == std::numeric_limits<std::size_t>::max())
        {
            curr_line = parse_line(line);
        } else if (curr_line != parse_line(line))
        {
            csv_file.close();
            throw("Invalid CSV file (different number of columns in rows)");
        }
    }

    csv_file.close();
}

std::size_t evoluti::csv_reader::parse_line(const std::string& line) {
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

    csv_container.add_row(row);

    return row.num_columns();
}