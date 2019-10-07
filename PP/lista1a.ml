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
  let rec inside r ll =
    if ll = [] then r else List.append (List.hd ll) (inside r (List.tl ll));
  in
    inside [] l;
;;

let rec count e l =
  if(l=[]) then 0 else
    if((List.hd l)=e) then (1 + (count e (List.tl l))) else (0 + (count e (List.tl l)));
;;


let replicate o n =
  let rec inside l n =
      if(n>0) then (o::inside l (n-1)) else (l);
  in
    inside [] n;
;;

let sqrList l =
  let rec inside r ll =
    if ll = [] then r else ((List.hd ll) * (List.hd ll)) :: (inside r (List.tl ll));
  in
    inside [] l;
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

print_list_s (replicate "test" 8);;

print_string "\n";;

print_list (sqrList (flatten list));;

print_string "\n";;

Printf.printf "%b" (palindrome list2);;

print_string "\n";;

print_int (listLength list2);;

print_string "\n";;

print_int (count 5 list2);;
