#ifndef _E_CSV_CONTAINER_H_
#define _E_CSV_CONTAINER_H_

#include <vector>
#include <string>
#include "csv_row.h"

namespace evoluti
{
class csv_container
{
public:
    csv_container() = default;
    csv_container(const std::string& fn, const csv_row& hdr, const std::vector<csv_row>& dat);

    /* Const getters */
    csv_row get_header() const;
    std::vector<csv_row> get_rows() const;

    /* Modifiers */

private:
    std::string filename;  // loaded or to be saved
    csv_row header;  // optional
    std::vector<csv_row> data;
};
}

#endif /* _E_CSV_CONTAINER_H */