#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>

void algorithm_bresenham(int x1, int y1, int x2, int y2)
{
    std::vector<int>Xs;
    std::vector<int>Ys;
    int x = x1;
    int y = y1;
    //calculate differences in xs and ys of the two coordinates
    int dx = x2 - x;
    int dy = y2 - y;
    if (dx >= 0 && dy >= 0) //positive slope where both x and y are increasing
    {
        int p = 2 * dx - dy; //p is the decision variable
        while (x <= x2) //sampling x values until reach end point of line
        {
            Xs.push_back(x);
            Ys.push_back(y);

            x++;
            if (p < 0) //if statement calculates the new value of position variable
            {
                p = p + 2 * dy;
            }
            else
            {
                p = p + 2 * dy - 2 * dx;
                y++;
            }
        }
    }
    else if (dx < 0 && dy >= 0) //negative slope where x is decreasing
    {
        //translate points to origin and reflect in y axis (x coordinates' sign flips)
        int tempx1 = 0;
        int tempy1 = 0;
        int tempx2 = -(x2 - x);
        int tempy2 = y2 - y;
        //calculate new dx and dy
        dx = tempx2 - tempx1;
        dy = tempy2 - tempy1;
        //perform bresenhams algorithm
        int p = 2 * dx - dy; //decision variable
        while (tempx1 <= tempx2)
        {
            Xs.push_back(tempx1);
            Ys.push_back(tempy1);

            tempx1++;
            if (p < 0) //if statement calculates the new value of position variable
            {
                p = p + 2 * dy;
            }
            else
            {
                p = p + 2 * dy - 2 * dx;
                tempy1++;
            }
        }
        //flip signs of x coordinates then translate back
        for (int i = 0; i < Xs.size(); i++)
        {
            Xs[i] = ((-(Xs[i])) + x);
        }
        //translate the y coordinates back
        for (int j = 0; j < Ys.size(); j++)
        {
            Ys[j] = Ys[j] + y;
        }
    }
    else if (dy < 0 && dx >= 0) //negative slope where y is decreasing
    {
        //translate points to origin and reflect in y axis (x coordinates' sign flips)
        int tempx1 = 0;
        int tempy1 = 0;
        int tempx2 = x2 - x;
        int tempy2 = -(y2 - y);
        //calculate new dx and dy
        dx = tempx2 - tempx1;
        dy = tempy2 - tempy1;
        //perform bresenhams algorithm
        int p = 2 * dx - dy; //decision variable
        while (tempx1 <= tempx2)
        {
            Xs.push_back(tempx1);
            Ys.push_back(tempy1);

            tempx1++;
            if (p < 0) //if statement calculates the new value of position variable
            {
                p = p + 2 * dy;
            }
            else
            {
                p = p + 2 * dy - 2 * dx;
                tempy1++;
            }
        }
        //flip signs of y coordinates then translate back
        for (int i = 0; i < Ys.size(); i++)
        {
            Ys[i] = ((-(Ys[i])) + y);
        }
        //translate the x coordinates back
        for (int j = 0; j < Xs.size(); j++)
        {
            Xs[j] = Xs[j] + x;
        }
    }
    else //positive slope where both x and y are decreasing
    {
        //translate points to origin and reflect in x and y axis (x and y coordinates' sign flips)
        int tempx1 = 0;
        int tempy1 = 0;
        int tempx2 = -(x2 - x);
        int tempy2 = -(y2 - y);
        //calculate new dx and dy
        dx = tempx2 - tempx1;
        dy = tempy2 - tempy1;
        //perform bresenhams algorithm
        int p = 2 * dx - dy; //decision variable
        while (tempx1 <= tempx2)
        {
            Xs.push_back(tempx1);
            Ys.push_back(tempy1);

            tempx1++;
            if (p < 0) //if statement calculates the new value of position variable
            {
                p = p + 2 * dy;
            }
            else
            {
                p = p + 2 * dy - 2 * dx;
                tempy1++;
            }
        }
        //flip signs of x coordinates then translate back
        for (int i = 0; i < Xs.size(); i++)
        {
            Xs[i] = ((-(Xs[i])) + x);
        }
        //flip signs of y coordinates then translate back
        for (int j = 0; j < Ys.size(); j++)
        {
            Ys[j] = ((-(Ys[j])) + y);
        }
    }

    //print results
    std::cout << "X = [";
    for (int i = Xs.size()-1; i >= 0; i--)
    {
        std::cout << Xs[i] << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Y = [";
    for (int i = Ys.size() - 1; i >= 0; i--)
    {
        std::cout << Ys[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void rotate(double point[3], float angle, char axis)
{
    double x = point[0];
    double y = point[1];
    double z = point[2];
    float theta = angle * 3.141592653589793 / 180; //converts from degrees to radians
    float sin_theta = sin(theta);
    float cos_theta = cos(theta);
    std::cout << "Using right-handed rule, rotate (" << x << "," << y << "," << z << ") " << angle << " degrees about " << axis << "-axis: " << std::endl;
    switch (axis)
    {
    case 'x': //rotate about x-axis
        point[0] = x;
        point[1] = y * cos_theta - z * sin_theta;
        point[2] = y * sin_theta + z * cos_theta;
        break;
    case 'y': //rotate about y-axis
        point[0] = x * cos_theta + z * sin_theta;
        point[1] = y;
        point[2] = -x * sin_theta + 2 * cos_theta;
        break;
    case 'z': //rotate about z-axis
        point[0] = x * cos_theta - y * sin_theta;
        point[1] = x * sin_theta + y * cos_theta;
        point[2] = z;
        break;
    }
    std::cout << "New point: " << std::endl << "(" << point[0] << ", " << point[1] << ", " << point[2] << ")" << std::endl;
}

int main()
{
    std::cout << "Plotting using Bresenham's line-drawing algorithm: " << std::endl;
    float x1;
    float y1;
    float x2;
    float y2;
    char input1;
    bool flag1 = true;
    while (flag1 == true)
    {
        std::cout << "Please enter the x and y coordinates of your two points: " << std::endl;
        std::cout << "X1: ";
        std::cin >> x1;
        std::cout << "Y1: ";
        std::cin >> y1;
        std::cout << "X2: ";
        std::cin >> x2;
        std::cout << "Y2: ";
        std::cin >> y2;
        algorithm_bresenham(x1, y1, x2, y2);
        std::cout << "Would you like to use Bresenham's line-drawing algorithm again? (y/n): ";
        std::cin >> input1;
        if (input1 == 'n')
        {
            flag1 = false;
        }
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Performing a sequence of 3D matrix transformations in the right-handed coordinate system: " << std::endl;
    double point[3];
    float angle;
    char axis;
    char input2;
    bool flag2 = true;
    while (flag2 == true)
    {
        std::cout << "Please enter the x, y, z coordinates of your point: " << std::endl;
        std::cout << "X: ";
        std::cin >> point[0];
        std::cout << "Y: "; 
        std::cin >> point[1];
        std::cout << "Z: ";
        std::cin >> point[2];

        std::cout << "Please enter the angle in degrees that you want the angle to be rotated by: " << std::endl;
        std::cin >> angle;

        std::cout << "Please enter the letter of the axis you want the point to be rotated about: " << std::endl;
        std::cin >> axis;

        rotate(point, angle, axis);

        std::cout << "Would you like to roate another point (y/n): ";
        std::cin >> input2;
        if (input2 == 'n')
        {
            flag2 = false;
        }
    }

    return 0;
}