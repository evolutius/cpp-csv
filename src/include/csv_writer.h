#ifndef _E_CSV_WRITER_H_
#define _E_CSV_WRITER_H_

#include <string>

#include "csv_container.h"
#include "csv_row.h"

namespace evoluti {
class csv_writer {
public:
    csv_writer() = default;
    csv_writer(const std::string& fp, const csv_container& container = csv_container());

    void set_filepath(const std::string& fp);
    std::string get_filepath() const;
    void set_container(const csv_container& container);

    void save();

private:
    std::string filepath;
    csv_container csv_data;

    std::string build_line(const csv_row& row) const;
};
}  // namespace evoluti

#endif /* _E_CSV_WRITER_H_ */