package aaaa;

public class PairClass2<F extends Comparable<F>,S extends Comparable<S>> implements Comparable<PairClass2<F, S>> {
	private F item1; 
	private S item2;
	
	public PairClass2(F a, S b){
		item1 = a;
		item2 = b;
	}
	public F getItem1(){return item1;}
	public S getItem2(){return item2;}
	
	@Override
	public int compareTo(PairClass2<F, S> o) {
		int a =item1.compareTo(o.getItem1());
		int b= item2.compareTo(o.getItem2());
		if(a==1)return 1;
		else if(a==-1) return -1;
		else if(b==1) return 1;
		else if(b==-1) return -1;
		return 0;
		}

}
