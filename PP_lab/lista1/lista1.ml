let list1 = [3.4; 5.4; 1.0; 2.0];;
let list2 = [];;
let list3 = [3.0; 5.0; 7.0];;

let rec sum = function
  | [] -> 0.0
  | h::t -> h +. sum t
;;

print_string "\n";;
print_float (sum list1);;
print_string "\n";;
print_float (sum list2);;
print_string "\n";;
print_float (sum list3);;

let sumT (a, b, c, d) =
  a +. b +. c +. d
;;

print_string "\n";;

print_string "\n";;
print_float (sumT  (1.0, 2.0, 3.0, 4.0));;
print_string "\n";;
print_float (sumT  (1.0, 2.0, 0.0, -5.0));;
print_string "\n";;
print_float (sumT  (11.0, 22.5, 3.0, 4.0));;

let rec conn l s = match l with
  | [] -> ""
  | [h] -> h
  | h::t -> h ^ s ^ (conn t s)
;;

let str1 = ["To"; "Jest"; "Test"];;
let str2 = ["To"; "Jest"; "Drugi"; "Test"];;
let str3 = ["To";];;
let str4 = [];;

print_string "\n";;


print_string "\n";;
print_string (conn str1 "-");;
print_string "\n";;
print_string (conn str2 "-");;
print_string "\n";;
print_string (conn str3 "-");;
print_string "\n";;
print_string (conn str4 "-");;
