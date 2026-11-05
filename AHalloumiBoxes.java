import java.util.Scanner;

public class AHalloumiBoxes {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();

        while(t-- > 0){
            int n = scanner.nextInt();
            int k = scanner.nextInt();

            int[] a = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = scanner.nextInt();
            }

            if (k > 1){
                System.out.println("YES");
            }

            boolean sorted = true;
            for(int i = 1; i < n; i++){
                if(a[i] < a[i-1]){
                    sorted = false;
                    break;
                }
            }
        if (sorted){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }

        scanner.close();
    }
}