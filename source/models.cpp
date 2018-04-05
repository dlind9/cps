#include "../headers/models.h"
#include <ostream>
using std::ostream;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;

StringTemplate::StringTemplate(std::string t) : total(t) {}

StringTemplate& StringTemplate::replaceTokenWithValue(const string & token, string value) {
    auto formattedToken = "${ " + token + " }$";

    auto pos = total.find(formattedToken);

    total.replace(
        pos,
        formattedToken.length(),
        value
    );

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
