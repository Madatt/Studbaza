open QueueMut

module QueueCyclic : QUEUE_MUT =
struct
  type 'a t = {mutable f: int; mutable r: int; a: 'a option array}

  exception Empty of string
  exception Full of string

  let empty n =
    {f = 0; r = 0; a = Array.make n None}
  ;;

  let isFull q =
    q.r - q.f = -1 || q.r - q.f = Array.length q.a - 1
  ;;

  let isEmpty q =
    q.r = q.f
  ;;

  let enqueue (e, q) =
    if(isFull q) then raise (Full "") else
      q.a.(q.r) <- Some e;
      q.r <- ((q.r + 1) mod (Array.length q.a));
  ;;

  let dequeue q =
    if(isEmpty q) then () else
      q.f <- ((q.r + 1) mod (Array.length q.a));
  ;;

  let first q =
    if(isEmpty q) then raise (Empty "") else
    match q.a.(q.f) with
      | None -> raise (Empty "") 
      | Some a -> a
    ;;
  ;;

end;;
