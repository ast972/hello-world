#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Shape
{
public:
    Shape(int width, int height) : 
        width_{ width }, height_{ height }
    {
    }
    // pure virtual function
    virtual void description() = 0;

    virtual int area() const {
        cout << "Shape::area" << endl;

        return 0;
    }

protected:
    int width_, height_;
};

class Rectangle : public Shape
{
public:
    Rectangle(int width, int height) : Shape{ width, height }
    {
    }

    void description() {
        cout << "This is Rectangle";
    }

    int area() const override  
    {
        cout << "Rectangle::area" << endl;

        return width_ * height_;
    } 

private:


};

class Triangle : public Shape
{
public:
    Triangle(int width, int height, int color) : 
        Shape{ width, height }, color_{ color }
    {
    }

    void description() {
        cout << "This is Rectangle";
    }

    int area() const override
    {
        cout << "Triangle::area" << endl;

        return width_ * height_ / 2;
    }
    int color() const {
        return color_;
    }

private:
    int color_;

};

/*class Circle : public Shape
{


};*/

/*void print(const Rectangle& rect)
{
    cout << "Rectangle" << endl;
    cout << "Area is: " << rect.area() << endl;
}

void print(const Triangle& triangle)
{
    cout << "Triangle" << endl;
    cout << "Area is: " << triangle.area() << endl;
}*/

void print(Shape* shape)
{
    //cout << "Triangle" << endl;
    cout << "Area is: " << shape->area() << endl;
}


int main()
{
    Rectangle rect{ 3, 7 };
    Triangle triangle{ 3, 7, 99 };

   // print(rect);
   // print(triangle);

    Shape* shape = &rect;
     print(shape);
    shape = &triangle;
    print(shape);

   
    vector<Shape*> shapes; // if you want to use polymorphism, you do vector<Shape*> and not vector<Shape>
                           // you could do vector<Rectangle> or vector<Triangles> as arrays of plain objects  
    shapes.push_back(new Rectangle{33, 6});
    shapes.push_back(new Triangle{ 33, 6, 110 });
    shapes.push_back(new Rectangle{ 313, 62 });

    for (auto shape : shapes)
        print(shape);

    for (auto shape : shapes)
        delete shape;

    shapes.clear();

    // - When you need have ownership of the object => use unique_ptr
    // - If you need to refer/point only to an existing object and not
    // owning it, then use raw pointing.
    {
        vector<unique_ptr<Shape>> shapes;
        shapes.push_back(unique_ptr<Shape>{ new Rectangle{ 33, 6 } });
        shapes.push_back(unique_ptr<Shape>{ new Triangle{ 33, 6, 110 } });
        shapes.push_back(unique_ptr<Shape>{ new Rectangle{ 313, 62 }});
    }
    {
        vector<unique_ptr<Shape>> shapes;
        shapes.push_back(make_unique<Rectangle>( 33, 6 ));
        shapes.push_back(make_unique<Triangle>( 33, 6, 110));
        shapes.push_back(make_unique<Rectangle>( 313, 62 ));

    }
    //
    /*Shape* s1 = new Rectangle{ 33, 6 };
    Shape* s2 = s1;

    delete s1;

    s2->area();*/

    ///
    unique_ptr<Shape> shape{new  Rectangle{33, 6}};
    shape->area();


    unique_ptr<Shape> shape = make_unique<Rectangle>(33, 6);

    //unique_ptr<Shape> p = shape;

    vector<Rectangle> rectangles;
    rectangles.push_back(Rectangle{ 33, 6 });

    return 0;
}

