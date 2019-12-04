class Pojazd(val producent: String, val model: String, val rok: Int = -1, var rejestracja: String = "") {
  def this(producent: String, model: String, rejestracja: String) {
    this(producent, model, -1, rejestracja)
  }
}