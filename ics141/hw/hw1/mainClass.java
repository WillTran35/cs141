
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
        String result = String.format("%s(%d) : %.2f", name, radius, area());
        System.out.println(result);
    }

    @Override
    double area() {
        return PI * radius * radius;
    }

    @Override
    void draw() {
        System.out.println("   ***   ");
        System.out.println(" *     * ");
        System.out.println("*       *");
        System.out.println(" *     * ");
        System.out.println("   ***   ");
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
        String result = String.format("%s(%d) : %.2f", name, length, area());
        System.out.println(result);
    }

    @Override
    double area() {
        return length * length;
    }

    @Override
    void draw() {
        System.out.println("*****");
        System.out.println("*****");
        System.out.println("*****");
        System.out.println("*****");
        System.out.println("*****");
    }

    int get_length() {
        return this.length;
    }
}

class Rectangle extends Square {

    private int width;

    public Rectangle(String name, int length, int width) {
        super(name, length);
        this.width = width;
    }

    @Override
    void print() {
        String name = this.get_name();
        String result = String.format("%s(%d, %d) : %.2f", name, this.get_length(), this.width, area());
        System.out.println(result);
    }

    @Override
    double area() {
        return this.get_length() * width;
    }

    @Override
    void draw() {
        System.out.println("*********");
        System.out.println("*       *");
        System.out.println("*       *");
        System.out.println("*       *");
        System.out.println("*********");
    }

}

class Triangle extends Shape {

    private int height;
    private int length;

    Triangle(String name, int height, int length) {
        super(name);
        this.height = height;
        this.length = length;

    }

    @Override
    void print() {
        String name = this.get_name();
        String result = String.format("%s(%d, %d) : %.2f", name, height, length, area());
        System.out.println(result);
    }

    @Override
    double area() {
        return 0.5 * height * length;
    }

    @Override
    void draw() {
        System.out.println("    *    ");
        System.out.println("   ***   ");
        System.out.println("  *****  ");
        System.out.println(" ******* ");
        System.out.println("*********");
    }

}

class Picture {

    ListNode head;

    Picture() {
        this.head = null;
    }

    void add(Shape sh) {
        head = new ListNode(sh, head);
    }

    void printAll() {
        ListNode copy = head;
        while (copy != null) {
            // System.out.print("hi");
            copy.info.print();
            copy = copy.next;
        }
    }

    void drawAll() {
        ListNode copy = head;
        while (copy != null) {
            copy.info.draw();
            copy = copy.next;
        }
    }

    double totalArea() {
        double sum = 0;
        ListNode copy = head;

        while (copy != null) {
            sum += copy.info.area();
            copy = copy.next;
        }
        return sum;
    }
}

class ListNode {

    Shape info;
    ListNode next;

    ListNode(Shape info, ListNode next) {
        this.info = info;
        this.next = next;
    }

}

public class mainClass {

    public static void main(String[] args) {
        int arg1 = Integer.parseInt(args[0]);
        int arg2 = Integer.parseInt(args[1]);

        Picture pic = new Picture();
        Triangle t1 = new Triangle("FirstTriangle", arg1, arg2);
        // System.out.println(t1.area());
        ;
        Triangle t2 = new Triangle("SecondTriangle", arg1 - 1, arg2 - 1);

        Circle c1 = new Circle("FirstCircle", arg1);
        Circle c2 = new Circle("SecondCircle", arg1 - 1);

        Square s1 = new Square("FirstSquare", arg1);
        Square s2 = new Square("SecondSquare", arg1 - 1);

        Rectangle r1 = new Rectangle("FirstRectangle", arg1, arg2);
        Rectangle r2 = new Rectangle("SecondRectangle", arg1-1, arg2-1);

        pic.add(t1);
        pic.add(t2);
        pic.add(c1);
        pic.add(c2);
        pic.add(s1);
        pic.add(s2);
        pic.add(r1);
        pic.add(r2);

        pic.printAll();
        pic.drawAll();
        System.out.println("Total : " + pic.totalArea());
    }
}
