#include <iostream>

using namespace std;

class IntVector2D {
private:
    int x;
    int y;

public:
    IntVector2D() {
        x = 0;
        y = 0;
    }

    IntVector2D(int a, int b) {
        x = a;
        y = b;
    }

    void set(IntVector2D b) {
        x = b.x;
        y = b.y;
    }

    IntVector2D add(IntVector2D b) {
        IntVector2D c;
        c.x = x + b.x;
        c.y = y + b.y;
        return c;
    }

    // Overload operator >
    bool operator>(IntVector2D b) {
        return (x > b.x && y > b.y);
    }

    // Overload operator -
    IntVector2D operator-(IntVector2D b) {
        IntVector2D c;

        if(x < b.x || y < b.y) {
            cout << "Error: negative values" << endl;
            throw "AAAAAAAAAAAAAAA!";
        }

        c.x = x - b.x;
        c.y = y - b.y;
        return c;
    }

    IntVector2D operator+(IntVector2D b) {
        return add(b);
    }

    void operator=(IntVector2D b) {
        set(b);
    }

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int x1;
    float y1;

    IntVector2D a(1,1), b(2,3), c;

    c.set(a.add(b));
    c.print();

    c = a - b;
    c.print();

    // The same:
    // c.=(a.+(b));
    c = a + b;
    c.print();

    // We need the next code to work:
    LongInt x,y,z;

    LongInt::SetMultiplicator(new KaratsubaMultiplicator());

    z = x * y;
    cout << z << endl;

    LongInt::SetMultiplicator(new SimpleMultiplicator());

    z = x * y;
    cout << z << endl;

    return 0;
}