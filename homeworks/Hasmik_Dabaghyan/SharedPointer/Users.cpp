#include <iostream>
#include "SharedPointer.hpp"
class Users 
{
private:
	int usersCount;
public:
	Users(int count)
	{
		usersCount = count;
	}
	void showUsersCount()
	{
		std::cout<<"Users count is: "<<usersCount<<std::endl;
	}
    ~Users()
    {
		std::cout<<"Users destructor is invoked....\n";
    }
};
template <class Users> int SharedPointer<Users>::count=0; 
int main(){
	SharedPointer<Users> obj(new Users(25));
	obj->showUsersCount();
    std::cout<<"Pointers count is: " << SharedPointer<Users>::count<<std::endl;
	{
		SharedPointer<Users> obj1 = obj;
		obj1->showUsersCount();
        std::cout<<"Pointers count is: " << SharedPointer<Users>::count<<std::endl;
        SharedPointer<Users> obj2;
        obj2 = obj;
        obj2->showUsersCount();
        std::cout<<"Pointers count is: " << SharedPointer<Users>::count<<std::endl;
	}
        std::cout<<"Pointers count is: " << SharedPointer<Users>::count<<std::endl;
	obj->showUsersCount();
	return 0;
}
