
type 'a llist =
  | LNil
  | LCons of 'a * 'a llist Lazy.t
;;

let rec print_list = function
  | [] -> ()
  | h::t -> print_int h; print_string " "; print_list t;
;;

let ln = function () -> print_string "\n"
;;


let rec duplicate l1 l2 =
  match (l1, l2) with
    | ([], l) -> []
    | (l, []) -> []
    | (h1::t1, h2::t2) -> if h2 <= 0 then duplicate (t1) (t2) else h1::duplicate (h1::t1) ((h2-1)::t2)
;;


let rec conn l1 l2 =
  match (l1, l2) with
    | (h1::t1, _) -> h1::conn l2 t1
    | ([], []) -> []
    | ([], h2::t2) -> h2::conn [] t2
;;

let rec lconn l1 l2 =
  match (l1, l2) with
    | (LCons(v, lazy f), l) -> LCons(v, lazy(lconn l f))
    | (LNil, LNil) -> LNil
    | (LNil, LCons(v, lazy f)) -> LCons(v, lazy(lconn LNil f))
;;

let rec ltake = function
  | (0, _) -> []
  | (_, LNil) -> []
  | (n, LCons(x, lazy f)) -> x::ltake(n-1, f)
;;

let rec lfrom k =
  LCons(k, lazy(lfrom(k+1)))
;;

let rec lonly k =
  LCons(k, lazy(lonly(k)))
;;

let lfib =
  let rec inside a b =
    LCons(a, lazy(inside b (a+b) ))
  in
    inside 0 1
;;

let l1 = [1;2;3;4];;
let l2 = [2;2;3;2];;
let l3 = [2;2];;
let l4 = [1;8];;
let l5 = [6;6;1;0;5];;
let l6 = [6;6;1;0;5;8;11;2];;
let l7 = [1;1;1;1;1];;
let l8 = [2;2;2;2];;

print_list (duplicate l1 l2);;
ln();;
print_list (duplicate l2 l3);;
ln();;
print_list (duplicate l4 l5);;
ln();;
ln();;
print_list (conn l1 l2);;
ln();;
print_list (conn l6 l3);;
ln();;
print_list (conn l7 l8);;
print_list (conn l6 l3);;
ln();;
print_list (ltake (20, (lconn (lonly 10) (lfib))));;
