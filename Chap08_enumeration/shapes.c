#include <stdio.h>

const char* nameTriangle = "triangle";
const char* nameSquare = "square";
const char* nameRectangle = "rectangle";
const char* nameTrapezoid = "trapezoid";
const char* namePentagon = "pentagon";
const char* nameUnknown = "unknown";

enum shape
{
    triangle,
    square,
    rectangle,
    trapezoid,
    pentagon
};

void PrintShapeInfo(enum shape aShape);
const char* GetShapeName(enum shape aShape);

int main(void)
{
    PrintShapeInfo(triangle);
    PrintShapeInfo(square);
    PrintShapeInfo(rectangle);
    PrintShapeInfo(trapezoid);
    PrintShapeInfo(pentagon);

    return 0;
}

const char* GetShapeName(enum shape aShape)
{
    const char* name;
    switch (aShape)
    {
        case triangle:
            name = nameTriangle;
            break;
        case square:
            name = nameSquare;
            break;
        case rectangle:
            name = nameRectangle;
            break;
        case trapezoid:
            name = nameTrapezoid;
            break;
        default:
            name = nameUnknown;
            break;
    }
    return name;
}
void PrintShapeInfo(enum shape aShape)
{
    int nSides = 0;
    switch (aShape)
    {
        case triangle:
            nSides = 3;
            break;
        case square:
        case rectangle:
        case trapezoid:
            nSides = 4;
            break;
        default:
            printf("UNKNOWN SHAPE TYPE\n");
            return;
            break;
    }
    printf("A %s has %d sides\n",GetShapeName(aShape), nSides );
}
