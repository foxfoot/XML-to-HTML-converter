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

#include <iostream>
#include "CDCatalog.hpp"

void helper() {
    std::cout << "usage: xml2html <XML file name> <HTML file name>"
              << std::endl
              << "This file is to convert the source XML file to the target HTML file."
              << std::endl;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        helper();
        return 1;
    }

    std::string xmlFileName(argv[1]);
    std::string htmlFileName(argv[2]);

    if(xmlFileName == htmlFileName) {
        std::cout << "The XML file name can not be the same as the HTML file name." << std::endl;
        return 2;
    }

    CDCatalog catalog;
    if (!catalog.load(argv[1])) {
        return 3;
    } 

    if (!catalog.toHTMLFile(argv[2])) {
        return 4;
    }

    return 0;
}