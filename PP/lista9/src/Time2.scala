class Time2(private var h: Int, private var m: Int) {
  require(h >= 0 && h <= 23)
  require(m >= 0 && m < 60)

  def hour = h

  def hour_=(nh: Int) = {
    require(nh >= 0 && nh <= 23)
    h = nh
  }

  def minute = h

  def minute_=(nm: Int) = {
    require(nm >= 0 && nm < 60)
    m = nm
  }

  def before(other: Time2): Boolean = {
    (h < other.h) || ((m < other.m) && (h == other.m))
  }
}