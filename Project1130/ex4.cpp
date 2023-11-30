#include <iostream>;


class Shape {// 도형 인터페이스 정의
public:
    virtual void draw() = 0; // 가상 함수로 선언해 오버라이딩이 가능하도록 함
    virtual ~Shape() {} // 가상 소멸자
};


class Rectangle : public Shape {// 직사각형 클래스
public:
    void draw() {
        std::cout << "Shape: Rectangle" << std::endl; // draw함수 오버라이딩
    }
};


class Circle : public Shape {// 원을 나타내는 클래스
public:
    void draw() {
        std::cout << "Shape: Circle" << std::endl;// draw함수 오버라이딩
    }
};

class ShapeDecorator : public Shape { // 도형을 꾸미는 추상 클래스
protected:
    Shape* decoratedShape;

public:
    ShapeDecorator(Shape* decoratedShape) : decoratedShape(decoratedShape) {}

    void draw()  {
        decoratedShape->draw(); // draw함수 오버라이딩
    }
};

class RedShapeDecorator : public ShapeDecorator { // 빨간 테두리를 추가로 그리는 클래스 ShapeDecorator 상속받음
public:
    RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {}

    void draw() {
        decoratedShape->draw(); // 원래 도형을 그림
        setRedBorder(); // 빨간 테두리 추가
    }

private:
    void setRedBorder() {
        std::cout << "Border Color: Red" << std::endl;
    }
};

int main() {
    // 도형 객체 생성
    Shape* circle = new Circle();
    Shape* redCircle = new RedShapeDecorator(new Circle());
    Shape* redRectangle = new RedShapeDecorator(new Rectangle());

    // 도형 그리기
    std::cout << "Circle with normal border" << std::endl;
    circle->draw();

    std::cout << "\nCircle of red border" << std::endl;
    redCircle->draw();

    std::cout << "\nRectangle of red border" << std::endl;
    redRectangle->draw();

    // 메모리 해제
    delete circle;
    delete redCircle;
    delete redRectangle;

    return 0;
}
