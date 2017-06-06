package aaaa;

public class PairClass<T> {
	private T item1;
	private T item2;
	
	public PairClass(T t1, T t2){
		item1=t1;
		item2=t2;
	}
	
	public T getItem1(){ return item1;}
	public T getItem2(){ return item2;}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return item1+" "+item2;
	}
}
