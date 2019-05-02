using arrT = std::string[10];
int odd[] = {2,3,4};
arrT& func();
decltype(odd)& func();
auto func() -> int(&)[10];