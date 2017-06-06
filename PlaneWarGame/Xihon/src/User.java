import java.io.*;
import java.util.LinkedList;

public class User implements Serializable, Comparable<User> {
    private static LinkedList<User> _userList;

    private String _name;
    private String _password;
    private int _highscore;

    public User(String name, String password, int highscore) {
        _name = name;
        _password = password;
        _highscore = highscore;
    }

    public static void UpdateHighscore(User user, int newscore) {
        user.set_highscore(newscore);
        Save();
    }

    public static User RegisterUser(String name, String password) {
        if (_userList == null) Load();
        User existUser = null;
        for (User u : _userList) {
            if (u.get_name().equals(name)) {
                existUser = u;
                break;
            }
        }
        if (existUser != null)
            return null; // user  name exists. input different name.
        User user = new User(name, password, 0);
        _userList.add(user);
        Save();
        return user;
    }

    public static User Login(String name, String password) {
        if (_userList == null) Load();
        User user = null;
        for (User u : _userList) {
            if (u.get_name().equals(name) && u.get_password().equals(password)) {
                user = u;
                break;
            }
        }
        return user;
    }

    public static LinkedList<User> TopScores(int n) {
        if (_userList == null) Load();
        _userList.sort((left, right) -> left.get_highscore() > right.get_highscore() ? 1 : 0);
        LinkedList<User> list = new LinkedList<>();
        int m = n > _userList.size() ? _userList.size() : n;
        for (int i = 0; i < m; i++) {
            list.add(_userList.get(i));
        }
        return list;
    }

    public static void Save() {
        try {
            ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("scores.dat"));
            out.writeObject(_userList);
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void Load() {
        try {
            ObjectInputStream in = new ObjectInputStream(new FileInputStream("scores.dat"));
            _userList = (LinkedList<User>) in.readObject();
            in.close();
        } catch (IOException | ClassNotFoundException e) {
            _userList = new LinkedList<User>();
        }
    }

    public String get_name() {
        return _name;
    }

    public void set_name(String value) {
        _name = value;
    }

    public String get_password() {
        return _password;
    }

    public void set_password(String value) {
        _password = value;
    }

    public int get_highscore() {
        return _highscore;
    }

    public void set_highscore(int value) {
        _highscore = value;
    }

    @Override
    public int compareTo(User o) {

        if (this._highscore > o._highscore) return -1;
        else if (this._highscore < o._highscore) return 1;
        return 0;
    }
}
