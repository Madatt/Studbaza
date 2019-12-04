class Time(private var h: Int) {
  if (h < 0)
    h = 0

  def hour = h

  def house_=(nh: Int) = {
    h = nh
    if (h < 0)
      h = 0
  }
}

object Time {
  def apply(h: Int): Unit = {
    new Time(h)
  }
}
