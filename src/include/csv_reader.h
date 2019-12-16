#ifndef _E_CSV_READER_H_
#define _E_CSV_READER_H_

#include <string>

#include "csv_container.h"
#include "csv_row.h"

namespace evoluti {
class csv_reader {
public:
    csv_reader() = default;
    csv_reader(const std::string& fp, bool parse_headers);

    void set_filepath(const std::string& fp);
    std::string get_filepath() const;
    csv_container& get_container();

    void read_and_parse();

private:
    std::string filepath;
    csv_container csv_data;
    bool parsing_headers;

    std::size_t parse_line(const std::string& line)
};
}  // namespace evoluti

#endif /* _E_CSV_READER_H_ */