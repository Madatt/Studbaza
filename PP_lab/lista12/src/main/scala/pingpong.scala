import akka.actor._

class Player extends Actor {
  def receive = {
    case "ping" => {
      println("ping")
      sender() ! "pong"
    }
    case "pong" => {
      println("pong")
      sender() ! "ping"
    }
  }
}


object Main extends App {
  val system = ActorSystem()

  val player1: ActorRef = system.actorOf(Props[Player])
  val player2: ActorRef = system.actorOf(Props[Player])

  player1.tell("ping", player2)
}