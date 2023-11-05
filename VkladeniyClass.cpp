/*
Точка в геометрії — це позиція в просторі. Ми можемо визначити точку в 3D-просторі як набір координат x, y і z. Наприклад, Point(0.0, 1.0, 2.0) буде точкою в координатному просторі x = 0.0, y = 1.0 і z = 2.0.

Вектор в фізиці — це величина, яка має довжину і напрямок (але не положення). Ми можемо визначити вектор в 3D-просторі через значення x, y і z, що представляють напрям вектора вздовж осей x, y і z. Наприклад, Vector(1.0, 0.0, 0.0) буде вектором, що представляє напрямок тільки вздовж додатної осі x довжиною 1.0.

Вектор може застосовуватися до точки для її переміщення на нову позицію. Це робиться шляхом додавання напрямку вектора до позиції точки. Наприклад, Point(0.0, 1.0, 2.0) + Vector(0.0, 2.0, 0.0) дасть точку (0.0, 3.0, 2.0).

Точки і вектори часто використовуються в комп’ютерній графіці (точка для представлення вершин фігури, а вектори — для переміщення фігури).

Виходячи з наступної програми:
a) Зробіть клас Point3D внутрішнім у класі Vector3D і реалізуйте метод moveByVector() в класі Point3D.
b) використайте цей метод в головній функції, щоб змінити координати точки
*/
#include <iostream>
class Vector3D;

class Point3D
{

private:
    double m_x, m_y, m_z;

public:
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x(x), m_y(y), m_z(z)
    {

    }

    void print()
    {
        std::cout << "Point1(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    void printVector()
    {
        std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    void moveByVector(const Vector3D& v);

};

class Vector3D
{
private:
    double m_x, m_y, m_z;
    // змінні мають бути cаме приватними
public:
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x(x), m_y(y), m_z(z)
    {

    }
    void print()
    {
        std::cout << "Point2(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    Vector3D GetVec() const {
        return Vector3D(m_x, m_y, m_z);
    }

    friend void Point3D::moveByVector(const Vector3D& v);
};

void Point3D::moveByVector(const Vector3D& v) {
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}








int main()
{
    Point3D p(3.0, 4.0, 5.0);
    Vector3D v(3.0, 3.0, -2.0);

    p.printVector();
    v.print();
    p.moveByVector(v);
    p.printVector();
    

    return 0;
}