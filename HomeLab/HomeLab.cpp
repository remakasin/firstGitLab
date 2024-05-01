#include <iostream>
#include <cmath>

using namespace std;

class IsoscelesTrapezoid {
private:
    double x1, y1, x2, y2, x3, y3, x4, y4;

    double Distance(double x1, double y1, double x2, double y2) {
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    void LengthSide() {
        double AB_length = Distance(x1, y1, x2, y2);
        double BC_length = Distance(x2, y2, x3, y3);
        double CD_length = Distance(x3, y3, x4, y4);
        double DA_length = Distance(x4, y4, x1, y1);
        printf("\nAB = %.2f\tBC = %.2f\nCD = %.2f\tDA = %.2f\t", AB_length, BC_length, CD_length, DA_length);
    }

    double Perimeter() {
        double perimeter;
        return perimeter = Distance(x1, y1, x2, y2) + Distance(x2, y2, x3, y3) + Distance(x3, y3, x4, y4) + Distance(x4, y4, x1, y1);
    }


public:
    IsoscelesTrapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
        this->x4 = x4;
        this->y4 = y4;
    }

    double Square() {
        double AB_length = Distance(x1, y1, x2, y2);
        double BC_length = Distance(x2, y2, x3, y3);
        double CD_length = Distance(x3, y3, x4, y4);
        double DA_length = Distance(x4, y4, x1, y1);
        double square = 0.5 * (BC_length + DA_length) * sqrt(pow(AB_length, 2) - pow((DA_length - BC_length) / 2, 2));
        return square;
    }

    bool IsIsosceles() {
        double AC_length = Distance(x1, y1, x3, y3);
        double BD_length = Distance(x2, y2, x4, y4);

        return AC_length == BD_length;
    }

    void Statistics() {
        printf("\n\tДлинны сторон");
		LengthSide();
        printf("\n\nПериметр: %.2f", Perimeter());
        printf("\nПлощадь: %.2f", Square());
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    printf("\tРавнобедренные трапеции\n");
    // Пример 1: Равнобедренная трапеция
    IsoscelesTrapezoid t1(1, 1, 3, 1, 4, 3, 0, 3);
    cout << "Пример 1: " << (t1.IsIsosceles() ? "Да" : "Нет") << endl;

    // Пример 2: Неравнобедренная трапеция
    IsoscelesTrapezoid t2(1, 1, 3, 1, 4, 5, 0, 3);
    cout << "Пример 2: " << (t2.IsIsosceles() ? "Да" : "Нет") << endl;

    // Пример 3: Трапеция с отрицательными координатами
    IsoscelesTrapezoid t3(-1, -1, -3, -1, -4, -3, -0, -3);
    cout << "Пример 3: " << (t3.IsIsosceles() ? "Да" : "Нет") << endl;

    // Пример 4: Трапеция с пересечение в оси OY равнобедренная
    IsoscelesTrapezoid t4(-2, 4, -1, 6, 1, 6, 2, 4);
    cout << "Пример 4: " << (t4.IsIsosceles() ? "Да" : "Нет") << endl;

    t4.Statistics();

    IsoscelesTrapezoid objects[] = {
        t1,
        t2,
        t3,
        t4,
    };

    double averageArea = 0;
    int count = 0;

    for (auto& obj : objects) {
        averageArea += obj.Square();
        count++;
    }
    averageArea = averageArea / count;
    
    printf("\n\nСредняя площадь: %.2f", averageArea);

    count = 0;

    for (auto& obj : objects) {
        if (obj.Square() > averageArea)
            count++;
    }
    printf("\nКоличество трапеций у которых площадь выше средней %d\n\n", count);

    return 0;
}