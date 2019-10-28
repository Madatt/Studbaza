let duplicate l1 l2 =
  let rec inside l1 l2 acc n =
    if n = 0 then
      match (l1, l2) with
        | ([], l) -> acc
        | (h1::t1, h2::t2) -> inside t1 t2 h1
