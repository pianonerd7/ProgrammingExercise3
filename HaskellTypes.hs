data Nestedlist a = Element a | 
										SubList [Nestedlist a] deriving (Show, Eq)

--flatten (SubList []) = []
--flatten (SubList (x:xs)) = flatten x ++ flatten(SubList xs)
--flatten l = (head l) : flatten (SubList (tail l))
--flatten (SubList l) = flatten (head l) ++ flatten(tail l)

flatten (SubList []) = []
flatten (Element e) = [Element e]
flatten (SubList (x:xs)) = flatten x ++ flatten(SubList xs)
flatten (x:xs) = flatten x ++ flatten (SubList xs)
	

myreverse (SubList []) = []
myreverse (Element e) = [Element e]
--myreverse (SubList (x:xs)) = myreverse (SubList xs) : myreverse x :[]

--random = 

--flatten (SubList[Element 1, Element 3, SubList[Element 4, SubList [SubList [Element 5], SubList[]]], Element 6])
--[Element 1,Element 3,Element 4,Element 5,Element 6]

