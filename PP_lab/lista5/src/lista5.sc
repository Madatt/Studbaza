trait Debug {
  def debugName(): Unit = {
    println("Klasa " + getClass.getName)
  }

  def debugVars(): Unit = {
    for (f <- getClass.getDeclaredFields) {
      f.setAccessible(true)
      println("Pole: " + f.getName + " => " + f.getType.getSimpleName + ", " + f.get(this))
    }
  }
}


class Point2(tx: Int, ty: Int, tz: Float) extends Debug {
  var x: Int = tx
  var y: Int = ty
  var z: Float = tz
}

class Point(tx: Int, ty: Int) extends Debug {
  var x: Int = tx
  var y: Int = ty
  var a: String = "test"
}

object lista5 {
  def main(args: Array[String]): Unit = {
    var test = new Point(2, 3)
    var test2 = new Point(20, 0)
    var test3 = new Point2(2, 3, 324.124f)

    test.debugName()
    test.debugVars()
    test2.debugName()
    test2.debugVars()
    test3.debugName()
    test3.debugVars()

  }

}
