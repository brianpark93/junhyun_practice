#include <iostream>
#include <string>
#include "./helper.h"

using namespace std;

int** r;
int** g; 
int** b;

int mixColor(int originalColor, int inputColor, float inputAlpha) {

    int newColor;
    newColor=inputColor*inputAlpha + originalColor *(1-inputAlpha);

    return newColor;
}

bool checkCircle(int cx,int cy,int rad,int j,int i) {

    if( ((j-cx)*(j-cx) + (i-cy)*(i-cy)) <= rad*rad ) return true;
    else return false;
}
bool checkRect(int x,int y,int width,int height,int j,int i) {

    if(j>=x && j<=x+width && i>=y && i<=y+height) return true;
    else return false;
}

void addRect(int x, int y, int width, int height, string color) {
    // Use color data!!
    int rVal, gVal, bVal;
    float aVal;
    if (color == "red") { rVal = 255; gVal = 0; bVal = 0; aVal = 0.2; }
    if (color == "green") { rVal = 0; gVal = 255; bVal = 0; aVal = 0.2; }
    if (color == "blue") { rVal = 0; gVal = 0; bVal = 255; aVal = 0.2; }

    // TODO
    for(int i = 0; i < 300; i++){
        for(int j = 0; j < 250; j++) 
        {   
            if (checkRect(x,y,width,height,j,i))
            {
                r[i][j] = mixColor(r[i][j],rVal,aVal);
                g[i][j] = mixColor(g[i][j],gVal,aVal);
                b[i][j] = mixColor(b[i][j],bVal,aVal);
            }
        }
    }

    return;
}

void addCircle(int cx, int cy, int rad, string color) {
    // Use color data!!
    int rVal, gVal, bVal;
    float aVal;
    if (color == "red") { rVal = 255; gVal = 0; bVal = 0; aVal = 0.2; }
    if (color == "green") { rVal = 0; gVal = 255; bVal = 0; aVal = 0.2; }
    if (color == "blue") { rVal = 0; gVal = 0; bVal = 255; aVal = 0.2; }

    // TODO
    for(int i = 0; i < 300; i++){
        for(int j = 0; j < 250; j++)
        {
            if (checkCircle(cx,cy,rad,j,i))
            {
                r[i][j] = mixColor(r[i][j],rVal,aVal);
                g[i][j] = mixColor(g[i][j],gVal,aVal);
                b[i][j] = mixColor(b[i][j],bVal,aVal);
            }
        }
    }


    return;
}

string pickColor() {
    string color;
    // TODO 
    cout<<"Pick Color (red, green, blue)"<<endl;
    
    while(1)
    {
        cout<<"color: ";
        cin>>color;
        if(color=="red")
        {
            break;
        }
        else if(color=="green")
        {
            break;
        }
        else if(color=="blue")
        {
            break;
        }
        else
        {
            cout<<"Invalid color..."<<endl;
        }
    }
    return color;
}


int main() {

    r = arrayAllocator();
    g = arrayAllocator();
    b = arrayAllocator();
    /**
     * Able to use these 2D array
     * access (n, m)-th element by calling arr[n][m]
     * each array holds the r / g / b value of each pixel
     * current value: 255 for every color & pixel
     */

    // TODO
    while(1)
    {
        cout << "Add shapes!!" << endl;
        cout << "1. Rect" << endl;
        cout << "2. Circle" << endl;
        cout << "3. Print" << endl;
        cout << "INPUT: ";
        int input;
        cin >> input;

        if (input==1)
        {
            int x, y, width, height;
            string color;

            cout<<"x: ";
            cin >> x;
            cout<<"y: ";
            cin >> y;
            cout<<"width: : ";
            cin >> width;
            cout<<"height : ";
            cin >> height;
            color=pickColor();
            addRect(x, y, width, height, color);
            cout<<"Rect added!!"<<endl;
    
        }
        else if (input==2)
        {
            int cx, cy, radius;
            string color;

            cout<<"cx: ";
            cin >> cx;
            cout<<"cy: ";
            cin >> cy;
            cout<<"radius: : ";
            cin >> radius;
            color=pickColor();
            addCircle(cx, cy, radius, color);
            cout<<"Circle added!!"<<endl;

        }
        else if (input==3)
        {
            cout<<"Printing..."<<endl;
            break;
        }
        else
        {
            cout<<"Invalid input..."<<endl;
        }
        

    }


    // END

    pixelGenerator(r, g, b);
    cout<<"processed"<<endl;
    return 0;
}