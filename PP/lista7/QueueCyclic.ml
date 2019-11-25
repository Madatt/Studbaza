module type QUEUE_MUT =
sig
 type 'a t
 (* The type of queues containing elements of type ['a]. *)
 exception Empty of string
 (* Raised when [first q] is applied to an empty queue [q]. *)
 exception Full of string
 (* Raised when [enqueue(x,q)] is applied to a full queue [q]. *)
 val empty: int -> 'a t
 (* [empty n] returns a new queue of length [n], initially empty. *)
 val enqueue: 'a * 'a t -> unit
 (* [enqueue (x,q)] adds the element [x] at the end of a queue [q]. *)
 val dequeue: 'a t -> unit
 (* [dequeue q] removes the first element in queue [q] *)
 val first: 'a t -> 'a
 (* [first q] returns the first element in queue [q] without removing
 it from the queue, or raises [Empty] if the queue is empty. *)
 val isEmpty: 'a t -> bool
 (* [isEmpty q] returns [true] if queue [q] is empty,
 otherwise returns [false]. *)
 val isFull: 'a t -> bool
 (* [isFull q] returns [true] if queue [q] is full,
 otherwise returns [false]. *)
end;;


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
      q.f <- ((q.f + 1) mod (Array.length q.a));
  ;;

  let first q =
    if(isEmpty q) then raise (Empty "") else
    match q.a.(q.f) with
      | None -> raise (Empty "")
      | Some a -> a
    ;;
  ;;

end;;

let q = QueueCyclic.empty 4;;
QueueCyclic.enqueue(3, q);;
QueueCyclic.enqueue(4, q);;

print_int (QueueCyclic.first q);;
QueueCyclic.dequeue q;;
print_int (QueueCyclic.first q);;
