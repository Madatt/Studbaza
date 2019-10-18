object lista1 {
  def lesser(l: List[Int], n: Int): Boolean = {
    if(l == Nil) true
    else if(l.head < n) lesser(l.tail, n) else false
  }

  def main(args: Array[String]): Unit = {
    var list = List(5, 12, 2323, 2 , 3)
    var list2 = List(5, 6, 5, 6, 7, 3, 1, 2)
    var list3 = List()
    println()
    printf(lesser(list, 5).toString)
    println()
    printf(lesser(list2, 8).toString)
    println()
    printf(lesser(list3, 11).toString)

  }

}
