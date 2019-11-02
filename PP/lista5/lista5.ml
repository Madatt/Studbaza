type 'a lBT =
  | LEmpty
  | LNode of 'a * (unit ->'a lBT) * (unit -> 'a lBT)
;;

type 'a llist =
  | LNil
  | LCons of 'a * 'a llist Lazy.t
;;



let rec print_list = function
  | [] -> ()
  | h::t -> print_int h; print_string " "; print_list t;
;;

let rec ltake = function
  | (0, _) -> []
  | (_, LNil) -> []
  | (n, LCons(x, lazy f)) -> x::ltake(n-1, f)
;;

let rec lfrom k =
  LCons(k, lazy(lfrom(k+1)))
;;

let lfib =
  let rec inside a b =
    LCons(a, lazy(inside b (a+b) ))
  in
    inside 0 1
;;

let lrepeat k l =
  let rec inside (n, ll) =
    match (n, ll) with
      | (_, LNil) -> LNil
      | (0, LCons(_, lazy f)) -> inside(k, f)
      | (_, LCons(x, _)) -> LCons(x, lazy(inside(n-1, ll)))
  in
    inside (k, l)
;;

let lBreadth l =
  let rec inside tl =
    match tl with
      | [] -> LNil
      | [LEmpty] -> LNil
      | LEmpty::t -> inside t
      | LNode(v, f1, f2)::t -> LCons(v, lazy(inside (t @ (f1()::f2()::[]))))
  in
    inside [l]
;;

let rec lTree k =
  LNode(k, (function () -> lTree(2*k)), (function () -> lTree(2*k + 1)))
;;

let lst = ltake(31, lrepeat 4 (lfrom 10));;
let lst2 = ltake(10, lfib);;

print_list lst2;;
print_string "\n";;
print_list (ltake (10, (lBreadth (lTree 1))));;
