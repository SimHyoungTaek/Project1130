#include <iostream>

template <typename T>
T sum(T arg) { return arg; } // 종료 조건  단일 인자에 해당하는 값 반환
// template function

template <typename T, typename... Types>
T sum(T arg, Types... args) { return arg + sum(args...); } // 재귀적으로 합 계산


template <typename T, typename... Types>
double average(T arg, Types... args) {// sum함수를 활용해 평균을 구하는 함수
	T sum1 = sum(arg, args...); // 재귀함수를 통해 인자들을 다 더해주고 있다.
	int count = 1+ sizeof...(args); // sizeof...를 활용해 전달된 인자 수 센다. args 수를 세기 때문에 arg에 해당하는 값도 더할 수 있도록 1 더해주었다.
	return static_cast<double>(sum1) / count; // 나눠서 평균을 반환한다.

}		// template function

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;	// average = 5

	return 0;
}
