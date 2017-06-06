
import java.util.Scanner;



public class Client {
	private String name;
	private String lastName;
	private int age;
	private long id;
	private String phoneNumber;



	public static void main(String[] args) {
		Client c = new Client();
		Scanner s = new Scanner(System.in);
		while (true) {
			try {
				System.out.print("name:");
				c.setName(s.nextLine());
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
				s.nextLine();
			}

		}

		while (true) {
			try {
				System.out.print("surname:");
				c.setLastName(s.nextLine());
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
				s.nextLine();
			}

		}


		while (true) {
			try {
				System.out.print("age:");
				c.setAge(s.nextInt());
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
				s.nextLine();
				
			}

		}

		while(true){
			try {
				System.out.print("id:");
				c.setId(s.nextLong());
				s.nextLine();
				break;
			} catch (IDMismatchException e) {

				System.out.println(e.getMessage());
				s.nextLine();

			}
		}

		while (true) {
			try {
				System.out.print("phone number:");
				c.setPhoneNumber(s.nextLine());
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
				s.nextLine();
				
			}

		}



	}


	private void  checkPhone(String x) throws InvalidPhoneException{
		if(x.length()>12||x.length()<10) throw new InvalidPhoneException();
		if(x.length()==10){
			if(x.charAt(0)==0)throw new InvalidPhoneException();
			for (char c :x.toCharArray()) {
				if(!Character.isDigit(c))throw new InvalidPhoneException();
			}
			return;
		}
		else if(x.length()==11){
			if(x.charAt(0)==0){
				for (char c :x.toCharArray()) {
					if(!Character.isDigit(c))throw new InvalidPhoneException();
				}
				return;
			}
			else if(x.charAt(3)=='-'){
				for(int i=0; i<x.length();i++){
					if(i==3)i++;
					char c = x.charAt(i);
					if(!Character.isDigit(c))throw new InvalidPhoneException();
				}
				return;
			}
		}
		else if(x.length()==12){
			if(x.charAt(0)!=0)throw new InvalidPhoneException();
			if(x.charAt(4)!='-')throw new InvalidPhoneException();
			for(int i=0; i<x.length();i++){
				if(i==4)i++;
				char c = x.charAt(i);
				if(!Character.isDigit(c))throw new InvalidPhoneException();
			}
			return;
		}

	}
	
	private void chechAge(int age){
		if(age<20 || age>99) {
			throw new IllegalArgumentException("age must be between 20 and 99");
		}
	}


	public String getName() {
		return name;
	}



	public void setName(String name) {
		this.name = name;
	}



	public String getLastName() {
		return lastName;
	}



	public void setLastName(String lastName) {
		this.lastName = lastName;
	}



	public int getAge() {
		return age;
	}



	public void setAge(int age) {

		this.chechAge(age);
		this.age = age;


	}







	public String getPhoneNumber() {
		return phoneNumber;
	}



	public void setPhoneNumber(String phoneNumber) throws InvalidPhoneException {

		checkPhone(phoneNumber);
		this.phoneNumber = phoneNumber;


	}

	public long getId() {
		return id;
	}

	public void setId(long id) throws IDMismatchException {

		this.authenticateID(id);
		this.id = id;



	}


	private void authenticateID(long id) throws IDMismatchException {
		int length = 0;
		int[] n = new int [11];
		
		while(length<11){
			n[10-length]=(int) (id%10);
			id/=10;
			length++;
		}
		

		
		if(id>0) throw new IDMismatchException();
		if(n[9]!=(7*(n[0]+n[2]+n[4]+n[6]+n[8])-(n[1]+n[3]+n[5]+n[7]))%10)throw new IDMismatchException();
		if(n[10]!=(n[0]+n[1]+n[2]+n[3]+n[4]+n[5]+n[6]+n[7]+n[8]+n[9])%10) throw new IDMismatchException();
		
	}


	public class IDMismatchException extends Exception {
		public IDMismatchException() {
			super("IDMismatchException");
		}

	}

	public class InvalidPhoneException extends Exception{
		public InvalidPhoneException(){
			super("InvalidPhoneException");
		}
	}





}
