#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
	return (ctr > 1) ? word + ending : word;
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	auto wc = std::partition(words.begin(), words.end(), std::bind(check_size, _1, sz));

	auto count = wc - words.begin();
	cout << count << " " << make_plural(count, "word") << " of length " << sz << " or longer" << endl;

	std::for_each(words.begin(), wc, [](const string &s) {cout << s << " ";});
	cout << endl;
}

int main()
{
	vector<string> vec {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "thurtle"};
	biggies(vec, 4);
	return 0;
}
