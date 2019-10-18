object lista2 {
  def len[A](l: List[A]): Int = {
    def inside(l: List[A], a :Int): Int = l match {
      case h::t => inside(t, a+1)
      case Nil => a
    }
    inside(l, 0)
  }

  def main(args: Array[String]): Unit = {
    var list = List(5, 12, 2323, 2 , 3)
    var list2 = List(5, 6, 5, 6, 7, 3, 1, 2)
    var list3 = List()
    var list4 = List("a")
    println()
    printf(len(list).toString)
    println()
    printf(len(list2).toString)
    println()
    printf(len(list3).toString)
    println()
    printf(len(list4).toString)

  }

}
