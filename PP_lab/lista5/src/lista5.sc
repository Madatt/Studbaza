trait Debug {
  def debugName(): Unit = {
    println("Klasa " + getClass.getName)
  }

  def debugVars(): Unit = {
    for (f <- this.getClass.getDeclaredFields) {
      f.setAccessible(true)
      println("Pole: " + f.getName + " => " + f.getType.getSimpleName + ", " + f.get(this))
    }
  }
}

class Point(tx: Int, ty: Int) extends Debug {
  var x: Int = tx
  var y: Int = ty
  var a: String = "test"
}

var test = new Point(2, 3)

test.debugName()
test.debugVars()