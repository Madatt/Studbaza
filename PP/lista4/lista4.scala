sealed trait BT[+A]
  case object Empty extends BT[Nothing]
  case class Node[+A](elem:A, left:BT[A], right:BT[A]) extends BT[A]

sealed trait Graphs[A]
  case class Graph[A](succ: A=>List[A]) extends Graphs[A]


object lista4 {
  def printList(args: List[_]): Unit = {
    args.foreach(println)
  }

  def breadthBT[A](tt: BT[A]) = {
    def inside(tl: List[BT[A]]): List[A] = tl match {
        case Nil => Nil
        case Empty::t => inside(t)
        case Node(v, left, right)::t => v::(inside(t ++ List(left, right)))
    }
    inside(List(tt))
  }

  def lenIn[A](tt: BT[A]) = {
    def inside (tt:BT[A], a: Int): Int = tt match {
        case Empty => 0
        case Node(v, left, right) => a + (inside (left, (a + 1))) + (inside (right, (a + 1)))
    }
    inside(tt, 0)
  }

  def lenEx[A](tt: BT[A]) = {
    def inside (tt:BT[A], a: Int): Int = tt match {
        case Empty => a
        case Node(v, left, right) => (inside (left, (a + 1))) + (inside (right, (a + 1)))
    }
    inside(tt, 0)
  }


  def depthSearch [A](g: Graph[A])(st: A): List[A] = {
    def inside (vis: List[A])(que: List[A]): List[A] = que match {
        case Nil => Nil
        case h::t => if (vis contains h) inside(vis)(t) else h::inside(h::vis)((g succ h) ++ t)
    }
    inside (Nil)(List(st))
  }


  def main(args: Array[String]): Unit = {
    val tr =  Node(1,
 Node(2,
 Node(4,
 Empty,
Empty
 ),
 Empty
 ),
 Node(3,
 Node(5,
 Empty,
Node(6,
 Empty,
Empty
 )
 ),
 Empty
 )
 )
    printList(breadthBT(tr))
    println(lenIn(tr))
    println(lenEx(tr))
  }
}
