
#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
double min_value(T x) {// 단일인자 받는 min_value함수
    return x; // 입력 받은 값 그대로 반환
}

template<typename T, typename... Args>
double min_value(T x, Args... args) { // 가변인자 받는 min_value함수
    double min = min_value(args...); // min에 입력된 인자 중 첫번째 인자를 제외한 다른 인자들의 최솟값을 min에 저장
    if (static_cast<double>(x) < min) // 첫번째 값과 min을 비교해 작은 값을 min으로 선정
        min = x;
    return min; // min반환
}


int main() {
    auto x = min_value(42, 3.14, 11.1f, -2); // 함수 호출
    std::cout << x; // 값 출력

    getchar();
    return 0;
}
