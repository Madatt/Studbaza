class Time3(private var h: Int, private var m: Int) {
  require(h >= 0 && h <= 23)
  require(m >= 0 && m < 60)
  private var mam = h * 60 + m

  def hour = mam / 60

  def hour_=(nh: Int) = {
    require(nh >= 0 && nh <= 23)
    mam = minute + nh * 60
  }

  def minute = mam % 60

  def minute_=(nm: Int) = {
    require(nm >= 0 && nm < 60)
    mam = hour + nm
  }

  def before(other: Time3): Boolean = {
    mam < other.mam
  }
}