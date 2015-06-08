#ifndef MYCLASS_HPP
#define MYCLASS_HPP
/**
 * This is a class which "knows" its current objects count
 */
class myClass {

    private:
        /**
         * The member containing the current objects count
         */
        static int count;

    public:
        /**
         * The constructor
         */
        myClass ();
        
        /**
         * The copy-constructor
         */
         myClass (myClass& object);

         /**
          * The destructor
          */
        ~myClass ();

        /**
         * The function for getting the current objects count
         */
        static int get_count(); 
};
#endif
