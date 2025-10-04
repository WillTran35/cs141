
class Shape {

    private String name;

    // private int length; 
    // private int width;
    Shape(String name) {
        // this.length = length;
        // this.width = width;
        this.name = name;
    }

    void print() {
        // String result = "";
        System.out.println("");
    }

    void draw() {
        System.out.println();
    }

    double area() {
        return 0;
    }

    String get_name() {
        return this.name;
    }
}

class Circle extends Shape {

    private int radius;
    static final double PI = 3.14;

    Circle(String name, int radius) {
        super(name);
        this.radius = radius;
    }

    @Override
    void print() {
        // FirstTriangle(5, 5) : 12.5
        String name = this.get_name();
        String result = String.format("%s(%d) : %f:.2f", name, radius, area());
        System.out.println(result);
    }

    @Override
    double area() {
        return PI * radius * radius;
    }

    @Override
    void draw() {

    }
}

class Square extends Shape {

    private int length;

    Square(String name, int length) {
        super(name);
        this.length = length;
    }

    @Override
    void print() {
        String name = this.get_name();
        String result = String.format("%s(%d) : %f:.2f", name, length, area());
        System.out.println(result);
    }

    @Override
    double area() {
        return length * length;
    }

    @Override
    void draw() {

    }
}

public class mainClass {

}
