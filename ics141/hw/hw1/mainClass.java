
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
        System.out.println("*circle*");
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
        System.out.println("*square*");
    }

    int get_length(){
        return this.length; 
    }
}

class Rectangle extends Square{
    private int width ;

    public Rectangle(String name, int length, int width) {
        super(name,length);
        this.width = width; 
    }

    @Override
    void print() {
        String name = this.get_name();
        String result = String.format("%s(%d, %d) : %f:.2f", name, this.get_length(), this.width, area());
        System.out.println(result);
    }

    @Override
    double area() {
        return this.get_length() * width;
    }

    @Override
    void draw() {
        System.out.println("*rectangle*");
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
        String result = String.format("%s(%d, %d) : %f:.2f", name, height, length, area());
        System.out.println(result);
    }

    @Override
    double area() {
        return 0.5 * height * length;
    }

    @Override
    void draw() {
        System.out.println("*triangle*");
    }

}

class Picture {
    ListNode head; 

    Picture(){
        this.head = null; 
    }

    void add(Shape sh){ head = new ListNode(sh, head); }

    void printAll(){
        while (head != null){
            System.out.print("hi");
            head.info.print();
            head = head.next;
        }
    }

    void drawAll(){
        while (head != null){
            head.info.draw();
            head = head.next;
        }
    }

    double totalArea(){
        double sum = 0; 

        while (head != null){
            sum += head.info.area();
            head = head.next; 
        }
        return sum; 
    }
}

class ListNode{
    Shape info;
    ListNode next; 
    
    ListNode(Shape info, ListNode next){
        this.info = info; 
        this.next = next; 
    }


}

public class mainClass {
    public static void main(String[] args) {
        Picture pic = new Picture();
        Triangle t1 = new Triangle("FirstTriangle", 5, 5);
        Triangle t2 = new Triangle("SecondTriangle", 4, 4);

        Circle c1 = new Circle("FirstCircle", 5);
        Circle c2 = new Circle("SecondCircle", 4);

        Square s1 = new Square("FirstSquare", 5);
        Square s2 = new Square("SecondSquare", 4);

        Rectangle r1 = new Rectangle("FirstRectangle" , 5, 5);
        Rectangle r2 = new Rectangle("SecondRectangle" , 4, 4);

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
        pic.totalArea();
    }
}
