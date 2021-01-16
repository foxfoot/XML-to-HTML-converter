#include "../lib/catch.hpp"
#include "../../src/CD.hpp"

#include <iostream>

namespace TestData {
    const std::string title = "Mad Dogs and Englishmen";
    const std::string artist = "Joe Cocker";
    const std::string country = "USA";
    const std::string company = "A&M";
    const std::string price = "9.80";
    const std::string year = "1970";

    const std::string expectedRow = "<tr><td>Mad Dogs and Englishmen</td>\n"
            "<td>Joe Cocker</td>\n"
            "<td>USA</td>\n"
            "<td>A&M</td>\n"
            "<td>9.80</td>\n"
            "<td>1970</td>\n"
        "</tr>\n";

    const std::string expectedHead = "<tr><td>TITLE</td>\n"
            "<td>ARTIST</td>\n"
            "<td>COUNTRY</td>\n"
            "<td>COMPANY</td>\n"
            "<td>PRICE</td>\n"
            "<td>YEAR</td>\n"
        "</tr>\n";
    
    const std::string expectedRowMissingCountryYear = "<tr><td>Mad Dogs and Englishmen</td>\n"
            "<td>Joe Cocker</td>\n"
            "<td></td>\n"
            "<td>A&M</td>\n"
            "<td>9.80</td>\n"
            "<td></td>\n"
        "</tr>\n";
};

TEST_CASE("Normal case: set CD info and conver to html table row") {
    CD cd;
    cd.setTitle(TestData::title);
    cd.setArtist(TestData::artist);
    cd.setCountry(TestData::country);
    cd.setCompany(TestData::company);
    cd.setPrice(TestData::price);
    cd.setYear(TestData::year);

    const std::string cdTableRow = cd.toHTMLTableRow();
    REQUIRE(cdTableRow == TestData::expectedRow);
}

TEST_CASE("Normal case: conver to html table head") {
    const std::string cdTableHead = CD::toHTMLTableHead();
    REQUIRE(cdTableHead == TestData::expectedHead);
}

TEST_CASE("Missing country and year") {
    CD cd;
    cd.setTitle(TestData::title);
    cd.setArtist(TestData::artist);
    cd.setCompany(TestData::company);
    cd.setPrice(TestData::price);

    const std::string cdTableRow = cd.toHTMLTableRow();
    REQUIRE(cdTableRow == TestData::expectedRowMissingCountryYear);
}