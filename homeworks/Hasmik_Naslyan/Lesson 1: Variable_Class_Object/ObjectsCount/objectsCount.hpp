#ifndef OBJECTSCOUNT_HPP
#define OBJECTSCOUNT_HPP

class objectsCount {

    private:
        /**
         * The member containing the current objects count
         */
        static int counter;

    public:
        /**
         * The constructor
         */
        objectsCount ();
        
        /**
         * The copy-constructor
         */
         objectsCount (objectsCount& object);

         /**
          * The destructor
          */
        ~objectsCount ();
	static int getObjectsCount();

};
#endif
