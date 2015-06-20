class A {
    private:
        static unsigned long s_instances_count;

    public:
        A();
        A(const A& obj);
        ~A();
        
        static unsigned long getInstancesCount();
};
