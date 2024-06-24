import java.util.PriorityQueue

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
fun main() {
    var N:Int = 0
    N = readLine()!!.toInt()
    val pq = PriorityQueue<Int>()
    for (i: Int in 1..N ){
        val num = readLine()!!.toInt()
        if(num == 0)
            println(pq.poll()?:0)
        else
            pq.add(num)
    }
}