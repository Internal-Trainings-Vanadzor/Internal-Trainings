class Circle {
    static int counter;
    public:
    Circle(){
        counter++;
        std::cout<<"The number of the objects is "<<counter<<"\n";
    }
    ~Circle(){
        counter--;
        std::cout<<"The number of the objects is "<<counter<<"\n";
    }
   int getCounter(){
       return counter; 
   }
};
