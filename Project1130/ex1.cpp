#include <iostream>

template <typename T>
T sum(T arg) { return arg; } // ���� ����  ���� ���ڿ� �ش��ϴ� �� ��ȯ
// template function

template <typename T, typename... Types>
T sum(T arg, Types... args) { return arg + sum(args...); } // ��������� �� ���


template <typename T, typename... Types>
double average(T arg, Types... args) {// sum�Լ��� Ȱ���� ����� ���ϴ� �Լ�
	T sum1 = sum(arg, args...); // ����Լ��� ���� ���ڵ��� �� �����ְ� �ִ�.
	int count = 1+ sizeof...(args); // sizeof...�� Ȱ���� ���޵� ���� �� ����. args ���� ���� ������ arg�� �ش��ϴ� ���� ���� �� �ֵ��� 1 �����־���.
	return static_cast<double>(sum1) / count; // ������ ����� ��ȯ�Ѵ�.

}		// template function

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;	// average = 5

	return 0;
}
