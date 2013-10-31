import java.util.Scanner;

class coin_change
{
    public static int get_total_num_coins( int[] coin_values, final int num_cents )
    {
        int[] num_ways_make_change = new int[num_cents + 1];
        num_ways_make_change[0] = 1;

        for( int i = 0; i < coin_values.length; i++ )
            for( int j = 0; j + coin_values[i] <= num_cents; j++ )
                num_ways_make_change[j + coin_values[i]] += num_ways_make_change[j];

        return num_ways_make_change[num_cents];
    }

    public static void main( String[] args )
    {
        Scanner in = new Scanner( System.in );
        int num_coins = in.nextInt();
        int num_cents = in.nextInt();
        int[] coin_values = new int[num_coins];

        int tmp;
        for( int i = 0; i < num_coins; i++ )
        {
            tmp = in.nextInt();
            coin_values[i] = tmp;
        }

        System.out.println( "Change for " + num_cents + " cents can be made in " + get_total_num_coins( coin_values, num_cents ) + " ways." );
    }
};
