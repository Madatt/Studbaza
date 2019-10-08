object lista1a {
  def printList(args: List[_]): Unit = {
    args.foreach(println)
  }

  def flatten[A](l: List[List[A]]): List[A] = {
    if(l == Nil) Nil
    else l.head ++ flatten(l.tail)
  }


  def sqrList(l: List[Int]): List[Int] = {
    if(l == Nil) Nil
      else (l.head * l.head) :: sqrList(l.tail)
    }


  def count[A](e: A, l: List[A]): Int = {
    if(l == Nil) 0
      else if(e == l.head) 1 + count(e, l.tail) else count(e, l.tail)
  }

  def replicate[A](x: A, n: Int): List[A] = {
    if(n > 0) x :: replicate(x, n-1)
      else Nil
  }


  def listLength[A](l: List[A]): Int = {
    if(l == Nil) 0
      else 1 + listLength(l.tail)
  }

  def palindrome[A](l: List[A]): Boolean = {
    l == l.reverse
  }

  def main(args: Array[String]): Unit = {
    var list = List(List(5,6), List(1,2,3))
    var list2 = List(5, 6, 5, 6, 7, 3, 1, 2)
    var list3 = List(1,2,3,2,1)
    println()
    printList(flatten(list))
    println()
    printf(listLength(list2).toString)
    println()
    printf(count(5, list2).toString)
    println()
    printList(sqrList(list2))
    println()
    printf(palindrome(list3).toString)
    println()
    printList(replicate("aa", 6))
  }
}
