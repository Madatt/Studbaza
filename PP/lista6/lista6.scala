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

  def choose_pivot[A](tab: Array[A])(l: Int)(r: Int) = {
      tab((l+r)/2)
  }

  def partition(tab: Array[Int])(l: Int)(r: Int) = {
    var i = l
    var j = r
    val pivot = choose_pivot(tab)(l)(r)
    while(i <= j)
    {
      while(tab(i) < pivot) {i = i + 1}
      while(tab(j) > pivot) {j = j - 1}
      if(i <= j)
      {
        swap(tab)(i)(j)
        i = i + 1
        j = j - 1
      }
    }
    (i, j)
  }

  def quick(tab: Array[Int])(l: Int)(r: Int): Unit = {
    if(l < r) {
      val (i, j) = partition(tab)(l)(r)
      if(j-l < r-i) {
        quick(tab)(l)(j)
        quick(tab)(i)(r)
      }else {
        quick(tab)(i)(r)
        quick(tab)(l)(j)
      }
    }
  }

  def quicksort(tab: Array[Int]) = quick(tab)(0)(tab.length - 1)

/*
# let rec quick tab l r =
if l < r then
let (i,j) = partition tab l r
in if j-l < r-i (* usprawnienie 3 *)
then let _ = quick tab l j in quick tab i r
else let _ = quick tab i r in quick tab l j
else ();;
val quick : 'a array -> int -> int -> unit = <fun>
#let quicksort tab = quick tab 0 ((Array.length tab)-1);;*/


  def main(args: Array[String]): Unit = {
    var tab = Array(4, 676, 234, 56, -2, 0)
    quicksort(tab)
    println(tab.mkString(" "))
  }
}
