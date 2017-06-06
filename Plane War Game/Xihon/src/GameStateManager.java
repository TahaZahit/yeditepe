public class GameStateManager {

    public static final int MENU = 1;
    public static final int GAME = 2;
    public static final int HIGHSCORES = 3;
    public static final int GAMEOVER = 4;

    private int gameState;

    public GameStateManager() {
        gameState = MENU;
    }

    public void enterState(int state) {
        gameState = state;
    }

    public int getState() {
        return gameState;
    }
}