let rec print_list = function
  | [] -> ()
  | h::t -> print_int h; print_string " "; print_list t;
;;


type 'a llist =
  | LNil
  | LCons of 'a * (unit -> 'a llist)
;;

let rec ltake = function
  | (0, _) -> []
  | (_, LNil) -> []
  | (n, LCons(x, f)) -> x::ltake(n-1, f())
;;

let rec lfrom k =
  LCons(k, function () -> lfrom(k+1))
;;

let lrepeat k ll =
  let (v, f) = ll
  in LCons(
;;
