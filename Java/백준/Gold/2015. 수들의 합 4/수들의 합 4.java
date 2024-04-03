import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


class Main {
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int K = scan.nextInt();
        long answer = 0;
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Integer> sum = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i=0;i<N;i++)
            arr.add(scan.nextInt());
        
        sum.add(arr.get(0));
        map.put(0, 1);

        if(map.containsKey(sum.get(0) - K))
                answer+=map.get(sum.get(0) - K);
        
        if(map.containsKey(sum.get(0))){
            map.put(sum.get(0), (map.get(sum.get(0)) + 1));
        }
        else
            map.put(sum.get(0), 1);
        for(int i=1;i<N;i++)
        {

            sum.add(arr.get(i) + sum.get(i-1));
            
            if(map.containsKey(sum.get(i) - K))
                answer+=map.get(sum.get(i) - K);
            if(map.containsKey(sum.get(i))){
                map.put(sum.get(i), (map.get(sum.get(i)) + 1));
            }
            else
                map.put(sum.get(i), 1);
        }
        
        System.out.println(answer);
    }
}