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

#include "CDCatalog.hpp"
#include "constants.hpp"
#include "./lib/pugixml.hpp"

#include <iostream>
#include <fstream>

bool CDCatalog::load(const std::string& fn){
    pugi::xml_document xmlDoc;

    pugi::xml_parse_result xmlParseResult = xmlDoc.load_file(fn.c_str());

    if(!xmlParseResult) {
        std::cout << "Cannot load XML file: " << fn <<std::endl;
        return false;
    }

    pugi::xml_node xmlCatalog = xmlDoc.child(CONSTANTS::STR_CATALOG.c_str());

#ifdef DEBUG
    std::cout << "Load xml file: " << fn <<" Result: " << xmlParseResult.description() << std::endl;
    int cnt = 0;
    for (pugi::xml_node cd = xmlCatalog.first_child(); cd; cd = cd.next_sibling()) {
        std::cout << "No: " << ++cnt << std::endl;
        for (pugi::xml_node child: cd.children()){
            std::cout<<"\t"<<child.name()<<", "<< child.child_value() <<std::endl;
    	}

    }
#endif
    for(pugi::xml_node cd = xmlCatalog.first_child(); cd; cd = cd.next_sibling()) {
        CD oneCD;
        for (pugi::xml_node child: cd.children()) {
            const std::string key(child.name());
            const std::string value(child.child_value());

            if(key == CONSTANTS::STR_TITLE) {
                oneCD.setTitle(value);
            } else if(key == CONSTANTS::STR_ARTIST) {
                oneCD.setArtist(value);
            } else if(key == CONSTANTS::STR_COUNTRY) {
                oneCD.setCountry(value);
            } else if(key == CONSTANTS::STR_COMPANY) {
                oneCD.setCompany(value);
            } else if(key == CONSTANTS::STR_PRICE) {
                oneCD.setPrice(value);
            } else if(key == CONSTANTS::STR_YEAR) {
                oneCD.setYear(value);
            }
    	}

        catalogVec.push_back(oneCD);
    }

    return true;
}


bool CDCatalog::toHTMLFile(const std::string& fn) const {
    std::ofstream ofs(fn);
    if(!ofs.is_open())
	{
        std::cout << "Error: Cannot open file: " << fn << std::endl;
        return false;
    }

    ofs << CONSTANTS::htmlHead
        << CD::toHTMLTableHead();

    for(const auto& cd : catalogVec) {
        ofs << cd.toHTMLTableRow();
    }

    ofs << CONSTANTS::htmlEnd;

    ofs.close();

    return true;
}