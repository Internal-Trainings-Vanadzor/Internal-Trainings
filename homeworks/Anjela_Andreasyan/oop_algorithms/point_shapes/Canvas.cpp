#include <iostream>
#include "Canvas.hpp"

using std::cout;

Canvas::Canvas():pointsMatrix(0), canv_height(40), canv_width(40){
    pointsMatrix = new bool*[canv_height];
    for(int i = 0; i < canv_height; i++){
        pointsMatrix[i]= new bool[canv_width];
        for(int j = 0; j< canv_width; j++){
            pointsMatrix[i][j]=0;
        }
    }
    setupCanvas();
}

Canvas::Canvas(int height, int width): pointsMatrix(0), canv_height(height), canv_width(width){
    pointsMatrix = new bool*[canv_height];
    for(int i = 0; i < canv_height; i++){
        pointsMatrix[i]= new bool[canv_width];
        for(int j = 0; j< canv_width; j++){
            pointsMatrix[i][j]=0;
        }
    }
    setupCanvas();
}

Canvas::~Canvas(){
    delete[] pointsMatrix;
}

void Canvas::setupCanvas(){
    for (int i=0; i<canv_height; i++){
        pointsMatrix[i][1] = 1;
    }
    for (int j=0; j<canv_width; j++){
        pointsMatrix[canv_height -2][j] = 1;
    }
}

const void Canvas::pointComponent(){
    cout<<"\n";
    for(int i = 0; i< canv_height; i++){
        for(int j=0; j< canv_width; j++){
            if(0 == pointsMatrix[i][j]){
                cout<<" ";
            }else{
                cout<<"* ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}

const void Canvas::drawLine(Line line){
    cout<<"Not implemented yet.";
    //TODO
}

const void Canvas::drawRect(Rect rect){
    cout<<"Not implemented yet.";
    //TODO
}

