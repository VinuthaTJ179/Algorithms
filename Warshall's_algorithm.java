import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the number of vertices:");
		int n = input.nextInt();
		int arr[][] = new int[n][n],i,j,k;
		System.out.println("Enter the adjacency matrix:");
		for(i=0;i<n;i++)
		{
		    for(j=0;j<n;j++)
		    {
		        arr[i][j] = input.nextInt();
		    }
		}
		for(k=0;k<n;k++)
		{
		    for(i=0;i<n;i++)
		    {
		        for(j=0;j<n;j++)
		        {
		            arr[i][j] = (arr[i][j] | (arr[i][k] & arr[k][j]));
		        }
		    }
		}
		System.out.println("The corresponding transitive closure is:");
		for(i=0;i<n;i++){
		    for(j=0;j<n;j++)
		    {
		        System.out.print(arr[i][j] + " ");
		    }
		    System.out.println();
		}
	}
}
