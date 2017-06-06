import javax.imageio.ImageIO;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.*;
import java.awt.image.BufferedImage;

public class Tools {
    public static BufferedImage background1 = imageLoader("/res/bg.jpg");
    public static BufferedImage background2 = imageLoader("/res/bg.jpg");
    public static BufferedImage boom0 = imageLoader("/res/boom0.png");
    public static BufferedImage fire0 = imageLoader("/res/fire0.png");
    public static BufferedImage fire1 = imageLoader("/res/fire1.png");
    public static BufferedImage up0 = imageLoader("/res/Up0.png");
    public static ImageIcon bg_clear = new ImageIcon(imageLoader("/res/bgs/bg-clear.png"));
    public static ImageIcon button0 = new ImageIcon(imageLoader("/res/bgs/button0.png"));
    public static ImageIcon button1 = new ImageIcon(imageLoader("/res/bgs/button1.png"));
    public static ImageIcon input0 = new ImageIcon(imageLoader("/res/bgs/input0.png"));
    public static Clip bgClip = audioLoader("/res/bg.wav");

    public Tools() {

    }

    public static Clip audioLoader(String file) {
        Clip clip = null;
        try {
            clip = AudioSystem.getClip();
            clip.open(AudioSystem.getAudioInputStream(Tools.class.getResource(file)));

        } catch (Exception exc) {
            System.out.println("failed to load " + file);
            System.exit(0);
        }
        return clip;
    }

    public static BufferedImage imageLoader(String file) {

        BufferedImage image = null;
        try {
            image = ImageIO.read(Tools.class.getResource(file));
        } catch (Exception e) {
            System.out.println("failed to load " + file);
            System.exit(0);
        }

        return image;
    }

    public static int getDistance(int x1, int y1, int x2, int y2) {
        double x_1 = x1;
        double x_2 = x2;
        double y_1 = y1;
        double y_2 = y2;

        double component1 = (x_1 - x_2) * (x_1 - x_2);
        double component2 = (y_1 - y_2) * (y_1 - y_2);

        double result = Math.sqrt(component1 + component2);
        return (int) result;
    }

    //overload
    public static int getDistance(double x1, double y1, int x2, int y2) {
        double x_1 = x1;
        double x_2 = x2;
        double y_1 = y1;
        double y_2 = y2;

        double component1 = (x_1 - x_2) * (x_1 - x_2);
        double component2 = (y_1 - y_2) * (y_1 - y_2);

        double result = Math.sqrt(component1 + component2);
        return (int) result;
    }

    //overload 2
    public static int getDistance(int x1, int y1, double x2, double y2) {
        double x_1 = x1;
        double x_2 = x2;
        double y_1 = y1;
        double y_2 = y2;

        double component1 = (x_1 - x_2) * (x_1 - x_2);
        double component2 = (y_1 - y_2) * (y_1 - y_2);

        double result = Math.sqrt(component1 + component2);
        return (int) result;
    }

    //overload 3
    public static int getDistance(double x1, double y1, double x2, double y2) {
        double x_1 = x1;
        double x_2 = x2;
        double y_1 = y1;
        double y_2 = y2;

        double component1 = (x_1 - x_2) * (x_1 - x_2);
        double component2 = (y_1 - y_2) * (y_1 - y_2);

        double result = Math.sqrt(component1 + component2);
        return (int) result;
    }

    public static int abs(int num) {
        if (num > 0)
            return num;
        else
            return -num;
    }
}
