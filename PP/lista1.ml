let list = [[5;6];[1;2;3];[8;11;5]];;
let list2 =[5;6;7;8;7;6;5]

let rec print_list = function
  | [] -> ()
  | h::t -> print_int h; print_string " "; print_list t;
;;


let rec print_list_s = function
  | [] -> ()
  | h::t -> print_string h; print_string " "; print_list_s t;
;;

let flatten l =
  let rec inside r = function
    | [] -> r
    | h::t -> List.append h (inside r t)
  in
    inside [] l;
;;

let rec count e = function
  | [] -> 0
  | h::t -> if(h=e) then (1 + (count e t)) else (0 + (count e t));
;;


let replicate o n =
  let rec inside l n =
      if(n>0) then (o::inside l (n-1)) else (l);
  in
    inside [] n;
;;

let sqrList l =
  let rec inside r = function
    | [] -> r
    | h::t -> (h * h)::(inside r t)
  in
    inside [] l;
;;

let rec palindrome l =
  (List.rev l) = l;
;;

let rec listLength = function
  | [] -> 0
  | h::t -> (1 + listLength t);
;;

print_string "\n";;

print_list (flatten list);;

print_string "\n";;

print_list_s (replicate "test" 8);;

print_string "\n";;

print_list (sqrList (flatten list));;

print_string "\n";;

Printf.printf "%b" (palindrome list2);;

print_string "\n";;

print_int (listLength list2);;

print_string "\n";;

print_int (count 5 list2);;
