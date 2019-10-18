object lista1 {
  def printList(args: List[_]): Unit = {
    args.foreach(println)
  }

  def flatten(l: List[List[Int]]): List[Int] = {
    def inside(r: List[List[Int]], k: List[List[Int]]): List[Int] = k match {
      case Nil => Nil
      case h::t => h ++ inside(r, t)
      }
    inside(List(), l)
  }


  def sqrList(l: List[Int]): List[Int] = {
    def inside(r: List[Int], k: List[Int]): List[Int] = k match {
      case Nil => Nil
      case h::t => (h * h) :: inside(r, t)
      }
    inside(List(), l)
  }


  def count[E](e: E, l: List[Int]): Int = l match {
    case Nil => 0
    case h::t => if(e == h) 1 + count(e, t) else count(e, t)
  }


  def listLength(l: List[Int]): Int = l match {
    case Nil => 0
    case h::t => 1 + listLength(t)
  }



  def main(args: Array[String]): Unit = {
    var list = List(List(5,6), List(1,2,3))
    var list2 = List(5, 6, 5, 6, 7, 3, 1, 2)
    println()
    printList(flatten(list))
    println()
    printf(listLength(list2).toString)
    println()
    printf(count(5, list2).toString)
    println()
    printList(sqrList(list2))
  }
}
