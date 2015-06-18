/*
 TODO
 */
package objectcounter;

public class ObjectCounter {

    private static int objectsCount = 0;

    public static void main(String[] args) {
        ObjectCounter obj1 = new ObjectCounter();
        System.out.println(obj1.getObjectsCount());

        ObjectCounter obj2 = new ObjectCounter();
        ObjectCounter obj3 = new ObjectCounter();

        System.out.println(obj2.getObjectsCount());
        System.out.println(obj3.getObjectsCount());

        System.out.println(ObjectCounter.objectsCount);
    }

    public ObjectCounter() {
        ++objectsCount;
    }

    int getObjectsCount() {
        return ObjectCounter.objectsCount;
    }
}
