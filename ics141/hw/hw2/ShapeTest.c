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
    double_method_type double_method; // for area()
    void_method_type void_method;     // for draw()
    // void_method_type void_method_print; // for print()
    int_method_type int_method; // for getter
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
    {.void_method = (void_method_type)Shape_print},
    {.void_method = (void_method_type)Shape_draw}};

Shape *Shape_Shape(Shape *_this, string newName)
{
    _this->VPointer = Shape_VTable;
    _this->name = newName;
    return _this;
};

struct Circle
{
    VTableType VPointer;
    string name;
    int radius;
};
double Circle_area(Circle *_this)
{
    return PI * _this->radius * _this->radius;
}

void Circle_print(Circle *_this)
{
    cout << _this->name << "("<<_this->radius << ") : " << Circle_area(_this) << endl;
    // cout << std::format("{}({}) : {:.2f}", _this->name, _this->radius, Circle_area(_this)) << endl;
}

void Circle_draw(Circle *_this)
{
    cout << "Circle draw" << endl;
}

VirtualTableEntry Circle_VTable[] = {
    {.double_method = (double_method_type)Circle_area},
    {.void_method = (void_method_type)Circle_print},
    {.void_method = (void_method_type)Circle_draw}};

Circle *Circle_Circle(Circle *_this, string name, int radius)
{
    Shape_Shape((Shape *)_this, name);
    _this->VPointer = Circle_VTable;
    _this->radius = radius;
    _this->name = name;
    return _this;
}

struct Square
{
    VTableType VPointer;
    string name;
    int length;
    
};

double Square_area(Square *_this)
{
    return _this->length * _this->length;
}

void Square_print(Square *_this)
{
    // cout << "Square print" << endl;
    cout << _this->name << "("<<_this->length << ") : " << Square_area(_this) << endl;
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
    {.void_method = (void_method_type)Square_print},
    {.void_method = (void_method_type)Square_draw},
    {.int_method = (int_method_type)Square_get_length}};

Square *Square_Square(Square *_this, string name, int length)
{
    Shape_Shape((Shape *)_this, name);
    _this->VPointer = Square_VTable;
    _this->length = length;
    // _this->name = name;
    return _this;
}

struct Rectangle
{
    VTableType VPointer;
    string name;
    int length;
    int width;
    
};

double Rectangle_area(Rectangle *_this)
{
    int length = ((Square *)_this)->VPointer[GET_INDEX].int_method((Square *)_this);
    return _this->width * length;
}

void Rectangle_print(Rectangle *_this)
{
    cout << _this->name << "("<<_this->length << ", " << _this->width << ") : " << Rectangle_area(_this) << endl;
}

void Rectangle_draw(Rectangle *_this)
{
    cout << "Rectangle draw" << endl;
}

VirtualTableEntry Rectangle_VTable[] = {
    {.double_method = (double_method_type)Rectangle_area},
    {.void_method = (void_method_type)Rectangle_print},
    {.void_method = (void_method_type)Rectangle_draw},
    {.int_method = (int_method_type)Square_get_length}};

Rectangle *Rectangle_Rectangle(Rectangle *_this, string name, int length, int width)
{
    Square_Square((Square *)_this, name, length);
    _this->VPointer = Rectangle_VTable;
    _this->width = width;
    _this->length = length;
    return _this;
}

struct Triangle
{
    VTableType VPointer;
    string name;
    int length;
    int height;
};

double Triangle_area(Triangle *_this)
{
    return 0.5 * _this->length * _this->height;
}

void Triangle_print(Triangle *_this)
{
    cout << _this->name << "("<<_this->length << ", " << _this->height << ") : " << Triangle_area(_this) << endl;
}

void Triangle_draw(Triangle *_this)
{
    cout << "Triangle draw" << endl;
}

VirtualTableEntry Triangle_VTable[] = {
    {.double_method = (double_method_type)Triangle_area},
    {.void_method = (void_method_type)Triangle_print},
    {.void_method = (void_method_type)Triangle_draw}};

Triangle *Triangle_Triangle(Triangle *_this, string name, int length, int height)
{
    Shape_Shape((Shape *)_this, name);
    _this->VPointer = Triangle_VTable;
    _this->length = length;
    _this->height = height;
    // _this->width = width;
    // _this->name = name;
    return _this;
}

void printAll(Shape *arr[], int length)
{
    // cout << "IN PRINT ALL" << endl;
    for (int i = 0; i < length; i++)
    {
        (arr[i]->VPointer[PRINT_INDEX]).void_method(arr[i]);
    }
}

void drawAll(Shape *arr[], int length)
{
    // cout << "IN draw ALL" << endl;
    for (int i = 0; i < length; i++)
    {
        arr[i]->VPointer[DRAW_INDEX].void_method(arr[i]);
    }
}

double totalArea(Shape *arr[], int length)
{
    // cout << "IN area ALL" << endl;
    double result = 0;
    for (int i = 0; i < length; i++)
    {
        result += arr[i]->VPointer[AREA_INDEX].double_method(arr[i]);
    }
    return result;
}

int main(int argc, char *argv[])
{

    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);

    Shape *arr[8] = {(Shape *)Triangle_Triangle((Triangle *)malloc(sizeof(Triangle)), "FirstTriangle", arg1, arg2),
                     (Shape *)Triangle_Triangle((Triangle *)malloc(sizeof(Triangle)), "SecondTriangle", arg1 - 1, arg2 - 1),
                     (Shape *)Circle_Circle((Circle *)malloc(sizeof(Circle)), "FirstCircle", arg1),
                     (Shape *)Circle_Circle((Circle *)malloc(sizeof(Circle)), "SecondCircle", arg1 - 1),
                     (Shape *)Square_Square((Square *)malloc(sizeof(Square)), "FirstSquare", arg1),
                     (Shape *)Square_Square((Square *)malloc(sizeof(Square)), "SecondSquare", arg1 - 1),
                     (Shape *)Rectangle_Rectangle((Rectangle *)malloc(sizeof(Rectangle)), "FirstRectangle", arg1, arg2),
                     (Shape *)Rectangle_Rectangle((Rectangle *)malloc(sizeof(Rectangle)), "SecondRectangle", arg1 - 1, arg2 - 1)};
    // Shape *arr[1];
    // Triangle *t = (Triangle *)malloc(sizeof(Triangle));
    // Triangle_Triangle(t, "First Triangle", arg1, arg2);

    // arr[0] = (Shape *)t;
    // cout << "im here" << endl;
    // arr[0] =
    // cout << "im here2" << endl;
    printAll(arr, 8);
    drawAll(arr, 8);
    cout << "Total : " << totalArea(arr, 8) << endl;
    return 0;
}
