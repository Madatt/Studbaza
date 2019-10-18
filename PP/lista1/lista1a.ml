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

let rec flatten ll =
    if ll = [] then [] else (List.hd ll) @ (flatten (List.tl ll));
;;

let rec count (e, l) =
  if(l=[]) then 0 else
    if((List.hd l)=e) then (1 + (count (e, (List.tl l)))) else (0 + (count (e, (List.tl l))));
;;


let rec replicate (o, n) =
    if(n>0) then (o::replicate (o, n-1)) else ([]);
;;

let rec sqrList ll =
  if ll = [] then [] else ((List.hd ll) * (List.hd ll)) :: (sqrList (List.tl ll));
;;

let rec palindrome l =
  (List.rev l) = l;
;;

let rec listLength l =
  if l = [] then 0 else 1 + (listLength (List.tl l));
;;

print_string "\n";;

print_list (flatten list);;

print_string "\n";;

print_list_s (replicate ("test", 8));;

print_string "\n";;

print_list (sqrList (flatten list));;

print_string "\n";;

Printf.printf "%b" (palindrome list2);;

print_string "\n";;

print_int (listLength list2);;

print_string "\n";;

print_int (count (5, list2));;
