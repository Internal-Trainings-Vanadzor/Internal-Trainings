#ifndef SORT_HPP
#define SORT_HPP

class SortShapes{
    public:
        template <class Shape> void bubbleSort(Shape *shapes, int count) {
            for(int i=1; i<count; i++){
                for(int j=count-1; j>=i; j--){
                    if(shapes[j-1].area() > shapes[j].area()) {
                        Shape temp = shapes[j-1];
                        shapes[j-1] = shapes[j];
                        shapes[j] = temp;
                    }
                }
            }
        }

};

#endif
