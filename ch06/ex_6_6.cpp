int count_calls(int a) {
	int b = a + 0;
	static unsigned crt = 0;
	return ++crt + b;
}