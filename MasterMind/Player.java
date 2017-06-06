public class Player
{
    private static int number;
    public static void setNumber(int value)
    {
        number = value;
        
    }
    public static byte getCW(int guess)
    {
        return MasterMind.map.getData(guess, number);
    }
}
