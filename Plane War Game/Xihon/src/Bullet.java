import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import javax.sound.sampled.Clip;

public class Bullet extends Entity<Double> {
    private double dx;
    private double dy;
    private int r;
    private boolean friendly;
    private BufferedImage bi;

    Bullet(int angle, int x, int y, boolean friendly) {
        bi = friendly ? Tools.fire0 : Tools.fire1;
        this.x = (double) x;
        this.y = (double) y;
        speed = 9;
        r = 4;
        double rad = Math.toRadians(angle - 90);
        dx = (Math.cos(rad) * speed);
        dy = (Math.sin(rad) * speed);
        isLive = true;
        this.friendly = friendly;
        Clip shoot0 = Tools.audioLoader("/res/shoot0.wav");
        shoot0.start();
    }

    //main functions
    public void update() {
        x += dx;
        y += dy;
        checkForCollision();
    }

    public void draw(Graphics2D g) {
        g.drawImage(bi, (int) x.doubleValue() - r, (int) (y - r), null);
    }

    private void checkForCollision() {
        if (x > GamePanel.WIDTH || x < 0 || y > GamePanel.HEIGHT || y < 0) isLive = false;
    }

    public boolean isFriendly() {
        return friendly;
    }
}