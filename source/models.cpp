#include "../headers/models.h"
#include <ostream>
using std::ostream;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;
#include <iostream>



StringTemplate::StringTemplate(std::string t) : total(t) {}

StringTemplate& StringTemplate::replace(const std::string & token, const std::string & value) {
    auto formattedToken = "${ " + token + " }$";

    std::size_t pos = total.find(formattedToken);

    while (pos != std::string::npos) {
        total = total.replace(pos, formattedToken.length(), value);
        pos = total.find(formattedToken);
    }

    return *this;
}


std::string StringTemplate::get() {
    return total;
}

bool operator==(const BoundingBox & lhs, const BoundingBox & rhs) {
    return rhs.height == lhs.height && rhs.width == lhs.width;
}

string BoundingBox::toString() const {
    ostringstream out;
    out << "("<< width << ", " << height << ")";

    return out.str();
}

ostream& operator <<(ostream& os, const BoundingBox & value) {
    os << value.toString();
    return os;
}
