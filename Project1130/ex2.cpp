
#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
double min_value(T x) {// �������� �޴� min_value�Լ�
    return x; // �Է� ���� �� �״�� ��ȯ
}

template<typename T, typename... Args>
double min_value(T x, Args... args) { // �������� �޴� min_value�Լ�
    double min = min_value(args...); // min�� �Էµ� ���� �� ù��° ���ڸ� ������ �ٸ� ���ڵ��� �ּڰ��� min�� ����
    if (static_cast<double>(x) < min) // ù��° ���� min�� ���� ���� ���� min���� ����
        min = x;
    return min; // min��ȯ
}


int main() {
    auto x = min_value(42, 3.14, 11.1f, -2); // �Լ� ȣ��
    std::cout << x; // �� ���

    getchar();
    return 0;
}
