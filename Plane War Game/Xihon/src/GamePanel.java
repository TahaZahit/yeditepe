import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

public class GamePanel extends JPanel implements Runnable, KeyListener, ActionListener {

    public static final int HEIGHT = 860;
    public static final int WIDTH = 700;
    private static final int FPS = 60;
    public static int SCORE;
    public static GameStateManager gsm;
    public static Player player;
    public static ArrayList<Bullet> bullets;
    public static ArrayList<Enemy> enemies;
    public static ArrayList<PowerUp> powerUps;
    static ArrayList<Boom> booms;
    private static boolean paused = false;
    private Thread thread;
    private boolean running = false;
    private int fpsDisplay;
    private int frames;
    private Timer fpsTimer;
    private Graphics2D g;
    private BufferedImage gameImage;
    private WaveSystem waveSystem;
    private CollisionTester cs;
    private Background bg;
    private Menu menu;
    private HighScore hs;
    private GameOver go;
    private User _currentUser;

    public GamePanel() {
        super();
        Boom.init();
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
        setFocusable(true);
        requestFocus();
    }

    public static boolean getPaused() {
        return paused;
    }

    public static void setPaused(boolean p) {
        paused = p;
    }

    @Override
    public void addNotify() {
        super.addNotify();
        init();
        if (thread == null) thread = new Thread(this);
        thread.start();
        addKeyListener(this);
    }

    private void init() {
        running = true;
        paused = false;
        fpsTimer = new Timer(1000, this);
        fpsTimer.start();
        frames = 0;
        fpsDisplay = 0;
        gameImage = Tools.imageLoader("/res/bgs/bg-clear.png");
        g = (Graphics2D) gameImage.getGraphics();
        SCORE = 0;
        gsm = new GameStateManager();
        waveSystem = new WaveSystem();
        cs = new CollisionTester();
        bg = new Background();
        menu = new Menu();
        hs = new HighScore();
        player = new Player(GamePanel.WIDTH / 2, GamePanel.HEIGHT / 2);
        go = new GameOver();
        bullets = new ArrayList<Bullet>();
        enemies = new ArrayList<Enemy>();
        powerUps = new ArrayList<PowerUp>();
        booms = new ArrayList<Boom>();
    }

    private void update() {
        if (gsm.getState() == GameStateManager.MENU) menu.update();
        if (gsm.getState() == GameStateManager.HIGHSCORES) hs.update();
        if (gsm.getState() == GameStateManager.GAME) {

            waveSystem.update();
            cs.update();
            bg.update();
            player.update();

            for (int i = 0; i < bullets.size(); i++) {
                bullets.get(i).update();
                if (bullets.get(i).isDead()) bullets.remove(i);
            }

            for (int i = 0; i < powerUps.size(); i++) {
                powerUps.get(i).update();
                if (powerUps.get(i).isDead()) powerUps.remove(i);
            }

            for (int i = 0; i < enemies.size(); i++) {
                enemies.get(i).update();
                if (enemies.get(i).isDead()) enemies.remove(i);
            }

            for (int i = 0; i < booms.size(); i++) {
                booms.get(i).update();
                if (booms.get(i).isDead()) booms.remove(i);
            }
        }
        if (player.isLive()) player.update();
        if (gsm.getState() == GameStateManager.GAMEOVER) go.update();
    }

    private void render() {

        if (gsm.getState() == GameStateManager.MENU) menu.draw(g);
        if (gsm.getState() == GameStateManager.HIGHSCORES) hs.draw(g);
        if (gsm.getState() == GameStateManager.GAMEOVER) {
            if (SCORE > _currentUser.get_highscore()) User.UpdateHighscore(_currentUser, SCORE);
            go.draw(g);
        }
        if (gsm.getState() == GameStateManager.GAME) {
            bg.draw(g);
            for (PowerUp powerUp : powerUps) powerUp.draw(g);
            for (Bullet bullet : bullets) bullet.draw(g);
            for (Enemy enemy : enemies) enemy.draw(g);
            for (Boom boom : booms) boom.draw(g);
            player.draw(g);
            waveSystem.draw(g);
        }
        g.setColor(Color.WHITE);
        g.setFont(new Font("TimesRoman", Font.BOLD, 20));
        g.drawString("FPS: " + fpsDisplay, 600, 40);
    }

