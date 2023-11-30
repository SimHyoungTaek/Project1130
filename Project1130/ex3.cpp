#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {  
		sorted = first;// 정렬된 부분

		for (auto cur = first, prev = first; ++cur != last; ++prev) {  
			if (comp(*cur, *prev)) {  // 해당 원소와 다음 원소간 크기를 비교한다.
				std::iter_swap(cur, prev); // 원소 교환  
				sorted = cur;  // 정렬된 부분을 업데이트 한다.
			}
		}
	}
}


	class compGreater {	// 오름차순
		// functor로 구현(두 정수 비교 결과를 bool 타입으로 리턴, operator( ) 구현)
	public:
		bool operator()(int a, int b) const {
			return a < b;
		}
	};

	class compLess {	// 내림차순 정렬에 사용
		// functor로 구현(두 정수 비교 결과를 bool 타입으로 리턴, operator( ) 구현)
	public:

		bool operator()(int a, int b) const {
			return a > b;
		}

	};

	int main() {
		std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };

		std::cout << "오름차순 정렬" << std::endl;
		// bubble sort 사용하여 오름차순 정렬 후 결과 출력
		bubble_sort(values.begin(), values.end(), compGreater());
		for (const auto& value : values) {
			std::cout << value << " ";
		}
		std::cout << std::endl;


		std::cout << "내림차순 정렬" << std::endl;
		// bubble sort 사용하여 내림차순 정렬 후 결과 출력
		bubble_sort(values.begin(), values.end(), compLess());
		for (const auto& value : values) {
			std::cout << value << " ";
		}
		std::cout << std::endl;

		return 0;
	}