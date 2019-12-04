object UzycieWyjatkow {
  def main(args: Array[String]): Unit = {
    try metoda1()
    catch {
      case e: Exception =>
        System.err.println(e.getMessage + "\n")
        e.printStackTrace()
    }
  }

  @throws[Exception]
  def metoda1(): Unit = {
    metoda2()
  }

  @throws[Exception]
  def metoda2(): Unit = {
    metoda3()
  }

  @throws[Exception]
  def metoda3(): Unit = {
    throw new Exception("Wyjatek zgloszony w metoda3")
  }
}

/*
Wyjatek zgloszony w metoda3

java.lang.Exception: Wyjatek zgloszony w metoda3
	at UzycieWyjatkow$.metoda3(UzycieWyjatkow.scala:23)
	at UzycieWyjatkow$.metoda2(UzycieWyjatkow.scala:18)
	at UzycieWyjatkow$.metoda1(UzycieWyjatkow.scala:13)
	at UzycieWyjatkow$.main(UzycieWyjatkow.scala:3)
	at UzycieWyjatkow.main(UzycieWyjatkow.scala)

 */