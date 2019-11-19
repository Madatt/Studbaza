open Queue

module QueueListPair : QUEUE_FUN =
struct
  type 'a t = 'a list * 'a list
  exception Empty of string

  let fix = function
    | ([], s) -> (List.rev s, [])
    | q -> q
  ;;

  let empty () =
    ([], [])
  ;;

  let enqueue(a, q) =
    fix (fst q, a :: snd q)
  ;;

  let dequeue = function
    | ([], _) -> ([], [])
    | (h::t, s) -> fix(t, s)
  ;;

  let first = function
    | ([], _) -> raise(Empty "")
    | (h::t, s) -> h

  let isEmpty = function
    | ([], _) -> true
    | (_, _) -> false
  ;;

end;;
