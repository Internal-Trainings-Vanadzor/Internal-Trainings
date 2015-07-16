
template<class Y>
struct auto_ptr_ref {
    explicit auto_ptr_ref(Y* p):ptr(p){
    
    }

    Y* ptr;
};


template <class X>
class auto_ptr {

    public:
        explicit auto_ptr(X* p = 0){
            std::cout << "constructor" << std::endl;
            ptr = new X();
            ptr = p;
        };

        auto_ptr(auto_ptr& a) {
            std::cout << "copy constructor" << std::endl;
            ptr = a.ptr;
            a.ptr = 0;
        }
        
        template<class Y> auto_ptr(auto_ptr<Y>& a){
            std::cout << "copy constructor 2" << std::endl;
            ptr = a.ptr;
            a.ptr = 0;
        }

        ~auto_ptr(){
            std::cout << "destructor" << std::endl;
            delete ptr;
        }
        X* get() const{
            return ptr;
        }

        X& operator*() const{
            return *ptr;
        }

        X* operator->() const{
            return ptr;
        }
        auto_ptr& operator= (auto_ptr& rhs){
            if(this != &rhs) {
            delete ptr;
            ptr = rhs.ptr;
            rhs.ptr = 0;
            }
            std::cout << "assignment operator" << std::endl;
            return *this;
        }

        template<class Y> auto_ptr& operator=(auto_ptr<Y>& rhs){
            if(this != &rhs) {
            delete ptr;
            ptr = rhs.ptr;
            rhs.ptr = 0;
            }
            std::cout << "assignment operator 2" << std::endl;
            return *this;
        }

        X* release(){
            X* tmp = ptr;
            ptr = 0;
            return tmp;
        }
        void reset(X* p = 0){
            if(p != ptr){
                delete ptr;
                ptr = p;
            }
        }
//conversions
        auto_ptr(auto_ptr_ref<X> ref) {
            ptr = ref.ptr;
            std::cout << "conversion 1" << std::endl;
        }
        
        auto_ptr& operator=(auto_ptr_ref<X> ref){
            if(ref.ptr != this->get()){
                delete ptr;
                ptr = ref.ptr;
            }
            std::cout << "conversion 2" << std::endl;
            return *this;
        }
        
        template<class Y> operator auto_ptr_ref <Y>() {
            std::cout << "conversion 3" << std::endl;
            return auto_ptr_ref<Y>(this->release());
        }
        
        template<class Y> operator auto_ptr <Y>() {
            std::cout << "conversion 4" << std::endl;
            return auto_ptr<Y>(this->release());
        }
        
    private:
        X* ptr;
};
