let list1 = [1;2;3;4;5;6];;
let list2 = [3;4;5;5;6];;
let list3 = ["a";"a";"a"];;
let list4 = ["c";"c";"c"];;
let list5 = ["A";"B";"C";"D";"E"];;

let reverse l =
  let rec inside l nl =
    match l with
      | [] -> nl
      | h::t -> inside t (h::nl)
  in
    inside l []
;;

let rec print_list = function
  | [] -> ()
  | h::t -> print_int h; print_string " "; print_list t;
;;


let rec print_list_s = function
  | [] -> ()
  | h::t -> print_string h; print_string " "; print_list_s t;
;;

let split l =
  let rec inside l o e =
    match l with
      | h::t -> if h mod 2 = 0 then inside t (h :: o) e else inside t o (h :: e)
      | [] -> (reverse o, reverse e)
  in
    inside l [] []
;;

let conn l1 l2 =
  let rec inside l1 l2 n nl =
    match (l1, l2) with
      | (h1::t1, h2::t2) -> if n mod 2 = 0 then inside t1 l2 (n + 1) (h1 :: nl) else inside l1 t2 (n + 1) (h2 :: nl)
      | ([], []) -> reverse nl
      | (h1::t1, []) -> inside t1 l2 (n + 1) (h1 :: nl)
      | ([], h2::t2) -> inside l1 t2 (n + 1) (h2 :: nl)
  in
    inside l1 l2 0 []
;;
print_string "\n";;
print_list list1;;
print_string "\n";;
let (a, b) = split list1;;
print_list a;;
print_string "\n";;
print_list b;;
print_string "\n";;
print_string "\n";;
print_list list2;;
print_string "\n";;
let (c, d) = split list2;;
print_list c;;
print_string "\n";;
print_list d;;
print_string "\n";;
print_string "\n";;
print_list_s list3;;
print_string "\n";;
print_list_s list4;;
print_string "\n";;
print_list_s list5;;
print_string "\n";;
print_string "\n";;

print_string "\n";;
print_list_s (conn list3 list4);;
print_string "\n";;
print_list_s (conn list3 list5);;
print_string "\n";;
