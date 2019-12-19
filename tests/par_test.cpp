#include <iomanip>
#include <iostream>

#include "evoluti_csv.h"

int main() {
    evoluti::csv_reader reader1("/Users/bryanmorfe/repositories/evoluti-cpp-csv/cpp-csv/resources/file1.csv", true);
    reader1.read_and_parse();
    evoluti::csv_container csv_data = reader1.get_container();

    for (auto& hdr_field : csv_data.get_header())
    {
        std::cout << std::left << std::setw(15) << hdr_field << "\t";
    }

    std::cout << std::endl;

    for (auto& row : csv_data)
    {
        for (auto& field : row)
        {
            std::cout << std::left << std::setw(15) << field << "\t";
        }
        std::cout << std::endl;
    }

    // Writer test
    evoluti::csv_writer writer1("/Users/bryanmorfe/repositories/evoluti-cpp-csv/cpp-csv/resources/file3.csv");
    evoluti::csv_container container;
    evoluti::csv_row row({"Year", "Name", "Release"});
    container.set_header(row);
    row.set_items({"1994", "Doe", "Conditional"});
    container.add_row(row);
    row.set_items({"1956", "Queen", "Conditional"});
    container.add_row(row);
    row.set_items({"2019", "Allen", "Good Behavior"});
    container.add_row(row);
    writer1.set_container(container);
    writer1.save();

    return 0;
}