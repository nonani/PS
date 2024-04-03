import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

class Process{
    int sec;
    int pid;
    int priority;
    public Process(int sec, int pid, int priority)
    {
        this.sec = sec;
        this.pid = pid;
        this.priority = priority;
    }
    @Override
    public String toString() {
        return "sec: "+sec+"\npid: "+pid+"\npriority: "+priority+"\n";
    }
    public void setSec(int sec) {
        this.sec = sec;
    }
    public void setPriority(int priority) {
        this.priority = priority;
    }
}
class ProcessComparator implements Comparator<Process>{

    @Override
    public int compare(Process o1, Process o2) {
        if(o1.priority==o2.priority)
            return o1.pid - o2.pid;
        else
            return o2.priority - o1.priority;
    }
    
}
class Main {
    
    
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));      
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T, n;
        PriorityQueue<Process> pq = new PriorityQueue<Process>(new ProcessComparator());
        StringTokenizer st1 = new StringTokenizer(bf.readLine()); 
        T = Integer.parseInt(st1.nextToken());
        n = Integer.parseInt(st1.nextToken());

        for(int i=0;i<n;i++)
        {
            int id, sec, priority;
            StringTokenizer st2 = new StringTokenizer(bf.readLine()); 
            id = Integer.parseInt(st2.nextToken());
            sec = Integer.parseInt(st2.nextToken());
            priority = Integer.parseInt(st2.nextToken());
            pq.add(new Process(sec, id, priority));
        }
        bf.close();
        while(T > 0)
        {
            T--;
            var cur = pq.poll();
            bw.write(cur.pid + "\n");
            cur.setSec(cur.sec-1);
            if (cur.sec > 0)
            {
                cur.setPriority(cur.priority-1);
                pq.add(cur);
            }
        }
       bw.close();
    }
}