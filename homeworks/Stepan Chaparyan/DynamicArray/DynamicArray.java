import java.util.Arrays;
 
public class DynamicArray
{
  // The storage for the elements. 
  // The capacity is the length of this array.
  private int[] data;
   
  // The number of elements (logical size).
  // It must be smaller than the capacity.
  private int size;
   
  // Constructs an empty DynamicArray
  public DynamicArray()   {
    data = new int[6];
    size = 0;
  }
   
  // Constructs an empty DynamicArray with the
  // specified initial capacity.
  public DynamicArray(int capacity) {
    if (capacity < 6)
    capacity = 6;
    data = new int[capacity];
    size = 0;
  }
   
  // Increases the capacity, if necessary
  private void ensureCapacity(int minCapacity) {
    int oldCapacity = data.length;
    if (minCapacity > oldCapacity)  {
      int newCapacity = (oldCapacity * 2);
      if (newCapacity < minCapacity)
        newCapacity = minCapacity;
		data = Arrays.copyOf(data, newCapacity);
	}
  }
   
  // Returns the logical size
  public int size() {
	  return size;
  }
    
  // Returns the element at the specified position.
  public int[] getArray () {
  	  return data;
  }
   
  // Appends the specified element to the end.
  public void add(int element) {
	  ensureCapacity(size + 1);
	  data[size++] = element;
  }
     
  // insert element
  public void insert(int index, int element) {
	  int[] tempData = data;
	  data = new int[data.length];
	  for (int i = 0; i < index; i++) {
		  data[i] = tempData[i];
	  }
	  data[index] = element;
	  for (int i = 0; i < (data.length-(index+1)); i++) {
		  data[(index+1)+i] = tempData[index+i];
	  }
  }
  
  // Replaces the element at the specified position
  public void set(int index, int element) {
	  data[index] = element;
  }
   
  // remove the element
  public void remove(int element) {
	  int[] tempData = data;
	  int newLength = data.length-1;
	  data = new int[newLength];
	  size = size-1;
	  for (int i=0; i < element; i++) {
		  data[i] = tempData[i];
	  }
	  for (int i = element; i < newLength; i++) {
	  	  data[i] = tempData[i+1]; 
	  }
  }
  	 		  
//Removes all of the elements.
  public void clear() {
	  size = 0;
	  data= new int[6];
  }
}
