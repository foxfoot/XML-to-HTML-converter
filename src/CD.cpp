/**
MIT License

Copyright (c) 2021 foxfoot

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "CD.hpp"
#include "constants.hpp"

#include <iostream>
#include <sstream>

void CD::setTitle(const std::string& tlt) {
    title = tlt;
}

void CD::setArtist(const std::string& art) {
    artist = art;
}

void CD::setCountry(const std::string& cntr) {
    country = cntr;
}

void CD::setCompany(const std::string& cmp) {
    company = cmp;
}

void CD::setPrice(const std::string&  prc) {
    price = prc;
}

void CD::setYear(const std::string&  yr) {
    year = yr;
}

std::string CD::toHTMLTableHead() {
    std::stringstream ss;
    ss<< "<tr>"
        << "<td>" << CONSTANTS::STR_TITLE << "</td>\n"
        << "<td>" << CONSTANTS::STR_ARTIST << "</td>\n"
        << "<td>" << CONSTANTS::STR_COUNTRY << "</td>\n"
        << "<td>" << CONSTANTS::STR_COMPANY << "</td>\n"
        << "<td>" << CONSTANTS::STR_PRICE << "</td>\n"
        << "<td>" << CONSTANTS::STR_YEAR << "</td>\n"
        <<"</tr>\n";

    return ss.str();
}

std::string CD::toHTMLTableRow() const {
    std::stringstream ss;
    ss<< "<tr>"
        << "<td>" << title << "</td>\n"
        << "<td>" << artist << "</td>\n"
        << "<td>" << country << "</td>\n"
        << "<td>" << company << "</td>\n"
        << "<td>" << price << "</td>\n"
        << "<td>" << year << "</td>\n"
        <<"</tr>\n";

    return ss.str();
}