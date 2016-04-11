extract :: Maybe [a]->[a]
extract (Just list) = list
extract (Nothing) = []

myfunction :: a->Maybe [a]->(a->Bool)->Maybe [a]
myfunction value list function = do
  x<- list
  if (function value)
    then
      Just (x ++ [value])
    else
      Nothing

myappend [] l2 = l2
myappend l1 l2 = (head l1) : (myappend (tail l1) l2)

checklist :: [a]->(a->Bool)->Maybe [a]
checklist [] function = Just []
checklist list function = do
  x <- (myfunction (head list) (Just []) function)
  y <- (checklist (tail list) function)
  Just (x ++ y)

checkappend :: Maybe [a]->Maybe [a]->(a->Bool)->Maybe [a]
checkappend (Just []) list2 function = list2
checkappend list1 list2 function = do
  a <- list1
  x <- (myfunction (head a) (Just[]) function)
  y <- (checkappend (Just (tail a)) list2 function)
  z <- list2
  Just (x ++ y)
