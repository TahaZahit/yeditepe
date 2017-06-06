public class Map
{
    private byte[][] data = new byte[10000][10000];
    public short[] list = new short[10000];
    public int count=0;

    public Map()
    {
      
       Thread x0= new Thread(()->{ for(int i = 0; i < 1250; i++)for (int j = 0; j < 10000; j++)data[i][j] = getCW(i, j);});
       x0.start();
       Thread x1= new Thread(()->{ for(int i = 1250; i < 2500; i++)for (int j = 0; j < 10000; j++)data[i][j] = getCW(i, j);});
       x1.start();
       Thread x2= new Thread(()->{ for(int i = 2500; i < 3750; i++)for (int j = 0; j < 10000; j++)data[i][j] = getCW(i, j);});
       x2.start();
       Thread x3= new Thread(()->{ for(int i = 3750; i < 5000; i++)for (int j = 0; j < 10000; j++)data[i][j] = getCW(i, j);});
       x3.start();
       Thread x4= new Thread(()->{ for(int i = 5000; i < 6250; i++)for (int j = 0; j < 10000; j++)data[i][j] = getCW(i, j);});
       x4.start();
       Thread x5= new Thread(()->{ for(int i = 6250; i < 7500; i++)for (int j = 0; j < 10000; j++)data[i][j] = getCW(i, j);});
       x5.start();
       Thread x6= new Thread(()->{ for(int i = 7500; i < 8750; i++)for (int j = 0; j < 10000; j++)data[i][j] = getCW(i, j);});
       x6.start();
       Thread x7= new Thread(()->{ for(int i = 8750; i < 10000; i++)for (int j = 0; j < 10000; j++)data[i][j] = getCW(i, j);});
       x7.start();
       while(x0.isAlive()||x1.isAlive()||x2.isAlive()||x3.isAlive()||x4.isAlive()||x5.isAlive()||x6.isAlive()||x7.isAlive()){};
       
    }
    static byte getCW(int i, int j)
    {
        byte c = 0, w = 0;
        int x1 = i % 10, x2 = (i / 10) % 10, x3 = (i / 100) % 10, x4 = i / 1000;
        int y1 = j % 10, y2 = (j / 10) % 10, y3 = (j / 100) % 10, y4 = j / 1000;

        if (x1 == y1) c++; else if (x1 == y2 || x1 == y3 || x1 == y4) w++;
        if (x2 == y2) c++; else if (x2 == y1 || x2 == y3 || x2 == y4) w++;
        if (x3 == y3) c++; else if (x3 == y1 || x3 == y2 || x3 == y4) w++;
        if (x4 == y4) c++; else if (x4 == y1 || x4 == y2 || x4 == y3) w++;

       
        
        return (byte)((c << 3) + w);

    }
    public byte getData(int guess, int number)
    {
        return data[guess][number];
    }

    public void fillList(byte wc, int guess)
    {
    	
    	int old=count;
    	count=0;
        for (short i = 0; i < old; i++)
        {
            if (data[guess][list[i]] == wc)
            {
            	
                list[count++]=list[i];
            }
        }
    }
    public void first(int wc)
    {
    	byte [] a=data[1234];
        for (short i = 0; i < 10000; i++)
        {
            if (a[i] == wc) list[count++]=i;
        }
    }
}

