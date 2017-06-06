import java.awt.*;

public class PowerUp extends Entity<Double> {

    private double dx;
    private double dy;
    private double rad;
    private int r;

    PowerUp(double angle, double x, double y) {
        this.x = x;
        this.y = y;
        speed = 4;
        r = 7;

        rad = Math.toRadians(angle - 90);

        dx = Math.cos(rad) * speed;
        dy = Math.sin(rad) * speed;

        isLive = true;
    }

    public void update() {
        x += dx;
        y += dy;
        checkForCollision();
    }

    public void draw(Graphics2D g) {
        g.setColor(Color.YELLOW);
        g.drawImage(Tools.up0, (int) x.doubleValue() - r, (int) y.doubleValue() - r, null);
    }

    private void checkForCollision() {
        if (x > GamePanel.WIDTH || x < 0 || y > GamePanel.HEIGHT || y < 0)
            isLive = false;
    }


}