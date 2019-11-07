sealed trait lBT[+A]
 case object LEmpty extends lBT[Nothing]
 case class LNode[+A](elem:A, left:()=>lBT[A], right:()=>lBT[A]) extends lBT[A]

object lista5 {
  def printList(args: List[_]): Unit = {
    args.foreach(println)
  }

  def lrepeat[A] (k: Int)(l: LazyList[A]): LazyList[A] = {
    def inside (n: Int, ll: LazyList[A]): LazyList[A] = (n, ll) match {
      case (_, LazyList()) => LazyList()
      case (0, h#::t) => inside(k, t)
      case (_, h#::_) => h#::inside(n-1, ll)
    }
    inside(k, l)
  }


  def lfib() = {
    def inside(a: Int, b: Int): LazyList[Int] = {
      a #:: inside(b, a+b)
    }
    inside(0, 1)
  }

  def lBreadth[A](l: lBT[A]) = {
    def inside(tl: List[lBT[A]]): LazyList[A] = tl match{
      case Nil => LazyList()
      case LEmpty::t => inside(t)
      case LNode(v, f1, f2)::t => v#::inside(t ++ (List(f1(), f2())))
    }
    inside(List(l))
  }

  def main(args: Array[String]): Unit = {

  }
}
