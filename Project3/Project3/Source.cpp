#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> A;
	A.push(1);
	A.push(2);
	A.push(3);
	A.push(4);
	cout << A.size() << endl;



	queue<int> B=A;
	cout << B.size() << endl;
	cin.get();
}