#include <iostream>
#include <string>

class DynArray {
private:
    int* data;
    int size;

public:
    DynArray(int n) {
        size = n;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    DynArray(const DynArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    DynArray& operator=(const DynArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~DynArray() {
        delete[] data;
    }

    void PrintArray() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << '\n';
    }

    void SetArray(int i, int znach) {
        if (i < 0 or i >= size) {
            std::cout << "Индекс выходит за границы" << '\n';
        } else if (znach < -100 or znach > 100) {
            std::cout << "Значение выходит за границы нужного значения" << '\n';
        } else {
            data[i] = znach;
        }
    }

    std::string GetArray(int i) const {
        if (i >= 0 and i < size) {
            return std::to_string(data[i]);
        } else {
            return "Выход за границы массива";
        }
    }

    void dobavEl(int znach) {
        if (znach > 100 or znach < -100) {
            std::cout << "Значение выходит за границы необходимого" << '\n';
        } else {
            int* newData = new int[size + 1];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            newData[size] = znach;
            delete[] data;
            data = newData;
            size++;
        }
    }

    void add(const DynArray& other) {
        for (int i = 0; i < size; i++) {
            int b = (i < other.size) ? other.data[i] : 0;
            data[i] += b;
        }
    }

    void sub(const DynArray& other) {
        for (int i = 0; i < size; i++) {
            int b = (i < other.size) ? other.data[i] : 0;
            data[i] -= b;
        }
    }
};

int main() {
    DynArray a(5);
    for (int i = 0; i < 5; i++) {
        a.SetArray(i, i + 1);
    }
    std::cout << "a: ";
    a.PrintArray();

    DynArray b(3);
    b.SetArray(0, 10);
    b.SetArray(1, 20);
    b.SetArray(2, 30);
    std::cout << "b: ";
    b.PrintArray();

    a.add(b);
    std::cout << "a + b: ";
    a.PrintArray();

    a.sub(b);
    std::cout << "a - b: ";
    a.PrintArray();

    a.dobavEl(99);
    std::cout << "после dobavEl(99): ";
    a.PrintArray();

    DynArray c(a);
    std::cout << "копия c: ";
    c.PrintArray();

    a.SetArray(10, 5);
    a.SetArray(0, 500);
    std::cout << a.GetArray(2) << '\n';
    std::cout << a.GetArray(20) << '\n';

    return 0;
}