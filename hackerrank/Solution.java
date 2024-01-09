import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] prime = new int[n];
        for(int i = 0;i<n;i++){
            prime[i] = sc.nextInt();
        }
        int k =sc.nextInt();
        
        int result = findkth(prime, k);
        
        System.out.println(result);
        
    }
    
    public static int findkth(int[] prime , int k){
        if(k<2){
            return 0;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        Set<Integer> visited = new HashSet<>();
        pq.offer(1);
        for(int i = 0 ;i<prime.length;i++){
            pq.offer(prime[i]);
            visited.add(prime[i]);
        }
        int count = -1;
        int number = 1;
        
        while(count<k){
            number = pq.poll();
            for(int p :prime){
                int next = p*number;
                
            
            if(!visited.contains(next)){
                pq.offer(next);
                visited.add(next);
            }
        }
        count++;
        }
        return number;
    }
}