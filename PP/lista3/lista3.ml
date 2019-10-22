
let rec print_list = function
  | [] -> ()
  | h::t -> print_int h; print_string " "; print_list t;
;;


let rec print_list_t = function
  | [] -> ()
  | (a, b)::t -> print_string "(";print_int a; print_string ", ";print_int b; print_string ") "; print_list_t t;
;;


let curry f x y z = f(x, y, z);;
(*
  * ('a * 'b * 'c -> 'd) -> 'a -> 'b -> 'c -> 'd
*)

let uncurry f (x, y, z) = f x y z;;
(*
  * ('a -> 'b -> 'c -> 'd) -> 'a * 'b * 'c -> 'd
*)

let rec sumProd l =
  List.fold_left (fun (a1, a2) x -> (a1+x, a2*x)) (0, 1) l
;;


let insertionSort orr l =
  let rec ins n e =
    match n with
      | [] -> [e]
      | h::t -> if orr e h then e::n else h::ins t e
    in
      List.fold_left (fun acc ee -> ins acc ee) [] l
;;


let rec mergeSort orr l =
    let len = List.length l / 2 in
    if len = 0 then l else
      let rec merge ll rr =
        match (ll, rr) with
          | (h1::t1, h2::t2) -> if orr h1 h2 then h1::merge t1 rr else h2::merge ll t2
          | (a, []) -> a
          | ([], a) -> a
      and split l r a =
          if a = 0 then (List.rev l,r) else split (List.hd r :: l) (List.tl r) (a-1)
      in
        let (ll, rr) = split [] l len in merge (mergeSort orr ll) (mergeSort orr rr)

;;


let test = [(2, 199); (1, 2); (1, 123); (3, 25); (2, 99); (3, 0); (4,8886); (1, 322);];;


let testOrder f s =
  fst f <= fst s
;;

 print_list_t (mergeSort testOrder test);;
