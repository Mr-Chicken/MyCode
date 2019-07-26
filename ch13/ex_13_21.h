
using line_no = vector<string>::size_type;
class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &is);
    QueryResult query(const string &s) const;
    TextQuery(const TextQuery &tq) = default;
    TextQuery& operator=(const TextQuery &tq) = default;
private:
    shared_ptr<vector<string>> file;
    map<string, 
        shared_ptr<set<line_no>>> wm;
};

class QueryResult {
    friend std::ostream& print(std::ostream &os, const QueryResult &qr);
public:
    QueryResult(string s,
                        shared_ptr<set<line_no>> p,
                        shared_ptr<vector<string>> f):
                        sought(s), lines(p), file(f) {}
    QueryResult(const QueryResult &qr) = default;
    QueryResult& operator=(const QueryResult &qr) = default;
private:
    string sought;
    shared_ptr<vector<string>> file;
    shared_ptr<set<line_no>> lines;
};