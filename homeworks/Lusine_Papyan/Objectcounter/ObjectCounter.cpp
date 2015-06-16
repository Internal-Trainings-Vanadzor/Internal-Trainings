#include "ObjectCounter.h"

int ObjectCounter::s_object_counter = 0;

ObjectCounter::ObjectCounter() {
	++s_object_counter;
}

ObjectCounter::~ObjectCounter() {
	--++s_object_counter;
};