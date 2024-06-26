import java.util.PriorityQueue
import java.util.Scanner

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
fun main() {
    var scan = Scanner(System.`in`)
    var d1 = scan.nextInt()
    var d2 = scan.nextInt()
    var d3 = scan.nextInt()
    var abc:Double = (d1+d2+d3) / 2.0
    val a = abc - d3
    val b = abc - d2
    val c = abc - d1
    if (a > 0 && b > 0 && c > 0)
    {
        println(1)
        println("${String.format("%.1f", a)} ${String.format("%.1f", b)} ${String.format("%.1f", c)}")
    }
    else
        println(-1)


}