#include <iostream>;


class Shape {// ���� �������̽� ����
public:
    virtual void draw() = 0; // ���� �Լ��� ������ �������̵��� �����ϵ��� ��
    virtual ~Shape() {} // ���� �Ҹ���
};


class Rectangle : public Shape {// ���簢�� Ŭ����
public:
    void draw() {
        std::cout << "Shape: Rectangle" << std::endl; // draw�Լ� �������̵�
    }
};


class Circle : public Shape {// ���� ��Ÿ���� Ŭ����
public:
    void draw() {
        std::cout << "Shape: Circle" << std::endl;// draw�Լ� �������̵�
    }
};

class ShapeDecorator : public Shape { // ������ �ٹ̴� �߻� Ŭ����
protected:
    Shape* decoratedShape;

public:
    ShapeDecorator(Shape* decoratedShape) : decoratedShape(decoratedShape) {}

    void draw()  {
        decoratedShape->draw(); // draw�Լ� �������̵�
    }
};

class RedShapeDecorator : public ShapeDecorator { // ���� �׵θ��� �߰��� �׸��� Ŭ���� ShapeDecorator ��ӹ���
public:
    RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {}

    void draw() {
        decoratedShape->draw(); // ���� ������ �׸�
        setRedBorder(); // ���� �׵θ� �߰�
    }

private:
    void setRedBorder() {
        std::cout << "Border Color: Red" << std::endl;
    }
};

int main() {
    // ���� ��ü ����
    Shape* circle = new Circle();
    Shape* redCircle = new RedShapeDecorator(new Circle());
    Shape* redRectangle = new RedShapeDecorator(new Rectangle());

    // ���� �׸���
    std::cout << "Circle with normal border" << std::endl;
    circle->draw();

    std::cout << "\nCircle of red border" << std::endl;
    redCircle->draw();

    std::cout << "\nRectangle of red border" << std::endl;
    redRectangle->draw();

    // �޸� ����
    delete circle;
    delete redCircle;
    delete redRectangle;

    return 0;
}
