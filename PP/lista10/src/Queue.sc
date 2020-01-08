class Queue[+T] private (private val q: (List[T], List[T])) {
  private def fix[S >: T](l1: List[S], l2: List[S]) = (l1, l2) match {
      case (Nil, t) => new Queue[S]((t.reverse, Nil))
      case q => new Queue(q)
    }

  def enqueue[S >: T](e: S): Queue[S] = {
    val (l1, l2) = q
    fix(l1, e :: l2)
  }

  def dequeue: Queue[T] = q match {
      case (_ :: t, l2) => fix(t, l2)
      case (Nil, Nil) => this
    }

  def first: T = q._1 match {
      case (h :: _) => h
      case _ => throw new Exception("first")
          }

  def isEmpty: Boolean =
    q._1 == Nil
}

object Queue {
  def apply[T](xs: T*) = new Queue[T](xs.toList, Nil)
  def empty[T] = new Queue[T](Nil, Nil)
}

import scala.collection.mutable._
def copy[T](dest: Seq[T], src: Seq[T]) = {
  var i = 0
  src foreach {
    el =>
      dest.update(i, el)
      i += 1
  }
}