#include <malloc.h>
#include <iostream>
#include <string>
using namespace std;

typedef double (*double_method_type)(void *);
typedef void (*void_method_type)(void *);
typedef int (*int_method_type)(void *);
// double_method_type → a pointer to a function that returns a double
// void_method_type → a pointer to a function that returns void

typedef union
{
    double_method_type double_method;   // for area()
    void_method_type void_method_draw;  // for draw()
    void_method_type void_method_print; // for print()
    int_method_type int_method;         // for getter
} VirtualTableEntry;

typedef VirtualTableEntry *VTableType;

#define AREA_INDEX 0
#define DRAW_INDEX 2
#define PRINT_INDEX 1
#define GET_INDEX 3
#define PI 3.14159

struct Shape
{
    VTableType VPointer;
    // double radius;
    string name;
};

double Shape_area(Shape *_this)
{
    return 0.0;
}

void Shape_draw(Shape *_this)
{
    cout << "shape_draw" << endl;
}

void Shape_print(Shape *_this)
{
    cout << "shape_print" << endl;
}

VirtualTableEntry Shape_VTable[] = {
    {.double_method = (double_method_type)Shape_area},
    {.void_method_print = (void_method_type)Shape_print},
    {.void_method_draw = (void_method_type)Shape_draw}};

Shape *Shape_Shape(Shape *_this, string newName)
{
    _this->VPointer = Shape_VTable;
    _this->name = newName;
    return _this;
};

struct Circle
{
    VTableType VPointer;
    int radius;
};
double Circle_area(Circle *_this)
{
    return PI * _this->radius * _this->radius;
}

void Circle_print(Circle *_this)
{
    cout << "Circle print" << endl;
}

void Circle_draw(Circle *_this)
{
    cout << "Circle draw" << endl;
}

VirtualTableEntry Circle_VTable[] = {
    {.double_method = (double_method_type)Circle_area},
    {.void_method_print = (void_method_type)Circle_print},
    {.void_method_draw = (void_method_type)Circle_draw}};

Circle *Circle_Circle(Circle *_this, string name, int radius)
{
    Shape_Shape((Shape *)_this, name);
    _this->VPointer = Circle_VTable;
    _this->radius = radius;
    return _this;
}

struct Square
{
    VTableType VPointer;
    int length;
};

double Square_area(Square *_this)
{
    return _this->length * _this->length;
}

void Square_print(Square *_this)
{
    cout << "Square print" << endl;
}

void Square_draw(Square *_this)
{
    cout << "Square draw" << endl;
}

int Square_get_length(Square *_this)
{
    return _this->length;
}

VirtualTableEntry Square_VTable[] = {
    {.double_method = (double_method_type)Square_area},
    {.void_method_print = (void_method_type)Square_print},
    {.void_method_draw = (void_method_type)Square_draw},
    {.int_method = (int_method_type)Square_get_length}};

Square *Square_Square(Square *_this, string name, int length)
{
    Shape_Shape((Shape *)_this, name);
    _this->VPointer = Square_VTable;
    _this->length = length;
    return _this;
}

struct Rectangle
{
    VTableType VPointer;
    int width;
};

double Rectangle_area(Rectangle *_this)
{
    int length = ((Square *)_this)->VPointer[GET_INDEX].int_method((Square *)_this);
    return _this->width * length;
}

void Rectangle_print(Rectangle *_this)
{
    cout << "Rectangle print" << endl;
}

void Rectangle_draw(Rectangle *_this)
{
    cout << "Rectangle draw" << endl;
}

VirtualTableEntry Rectangle_VTable[] = {
    {.double_method = (double_method_type)Rectangle_area},
    {.void_method_print = (void_method_type)Rectangle_print},
    {.void_method_draw = (void_method_type)Rectangle_draw},
    {.int_method = (int_method_type)Square_get_length}};

Rectangle *Rectangle_Rectangle(Rectangle *_this, string name, int length, int width)
{
    Square_Square((Square *)_this, name, length);
    _this->VPointer = Rectangle_VTable;
    _this->width = width;
    return _this;
}

struct Triangle
{
    VTableType VPointer;
    int length;
    int height;
};

double Triangle_area(Triangle *_this, int length, int height)
{
    return 0.5 * length * height;
}

void Triangle_print(Triangle *_this)
{
    cout << "Triangle print" << endl;
}

void Triangle_draw(Triangle *_this)
{
    cout << "Triangle draw" << endl;
}

VirtualTableEntry Triangle_VTable[] = {
    {.double_method = (double_method_type)Triangle_area},
    {.void_method_print = (void_method_type)Triangle_print},
    {.void_method_draw = (void_method_type)Triangle_draw}};

Triangle *Triangle_Triangle(Triangle *_this, string name, int length, int height)
{
    Shape_Shape((Shape *)_this, name);
    _this->VPointer = Triangle_VTable;
    _this->length = length;
    _this->height = height;
    return _this;
}

struct Picture
{
};
