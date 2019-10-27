let rec print_list = function
  | [] -> ()
  | h::t -> print_int h; print_string " "; print_list t;
;;

type 'a bt =
  | Empty
  | Node of 'a * 'a bt * 'a bt
;;

type 'a graph =
  | Graph of ('a -> 'a list)
;;

let rec f a = f a;;

let breadthBT tt =
  let rec inside tl =
    match tl with
      | [] -> []
      | [Empty] -> []
      | Empty::t -> inside t
      | Node(v, left, right)::t -> v::(inside (t @ (left::right::[])))
  in
    inside [tt]
;;


let lenIn tt =
  let rec inside tt a =
    match tt with
      | Empty -> 0
      | Node(v, left, right) -> a + (inside left (a + 1)) + (inside right (a + 1))
  in
    inside tt 0


let lenEx tt =
  let rec inside tt a =
    match tt with
      | Empty -> a
      | Node(v, left, right) -> (inside left (a + 1)) + (inside right (a + 1))
  in
    inside tt 0

let depthSearch (Graph fn) st =
  let rec inside vis que =
    match que with
      | [] -> []
      | h::t -> if List.mem h vis then inside vis t else h::(inside(h::vis) (fn h @ t))
  in
    inside [] [st]
;;

let tt = Node(1,
 Node(2,
 Node(4,
 Empty,
Empty
 ),
 Empty
 ),
 Node(3,
 Node(5,
 Empty,
Node(6,
 Empty,
Empty
 )
 ),
 Empty
 )
 );;

print_list (breadthBT tt);;
print_string "\n";;
print_int (lenEx tt);;
print_string "\n";;
print_int (lenIn tt);;
