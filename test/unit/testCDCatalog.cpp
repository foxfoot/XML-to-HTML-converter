#include "../lib/catch.hpp"
#include "../../src/CDCatalog.hpp"

#include <iostream>
#include <cstdio>
#include <filesystem>

namespace TestData {
    const std::string xmlFileName = "cd_catalog.xml";
    const std::string emptyXMLFileName = "empty_catalog.xml";
    const std::string nonExistingXMLFileName = "no-such.xml";
    const std::string notXMLFileName = "not_an_xml.xml";

    const std::string htmlFileName = "output_cd_catalog.html";
    const std::string nonExisitingHTMLFilePath = "no-such-path/output.xml";
};

TEST_CASE("Normal case: read an XML file. It should write to HTML file.") {
    SECTION("Setup") {
        std::remove(TestData::htmlFileName.c_str());
    }

    CDCatalog catalog;

    REQUIRE(catalog.load(TestData::xmlFileName));
    REQUIRE(catalog.toHTMLFile(TestData::htmlFileName));

    SECTION("Teardown") {
        std::remove(TestData::htmlFileName.c_str());
    }
}

TEST_CASE("Normal case: read an empty XML file. It should write to HTML file with table head only") {
    SECTION("Setup") {
        std::remove(TestData::htmlFileName.c_str());
    }

    CDCatalog catalog;

    REQUIRE(catalog.load(TestData::emptyXMLFileName));
    REQUIRE(catalog.toHTMLFile(TestData::htmlFileName));

    SECTION("Teardown") {
        std::remove(TestData::htmlFileName.c_str());
    }
}

TEST_CASE("Error case: read a non-existing XML file. It should return an error.") {
    CDCatalog catalog;

    REQUIRE(!catalog.load(TestData::nonExistingXMLFileName));
}

TEST_CASE("Error case: read a text file") {
    CDCatalog catalog;

    REQUIRE(!catalog.load(TestData::notXMLFileName));
}

TEST_CASE("Error case: write to a non-existing diretory. It should return an error.") {
    SECTION("Setup") {
        std::filesystem::remove(TestData::nonExisitingHTMLFilePath.c_str());
    }

    CDCatalog catalog;

    REQUIRE(catalog.load(TestData::xmlFileName));
    REQUIRE(!catalog.toHTMLFile(TestData::nonExisitingHTMLFilePath));
}