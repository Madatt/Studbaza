open Queue

module QueueList : QUEUE_FUN =
struct
  type 'a t = 'a list
  exception Empty of string

  let empty () =
    []
  ;;

  let enqueue(a, l) =
    l @ [a]
  ;;

  let dequeue = function
    | [] -> []
    | h::t -> t
  ;;

  let first = function
    |  [] -> raise(Empty "")
    | h::t -> h

  let isEmpty = function
    | [] -> true
    | h::t -> false
  ;;

end;;
