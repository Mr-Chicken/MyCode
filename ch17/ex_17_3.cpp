#ifndef EX_12_30_H
#define EX_12_30_H
#include <vector>
#include <iostream>
#include <fstream>
#include <tuple>
#include <memory>
#include <sstream>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::tuple;
using std::string;
using std::set;
using std::map;
using std::shared_ptr;
using std::getline;

using line_no = vector<string>::size_type;
class TextQuery {
public:
    TextQuery(std::ifstream &is);
    tuple<string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>> query(const string &s) const;
private:
    shared_ptr<vector<string>> file;
    map<string, 
        shared_ptr<set<line_no>>> wm;
};

#endif
tuple<string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>> TextQuery::query(const string &s) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(s);
    if (loc == wm.end())
        return make_tuple(s, nodata, file);
    return make_tuple(s, loc->second, file);
}
inline  string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1)? word + ending : word;
}

TextQuery::TextQuery(std::ifstream &is) : file(new vector<string>){
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}