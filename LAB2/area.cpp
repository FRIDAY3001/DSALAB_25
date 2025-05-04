//menu driven program to calculate area of square, cube, rectangle, cuboid
#include <iostream>


class Area {
    private:
    int length;
    int breadth;
    int height;
    
    
    public:
    Area()
    {length = 1;
    breadth = 1;
    height = 1;
    }


    void setlength(int l) {
        length = l;
    }

    void setbreadth(int b) {
        breadth = b;
    }

    void setheight(int h) {
        height = h;
    }


    int squareArea() {
        return length*length;
    }

    int cubeArea() {
        return length*length*6;
    }

    int rectangleArea() {
        return length*breadth;
    }

    int cuboidArea() {
        return 2*(length*breadth + breadth*height + length*height);
    }

};


int main() {
    int option;
    int l,b,h;
    Area area;

    area.setlength(l);
    area.setbreadth(b);
    area.setheight(h);


    while (1) {
        std::cout << "\nMenu:\n 1. Square\n 2. Cube\n 3. Rectangle\n 4. Cuboid\n 5. Exit\n";
        std::cin >> option;


        if ( option == 1) {    
            std::cout << "\nEnter length: ";
            std::cin >> l;  

            area.setlength(l);
           std::cout << area.squareArea();
        }

        if (option == 2) {
            std::cout << "\nEnter length: ";
            std::cin >> l;
            area.setlength(l);
            std::cout << area.cubeArea();
        }

        if (option == 3) {
            std::cout << "\nEnter length, breadth: ";
            std::cin >> l >> b;
            area.setlength(l);
            area.setbreadth(b);
            std::cout << area.rectangleArea();
        }

        if (option == 4) {
            std::cout << "\nEnter length, breadth and height: ";
            std::cin >> l >> b >> h;
            area.setlength(l);
            area.setbreadth(b);
            area.setheight(h);
            std::cout << area.cuboidArea();
        }

        if (option == 5) {
            break;
        }
    }

    return 0;
}