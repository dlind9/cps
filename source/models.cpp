#include "../headers/models.h"
#include <ostream>
using std::ostream;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;
#include <iostream>


std::string replaceFirstOccurrence(std::string& s,
    const std::string& toReplace,
    const std::string& replaceWith)
{
    std::size_t pos = s.find(toReplace);
    if (pos == std::string::npos) return s;
    return s.replace(pos, toReplace.length(), replaceWith);
}


StringTemplate::StringTemplate(std::string t) : total(t) {}

StringTemplate& StringTemplate::replaceTokenWithValue(const string & token, string value) {
    auto formattedToken = "${ " + token + " }$";

    replaceFirstOccurrence(total, formattedToken, value);

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
