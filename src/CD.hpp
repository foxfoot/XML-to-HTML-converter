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

#ifndef CD_HPP_
#define CD_HPP_

#include <string>

class CD
{
public:
    void setTitle(const std::string& tlt);
    void setArtist(const std::string& art);
    void setCountry(const std::string& cntr);
    void setCompany(const std::string& cmp);
    void setPrice(const std::string&  prc);
    void setYear(const std::string&  yr);

    std::string toHTMLTableRow() const;
private:
    std::string title;
    std::string artist;
    std::string country;
    std::string company;
    std::string price; //Do not over-engineering. Keep string type. No need to use float/double now.
    std::string year; //Do not over-engineering. Keep string type. No need to use int now.
};

#endif //CD_HPP_