extract :: Maybe [a]->[a]
extract (Just list) = list
--extract (Nothing) = []

myfunction :: a->Maybe [a]->(a->Bool)->Maybe [a]
myfunction value list function = do
  if (function value)
    then
      Just ((extract list) ++ [value])
    else
      Nothing

checklist :: Eq a=>[a]->(a->Bool)->Maybe [a]
checklist [] function = Just []
--checklist list function = Just (extract (myfunction (head list) (Just []) function) ++ extract (checklist (tail list) function))
--checklist list function = Just (extract (myfunction (head list) (Just []) function) ++ extract (myfunction (head list) (Just[]) function))

checklist list function = 
  if (myfunction (head list) (Just []) function) == Nothing
    then
      Nothing
    else
      Just (extract (myfunction (head list) (Just []) function) ++ extract (checklist (tail list) function))

mychecklist :: Eq a=>[a]->(a->Bool)->(v->v)->Maybe [a]
mychecklist list function return =
  if (myfunction (head list) (Just []) function) == Nothing
    then 
      return Nothing
    else
      checklist (tail list) function (\v-> return (Just (extract (myfunction (head list) (Just []) function)) ++ (extract v)))