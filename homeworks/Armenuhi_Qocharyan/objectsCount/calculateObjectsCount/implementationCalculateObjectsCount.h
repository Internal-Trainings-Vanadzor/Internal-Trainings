
int CalculateObjectsCount::ObjectsCount (0);
	
CalculateObjectsCount::CalculateObjectsCount() {
    ++ ObjectsCount;
    std::cout << "Count of objects is " << ObjectsCount << "\n";
}
	
CalculateObjectsCount::CalculateObjectsCount(CalculateObjectsCount& object){
    ++ ObjectsCount;
    std::cout << "Count of objects is " << ObjectsCount << "\n";
}

	
int CalculateObjectsCount::getCount() {
   std::cout << "Count of objects is " << ObjectsCount << "\n";
   return CalculateObjectsCount::ObjectsCount;
}

CalculateObjectsCount::~CalculateObjectsCount() {
    -- ObjectsCount;
    std::cout << "Count of objects is " << ObjectsCount << "\n";
}