    private void draw() {
        Graphics g2 = this.getGraphics();
        g2.drawImage(gameImage, 0, 0, null);
        g2.dispose();
    }

    @Override
    public void run() {
        long targetTime = 1000 / FPS;
        while (running) {
            long startingTime = System.nanoTime();
            if (!paused) {
                update();
                render();
                draw();
            }
            long elapsed = (System.nanoTime() - startingTime) / 1000000;
            long wait = targetTime - elapsed;
            try {
                if (wait > 0) Thread.sleep(wait);
            } catch (Exception e) {
                e.printStackTrace();
            }
            frames++;
        }
    }

    @Override
    public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();

        if (keyCode == KeyEvent.VK_ESCAPE) {
            System.out.println("Exit system");
            System.exit(0);
        }

        if (gsm.getState() == GameStateManager.GAME || gsm.getState() == GameStateManager.GAMEOVER)
            switch (keyCode) {
                case KeyEvent.VK_W:
                    player.setMovingUp(true);
                    break;
                case KeyEvent.VK_S:
                    player.setMovingDown(true);
                    break;
                case KeyEvent.VK_A:
                    player.setMovingLeft(true);
                    break;
                case KeyEvent.VK_D:
                    player.setMovingRight(true);
                    break;
                case KeyEvent.VK_SPACE:
                    player.setFiring(true);
                    break;
                case KeyEvent.VK_X:
                    player.setFiringDelay(2);
                    player.setFiring(true);
                    break;
                default:
                    System.out.println("unknown command");
            }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        int keyCode = e.getKeyCode();

        if (gsm.getState() == GameStateManager.MENU)
            switch (keyCode) {
                case KeyEvent.VK_W:
                case KeyEvent.VK_UP:
                    menu.previousChoice();
                    break;

                case KeyEvent.VK_S:
                case KeyEvent.VK_DOWN:
                    menu.nextChoice();
                    break;

                case KeyEvent.VK_ENTER:
                case KeyEvent.VK_SPACE:
                    menu.setChosen();
                    break;

                default:
                    System.out.println("unknown command");
            }

        if (gsm.getState() == GameStateManager.HIGHSCORES)
            switch (keyCode) {
                case KeyEvent.VK_ENTER:
                case KeyEvent.VK_SPACE:
                    hs.finish();
                    break;
                default:
                    System.out.println("unknown command");
            }

        if (gsm.getState() == GameStateManager.GAMEOVER)
            switch (keyCode) {
                case KeyEvent.VK_ENTER:
                case KeyEvent.VK_SPACE:
                    go.finish();
                    User.Save();
                    System.exit(0);
                    break;
                default:
                    System.out.println("unknown command");
            }

        if (gsm.getState() == GameStateManager.GAME)
            switch (keyCode) {
                case KeyEvent.VK_P:
                    pause();
                    if (paused)
                        System.out.println("pause thread");
                    else
                        System.out.println("unpause thread");
                    break;
                case KeyEvent.VK_W:
                    player.setMovingUp(false);
                    break;
                case KeyEvent.VK_S:
                    player.setMovingDown(false);
                    break;
                case KeyEvent.VK_A:
                    player.setMovingLeft(false);
                    break;
                case KeyEvent.VK_D:
                    player.setMovingRight(false);
                    break;
                case KeyEvent.VK_SPACE:
                    player.setFiring(false);
                    break;
                case KeyEvent.VK_X:
                    player.setFiringDelay(300);
                    player.setFiring(false);
                    break;
                case KeyEvent.VK_G:
                    player.setGodMode();
                    break;
                default:
                    System.out.println("unknown command");
            }
    }

    @Override
    public void keyTyped(KeyEvent e) {
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        fpsDisplay = frames;
        frames = 0;
    }

    private void pause() {
        paused = !paused;
    }


    public void set_currentUser(User user) {
        _currentUser = user;
    }

}
