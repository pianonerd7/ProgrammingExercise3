extract :: Maybe [a]->[a]
extract (Just list) = list
--extract (Nothing) = Nothing

myfunction :: a->Maybe [a]->(a->Bool)->Maybe [a]
myfunction value list function = do
	if (function value)
		then 
			Just ((extract list) ++ [value])
		else 
			Nothing

checklist :: [a]->(a->Bool)->Maybe [a]
checklist [] function = Just []
checklist list function = Just (extract (myfunction (head list) (Just []) function) ++ extract (checklist (tail list) function))
--checklist list function = Just (extract (myfunction (head list) (Just []) function) ++ extract (myfunction (head list) (Just[]) function))


