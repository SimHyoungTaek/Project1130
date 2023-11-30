#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {  
		sorted = first;// ���ĵ� �κ�

		for (auto cur = first, prev = first; ++cur != last; ++prev) {  
			if (comp(*cur, *prev)) {  // �ش� ���ҿ� ���� ���Ұ� ũ�⸦ ���Ѵ�.
				std::iter_swap(cur, prev); // ���� ��ȯ  
				sorted = cur;  // ���ĵ� �κ��� ������Ʈ �Ѵ�.
			}
		}
	}
}


	class compGreater {	// ��������
		// functor�� ����(�� ���� �� ����� bool Ÿ������ ����, operator( ) ����)
	public:
		bool operator()(int a, int b) const {
			return a < b;
		}
	};

	class compLess {	// �������� ���Ŀ� ���
		// functor�� ����(�� ���� �� ����� bool Ÿ������ ����, operator( ) ����)
	public:

		bool operator()(int a, int b) const {
			return a > b;
		}

	};

	int main() {
		std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };

		std::cout << "�������� ����" << std::endl;
		// bubble sort ����Ͽ� �������� ���� �� ��� ���
		bubble_sort(values.begin(), values.end(), compGreater());
		for (const auto& value : values) {
			std::cout << value << " ";
		}
		std::cout << std::endl;


		std::cout << "�������� ����" << std::endl;
		// bubble sort ����Ͽ� �������� ���� �� ��� ���
		bubble_sort(values.begin(), values.end(), compLess());
		for (const auto& value : values) {
			std::cout << value << " ";
		}
		std::cout << std::endl;

		return 0;
	}