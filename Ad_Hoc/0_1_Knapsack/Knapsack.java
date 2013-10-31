import java.util.Scanner;

public class Knapsack
{
    public static int get_max_value( int[] values, int[] weights, int capacity )
    {
        int[][] knapsack_values = new int[values.length + 1][capacity + 1];

        for( int i = 1; i <= values.length; i++ )
            for( int j = 0; j <= capacity; j++ )
            {
                if( weights[i - 1] <= j )
                    knapsack_values[i][j] = Math.max( knapsack_values[i - 1][j], values[i - 1] + knapsack_values[i - 1][j - weights[i - 1]] );
                else
                    knapsack_values[i][j] = knapsack_values[i - 1][j];
            }

        return knapsack_values[values.length][capacity];
    }
        
    public static void main( String[] args )
    {
        Scanner in = new Scanner( System.in );
        int capacity = in.nextInt(), num_objects = in.nextInt();

        int[] values = new int[num_objects];
        int[] weights = new int[num_objects];

        int tmp;
        for( int i = 0; i < num_objects; i++ )
        {
            tmp = in.nextInt();
            values[i] = tmp;
        }

        for( int i = 0; i < num_objects; i++ )
        {
            tmp = in.nextInt();
            weights[i] = tmp;
        }

        int max_value = get_max_value( values, weights, capacity );
        System.out.println( "The maximum value you can take from the knapsack is " + max_value );
    }
};
