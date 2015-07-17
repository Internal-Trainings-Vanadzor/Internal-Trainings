public class Main {
	public static void main(String[] args) {
  	start();
	}

	private static void start() {
		DynamicArray array = new DynamicArray();
		for (int i = 11; i < 16; i++) {
			array.add(i);
		}
		array.set(2,23);
		array.insert(3, 20);
		for (int i = 0; i < 6; i++) {
		System.out.println("after set and insert "+array.getArray()[i]);
		}
		array.remove(2);
		for (int i = 0; i < 5; i++) {
			System.out.println("after remove "+array.getArray()[i]);
			}
		array.clear();
		System.out.println("size "+array.size());
	}
}

