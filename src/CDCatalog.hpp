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

#ifndef CD_CATALOG_HPP_
#define CD_CATALOG_HPP_

#include <string>
#include <vector>

#include "lib/pugixml.hpp"
#include "CD.hpp"


class CDCatalog
{
public:

    // This function loads the XML file
    // @param fn: - std::string the file name of the XML file including the path
    // @return: true, if load successfully; false, if load failed.
    bool load(const std::string& fn);

    // This function writes to the HTML file in table format
    // @param fn: - std::string the file name of the HTML file including the path
    // @return: true, if write successfully; false, if write failed.
    bool toHTMLFile(const std::string& fn) const;

private:
    std::vector<CD> catalogVec;
};

#endif //CD_CATALOG_HPP_