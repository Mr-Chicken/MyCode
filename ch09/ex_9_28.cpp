#include <forward_list>
#include <iostream>

using std::cout;
using std::endl;
using std::forward_list;
using std::string;

void findThenInsert(forward_list<string> &flst, const string &find, const string &addAfter) {
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	
	while (curr != flst.end()) {
		if (*curr == find) {
			flst.insert_after(curr, addAfter);
			return ;
		}
		prev = curr++;
	}
	flst.insert_after(prev, addAfter);
}

int main()
{
	forward_list<string> flst {"Ming", "Xiao", "Gang", "Qian", "Zhang"};
	findThenInsert(flst, "HHHH", "KangKang");

	for (const auto &x : flst)
		cout << x << " ";
	cout << endl;
	return 0;
}