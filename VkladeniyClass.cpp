/*
����� � ������� � �� ������� � �������. �� ������ ��������� ����� � 3D-������� �� ���� ��������� x, y � z. ���������, Point(0.0, 1.0, 2.0) ���� ������ � ������������� ������� x = 0.0, y = 1.0 � z = 2.0.

������ � ������ � �� ��������, ��� �� ������� � �������� (��� �� ���������). �� ������ ��������� ������ � 3D-������� ����� �������� x, y � z, �� ������������� ������ ������� ������ ���� x, y � z. ���������, Vector(1.0, 0.0, 0.0) ���� ��������, �� ����������� �������� ����� ������ ������� �� x �������� 1.0.

������ ���� ��������������� �� ����� ��� �� ���������� �� ���� �������. �� �������� ������ ��������� �������� ������� �� ������� �����. ���������, Point(0.0, 1.0, 2.0) + Vector(0.0, 2.0, 0.0) ����� ����� (0.0, 3.0, 2.0).

����� � ������� ����� ���������������� � ���������� ������� (����� ��� ������������� ������ ������, � ������� � ��� ���������� ������).

�������� � �������� ��������:
a) ������ ���� Point3D �������� � ���� Vector3D � ��������� ����� moveByVector() � ���� Point3D.
b) ������������ ��� ����� � ������� �������, ��� ������ ���������� �����
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
    // ���� ����� ���� c��� ����������
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