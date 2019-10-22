let reverse l =
  let rec inside l nl =
    match l with
      | [] -> nl
      | h::t -> inside t (h::nl)
  in
    inside l []
;;


let rec print_list_s = function
  | [] -> ()
  | h::t -> print_string h; print_string " "; print_list_s t;
;;


let rec fib = function
  | 0 -> 0
  | 1 -> 1
  | n -> (fib[@tailcall])(n-2) + (fib[@tailcall])(n-1);
;;

let fib_t n =
  let rec ins n a b =
    match n with
      | 0 -> a
      | x -> (ins[@tailcall]) (n-1) b (a+b)
  in
    ins n 0 1
;;

let abs a =
  if a < 0.0 then -1.0*.a else a
;;

let root3 a e =
  let rec ins a e aa i =
    if abs (aa*.aa*.aa -. a) <= e *. (abs a) then
      aa
    else if i = 0 then
      if a > 1.0 then (ins [@tailcall]) a e (a/.3.0) 1 else (ins [@tailcall]) a e a 1
    else
      (ins [@tailcall]) a e (aa +. (a/.(aa*.aa) -. aa)/.3.0) (i + 1)
  in
    ins a e 0.0 0
;;

let rec initSegment (f, s) =
  match (f, s) with
    | ([], s) -> true
    | (h1::t1, h2::t2) -> if h1=h2 then initSegment (t1, t2) else false
    | (h::t, []) -> false
;;

let rec replaceNth (l, n, a) =
  match l with
    | h::t -> if n = 0 then a::t else h::replaceNth(t, n - 1, a)
    | [] -> []
;;


print_string "\n";;
print_int (fib 10);;
print_string "\n";;
print_int (fib_t 10);;
print_string "\n";;
print_float (root3 20.0 10e-15);;
print_string "\n";;
Printf.printf "%b" (initSegment([1], [1;2;3;4]));;
print_string "\n";;
print_list_s (replaceNth(["a";"e";"d";"b"], 2, "c"));;
print_string "\n";;


let [_; _; x1; _; _] = [-2; -1; 0; 1; 2];;
let [(_, _); (x, _)] = [(1, 2); (0, 1)];;
