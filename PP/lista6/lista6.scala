object lista6 {
  def printList(args: List[_]): Unit = {
    args.foreach(println)
  }

  def whileLoop(cond: =>Boolean)(exp: =>Unit): Unit = {
    if(cond)
    {
      exp
      whileLoop(cond)(exp)
    }
  }

  def swap[A](tab: Array[A])(i: Int)(j: Int) = {
    val tmp = tab(i)
    tab(i) = tab(j)
    tab(j) = tmp
  }



  def main(args: Array[String]): Unit = {

  }
}
