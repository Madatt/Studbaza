object lista1a {
  def printList(args: List[_]): Unit = {
    args.foreach(println)
  }

  def flatten(l: List[List[Int]]): List[Int] = {
    def inside(r: List[List[Int]], k: List[List[Int]]): List[Int] = {
      if(k == Nil) Nil
      else k.head ++ inside(r, k.tail)
    }
    inside(List(), l)
  }


  def sqrList(l: List[Int]): List[Int] = {
    def inside(r: List[Int], k: List[Int]): List[Int] = {
      if(k == Nil) Nil
      else (k.head * k.head) :: inside(r, k.tail)
    }
    inside(List(), l)
  }


  def count[E](e: E, l: List[Int]): Int = {
    if(l == Nil) 0
      else if(e == l.head) 1 + count(e, l.tail) else count(e, l.tail)
  }


  def listLength(l: List[Int]): Int = {
    if(l == Nil) 0
      else 1 + listLength(l.tail)
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
