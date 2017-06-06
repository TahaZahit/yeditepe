import java.io.Serializable;

public class Person implements Serializable {
    public String name;
    public String surname;
    public boolean[] meritalStatus;
    public boolean[] interest;

    public Person (String n, String s, boolean[] m, boolean[] i) {
        name = n;
        surname = s;
        meritalStatus = m;
        interest = i;
    }
}
