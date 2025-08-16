#include "stackTemplateInCPP.cpp"

using namespace std;

int main() {
	stack<int>s;
	cout << s.size() << '\n';
	s.push(5);
	cout << s.size() << '\n';
	cout << s.empty() << '\n';
	cout << s.pop() << '\n';
	cout << s.empty() << '\n';

}
