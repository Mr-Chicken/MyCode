#include <bitset>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::bitset;

template <size_t> class QuizResult;
template <size_t N>
class QuizAnswer {
	friend class QuizResult<N>;
public:
	QuizAnswer(const std::string &s): bs(s) {}
private:
	bitset<N> bs;
};

template <size_t N> ostream& operator<<(ostream&, const QuizResult<N>&);
template <size_t N>
class QuizResult {
	friend ostream& operator<<<N>(ostream &os, const QuizResult &qr);
public:
	QuizResult() = default;
	QuizResult(const std::string &s): bs(s) {}
	void answer(size_t n, bool val) {
		bs.set(n - 1, val);
	}
	double score(const QuizAnswer<N> &qa) const {
		size_t wrong = 0;
		return N * 1.0 - 1.0 * ((qa.bs ^ this->bs).count());
	}
private:
	bitset<N> bs;
};
template <size_t N>
inline ostream& operator<<(ostream &os, const QuizResult<N> &qr) {
	return os << qr.bs;
}
int main()
{
	QuizAnswer<5> qa("11111");
	QuizResult<5> qr("10111");
	cout << qr.score(qa) << endl;
	return 0;
}