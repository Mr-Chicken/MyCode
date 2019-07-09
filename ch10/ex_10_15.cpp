int main() {
	int a = 10;
	auto f = [a](int b) -> int {return a + b;};
}