#include <memory>

using std::unique_ptr;

int main()
{
	unique_ptr<int> p1(new int(45));
	unique_ptr<int> p2;
	p2 = p1;
	/*
		g++ (7.4.0)
			error: use of deleted function 
		‘std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
			note: declared here
       unique_ptr& operator=(const unique_ptr&) = delete;
 		chang++ (6.0.0)
 			error: overload resolution selected deleted operator '='
	*/
	return 0;
}