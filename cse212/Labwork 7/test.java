package aaaa;

public class test {

	public static void main(String[] args){
		PairClass2<String,String> c1 = new PairClass2<>("a", "b");
		PairClass2<String,String> c2 = new PairClass2<>("a", "b");
		PairClass2<String,String> c3 = new PairClass2<>("a", "c");
		PairClass2<String,String> c4 = new PairClass2<>("a", "a");
		
		PairClass2<Integer,String> c21 = new PairClass2<>(1, "b");
		PairClass2<Integer,String> c22 = new PairClass2<>(1, "b");
		PairClass2<Integer,String> c23 = new PairClass2<>(1, "c");
		PairClass2<Integer,String> c24 = new PairClass2<>(1, "a");
		
		System.out.println(c1.compareTo(c2));
		System.out.println(c1.compareTo(c3));
		System.out.println(c1.compareTo(c4));
		
		System.out.println(c21.compareTo(c22));
		System.out.println(c21.compareTo(c23));
		System.out.println(c21.compareTo(c24));

		
	}
}
