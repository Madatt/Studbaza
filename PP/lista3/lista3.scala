object lista3 {
  def printList(args: List[_]): Unit = {
    args.foreach(println)
  }

  def sumProd (l: List[Int]): (Int, Int) = {
    (l.foldLeft ((0, 1))) ((t, x) => (t._1 + x, t._2 * x))
  }

  def insertionSort[A](orr: (A, A) => Boolean, l: List[A]) = {
    def ins (n: List[A], e: A): List[A] = n match {
        case Nil => e::Nil
        case h::t => if (orr (e, h)) e::n else h::(ins (t, e))
    }
    (l foldLeft List[A]()) ((acc, ee) => ins (acc, ee))
  }

  def mergeSort[A](orr: (A, A) => Boolean, l: List[A]):List[A]  = {
      var len = l.length / 2
      if (len == 0) l else {
        def merge (ll: List[A], rr: List[A]): List[A] = (ll, rr) match {
            case (h1::t1, h2::t2) => if (orr(h1, h2)) h1::merge(t1, rr) else h2::merge(ll, t2)
            case (a, Nil) => a
            case (Nil, a) => a
        }

        def split (l: List[A], r: List[A], a: Int): (List[A], List[A]) =
            if (a == 0) (l.reverse, r) else split((r.head :: l), (r.tail), (a-1))

        var (ll, rr) = split(Nil, l, len)
        merge (mergeSort (orr, ll), mergeSort (orr, rr))
      }
  }




  def main(args: Array[String]): Unit = {
    var list = List(List(5,6), List(1,2,3))
    var list2 = List(5, 6, 5, 6, 7, 3, 1, 2)
    var list3 = List(1,2,3,2,1)
    var list4 = List(1,2,3)

    println()
    printList(insertionSort(((a: Int, b: Int) => a <= b ) ,list2))
    printList(mergeSort(((a: Int, b: Int) => a <= b ) ,list2))


  }
}
