import java.awt.*;

public abstract class Entity<T> {
    protected int speed;
    protected int type;
    protected int height;
    protected int width;
    protected T x;
    protected T y;
    protected int HP;
    protected boolean isLive;

    public abstract void update();

    public abstract void draw(Graphics2D g);

    public boolean isLive() {
        return isLive;
    }

    public boolean isDead() {
        return !isLive;
    }


    public T getX() {
        return x;
    }

    public T getY() {
        return y;
    }

    public int getHP() {
        return HP;
    }

    public int getType() {
        return type;
    }

    public void hurt() {
        HP--;
    }

}
