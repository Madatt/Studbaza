
let rec print_list_s = function
  | [] -> ()
  | h::t -> print_string h; print_string " "; print_list_s t;
;;



let curry f x y z = f(x, y, z);;
(*
  * ('a * 'b * 'c -> 'd) -> 'a -> 'b -> 'c -> 'd
*)

let uncurry f (x, y, z) = f x y z;;
(*
  * ('a -> 'b -> 'c -> 'd) -> 'a * 'b * 'c -> 'd
*)
