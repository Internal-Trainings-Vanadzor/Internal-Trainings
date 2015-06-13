#ifndef MYCLASS_HPP
#define MYCLASS_HPP
/**
 * This is a class similar to auto_ptr
 */
class myClass {

    private:
        /**
         * The main member containing the pointer
         */
        int* ptr;

    public:
        /**
         * The constructor
         */
        myClass (int* n);
        
        /**
         * The copy-constructor
         */
        myClass (myClass& object);

        /**
         * The assignment operator
         */
        myClass& operator=(myClass& object);

         /**
          * The destructor
          */
        ~myClass ();

        /**
         * The function for getting the value of the pointer
         */
        int get_ptr_value();

        /**
         * The function for setting the value of the pointer
         */
        void set_ptr_value(int);

        /**
         * The function for printing the value of the pointer
         */
        void print_ptr_value();
};
#endif
