import javafx.scene.shape.Cylinder

class MyPair[A, B](var fst: A, var snd: B) {
  override def toString: String = "(" + fst.toString + ", " + snd.toString + ")"
}

abstract class MyPair2 {
  type A
  type B
  var fst: A
  var snd: B

  override def toString: String = "(" + fst.toString + ", " + snd.toString + ")"
}


class Pracownik private(var nazwisko: String, private var zwolinony: Boolean) {
  def zwolnij = {
    Pracownik._liczbaPracownikow -= 1
    zwolinony = false
  }
}

object Pracownik {
  private var _liczbaPracownikow = 0
  def liczbaPracownikow = _liczbaPracownikow

  def apply(nazwisko: String) = {
    _liczbaPracownikow += 1
    new Pracownik(nazwisko, false)
  }
}

class Point(private var _x: Double = 0.0, private var _y: Double = 0.0) {
  def x_=(xx: Double): this.type = {
    _x = xx
    this
  }

  def y_=(yy: Double): this.type = {
    _y= yy
    this
  }

  def x = _x
  def y = _y
}

class Circle(xx: Double = 0.0, yy: Double = 0.0, private var _r: Double = 1.0) extends Point(xx, yy) {
  def r_=(rr: Double): this.type = {
    _r = rr
    this
  }

  def r = _r
}

class Cylinder(xx: Double = 0.0, yy: Double = 0.0, rr: Double = 1.0, private var _h: Double = 1.0) extends Circle(xx, yy, rr) {
  def h_=(hh: Double): this.type = {
    _h = hh
    this
  }

  def h = _h
}


def wordCounter(text: String): scala.collection.mutable.Map[String,Int] = {
  val counts = scala.collection.mutable.Map.empty[String, Int].withDefaultValue(0)
  for(i <- text.split(" ")) {
    val word = i.toLowerCase
    counts(word) += 1
  }

  counts
}



val test: MyPair[Int, Int] = new MyPair(323, 233)
println(test.toString)

val test2 = new MyPair2{type A = Int; type B = Int; var fst = 323; var snd = 233}
println(test2.toString)

val pracownik1 = Pracownik("test")
val pracownik2 = Pracownik("test2")
println(Pracownik.liczbaPracownikow)
pracownik1.zwolnij
println(Pracownik.liczbaPracownikow)
pracownik2.zwolnij
println(Pracownik.liczbaPracownikow)

var point = new Point(12, 123)
(point.x = 5).y = 34
println(point.x)
println(point.y)

var cylinder = new Cylinder(123,123,33,122)