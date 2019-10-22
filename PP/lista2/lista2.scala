object lista2 {
  def printList(args: List[_]): Unit = {
    args.foreach(println)
  }

  def fib(n: Int): Int = n match {
    case 0 => 0
    case 1 => 1
    case k => fib(n-2) + fib(n-1)
  }


  def fibTail(n: Int): Int = {
    def inside(n: Int, a: Int, b: Int): Int = n match {
      case 0 => a
      case k => inside(n-1, b, a+b)
    }
    inside(n, 0, 1)
  }

  def root3(a: Double, e: Double): Double = {
    def inside(a: Double, e: Double, x: Double, i: Int): Double = {
      if (math.abs(x*x*x - a) <= e*math.abs(a))
        x
      else if (i == 0)
        if (a > 1.0) inside(a, e, a/3.0, 1) else inside(a, e, a, 1)
      else
        inside(a,e, x+(a/(x*x)-x)/3.0,i+1)
    }
    inside(a, e, 0.0, 0)
  }

  def initSegment[A](f: List[A], s: List[A]): Boolean = (f, s) match {
      case (Nil, s) => true
      case (h1::t1, h2::t2) => if (h1 == h2) initSegment (t1, t2) else false
      case (h::t, Nil) => false
  }


  def replaceNth[A](l: List[A], n: Int, a: A): List[A] = l match {
      case h::t => if (n == 0) a::t else h::replaceNth(t, n - 1, a)
      case Nil => Nil
  }

  def main(args: Array[String]): Unit = {
    var list = List(List(5,6), List(1,2,3))
    var list2 = List(5, 6, 5, 6, 7, 3, 1, 2)
    var list3 = List(1,2,3,2,1)
    var list4 = List(1,2,3)

    println()
    printf(fib(12).toString)
    println()
    printf(fibTail(12).toString)
    println()
    printf(root3(20, 10e-15).toString)
    println()
    printf(initSegment(list4, list3).toString)
    println()
    printf(initSegment(list3, list4).toString)
    println()
    printList(replaceNth(list3, 3, 232))
  }
}
