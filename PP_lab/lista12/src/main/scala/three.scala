import akka.actor._

case class Ball(count: Int)

class Player2(val num: Int, val players: Array[ActorRef]) extends Actor {
  private val r = scala.util.Random

  def receive = {
    case Ball(n) => {
      var next = r.nextInt(players.length)
      while(next == num) next = r.nextInt(players.length)

      println("Gracz " + num + " odebrał rzut nr " + n)
      println("Gracz " + num + " rzuca do Gracza " + next)
      players(next) ! Ball(n+1)
    }
  }
}

object Main2 extends App {
  val system = ActorSystem()
  var players: Array[ActorRef] = new Array[ActorRef](3)
  players(0) = system.actorOf(Props(classOf[Player2], 0, players))
  players(1) = system.actorOf(Props(classOf[Player2], 1, players))
  players(2) = system.actorOf(Props(classOf[Player2], 2, players))

  players(0) ! Ball(0)
}