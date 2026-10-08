#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> f() {
	return { 1, 2, 3 };
}

int main() {
	// 1.pointer
	//int* n = new int(5);
	//cout << n << endl; // address
	//cout << *n << endl; // value
	//n = nullptr;
	//cout << *n << endl; // error

	// 2. pass by ref
	// - saves you copying time and memory
	// - see the example for copy ref measurement

	// 3. types and overflow handling
	//int a = INT_MAX;
	//int b = INT_MAX;
	//long long c = a + b;
	//cout << c;
	//int n;
	//cin >> n;

	// 4. double
	//double a = 0.1 + 0.2;
	//double b = 0.3;
	//cout << (a == b) << endl; // false
	//// double is not precise, use epsilon to compare
	//// learn more about it from the link in the readme
	//double EPSILON = 1e-9;
	//cout << (abs(a - b) < EPSILON) << endl; // true

	// 5. vector reading and printing

	//vector<int> arr(n);
	//for (size_t i = 0; i < n; i++)
	//{
	//	cin >> arr[i];
	//}

	//arr.push_back(1);
	//arr.pop_back();

	//for (size_t i = 0; i < n; i++) {
	//	cout << arr[i] << " ";
	//}
	//
	// 6. auto newArr = f(); // auto keyword
	// 
	// 7. range based for loop / for-each loop
	//for (auto& el : arr) {
	//	cout << el << " ";
	//}
	// 10. iterators
	// for (auto it = arr.begin(); it != arr.end(); ++it) {
	// 	cout << *it << " ";
	// }

	// 8. string
	//string str = "Hello World";
	//cout << str.length() << endl;
	//str += "!";
	//cout << str.length() << endl;
	//// v1
	////cin >> str; // abc abc
	////cout << str << endl; // abc
	//// v2
	//getline(cin, str); // abc abc
	//cout << str << endl; // abc abc

	// 9. stl functions (there are a lot)
	// cout << max(1, 2) << endl;
	// cout << min(1, 2) << endl;
	// vector<int> arr = { 1, 2, 3, 4, 5 };
	// reverse(arr.begin(), arr.end());
	// for (auto& el : arr) {
	// 	cout << el << " ";
	// }
	// cout << endl;
	// int a = 1, b = 2;
	// swap(a, b);
	// cout << a << " " << b << endl;
}
