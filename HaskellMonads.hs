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
--checklist list function = Just (extract (myfunction (head list) (Just []) function) ++ extract (checklist (tail list) function))

checklist list function = do
  x <- (myfunction (head list) (Just []) function)
  y <- (checklist (tail list) function)
  Just (x ++ y)